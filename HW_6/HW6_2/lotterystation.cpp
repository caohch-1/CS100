#include<iostream>
#include<random>
#include<time.h>
#include"lotterystation.h"
using namespace std;
int randInt(int min, int max){
    if(max<min){swap(max,min);}
    return rand()%(max-min+1)+min;
}

LotteryStation::LotteryStation()
{
    m_round=0;
}

LotteryStation::~LotteryStation()
{

}

LotteryTicket* LotteryStation::buy( CustomSet<int> numbers, int tickettype )
{
    if(numbers.size()<6 || (tickettype!=6 && tickettype!=7)){
        cout<<"Failed.\n";
        return nullptr;
    }
    if(tickettype==6&&numbers.size()>5){
        for(int i=0;i<numbers.size();i++){
            if(numbers.data()[i]>43 || numbers.data()[i]<1){
                cout<<"Failed.\n";
                return nullptr;
            }
        }
        LotteryTicket* result =new Lotto6Ticket(numbers,m_round);
        cout<<"Bought a Lotto 6 ticket for "<<result->getCost()<<" Yuan at round "<<m_round<<".\n";
        return result;
    }
    else if(tickettype==7&&numbers.size()>6){
        for(int i=0;i<numbers.size();i++){
            if(numbers.data()[i]>30 || numbers.data()[i]<1){
                cout<<"Failed.\n";
                return nullptr;
            }
        }
        LotteryTicket* result =new Lotto7Ticket(numbers,m_round);
        cout<<"Bought a Lotto 7 ticket for "<<result->getCost()<<" Yuan at round "<<m_round<<".\n";
        return result;
    }
    else{
        cout<<"Failed."<<endl;
        return nullptr;
    }
}

void LotteryStation::claimPrize( LotteryTicket* ticket )
{
    if(ticket->getTicketType()==7 && ticket->getRound()==m_round){
        cout<<"This ticket wins "<< ticket->claimPrize(prizeTicket_7,m_round)<<" Yuan."<<endl;
        ticket->setRound(-111);
    }
    else if(ticket->getTicketType()==6 && ticket->getRound()==m_round){
        cout<<"This ticket wins "<< ticket->claimPrize(prizeTicket_6,m_round)<<" Yuan."<<endl;
        ticket->setRound(-111);
    }
    else{
        cout<<"This ticket wins 0 Yuan."<<endl;
        }
}

void LotteryStation::newRound()
{
    m_round++;
    prizeTicket_7.clear();
    prizeTicket_6.clear();
    for(int j=0;j<6;j++){       
        prizeTicket_6.add(randInt(1,43));
    }
    
    for(int j=0;j<7;j++){
        prizeTicket_7.add(randInt(1,30));
    }
}

bool LotteryStation::setPrizeNumbers( CustomSet<int> numbers, int tickettype )
{
    if(tickettype==6){
        prizeTicket_6=numbers;  
        return true;
    }
    if(tickettype==7){
        prizeTicket_7=numbers;
        return true;
    }
}