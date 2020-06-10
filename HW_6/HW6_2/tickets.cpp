#include<iostream>
#include"tickets.h"
using namespace std;

Lotto7Ticket::Lotto7Ticket()
{
    m_round=1;
    m_cost=2;
}

Lotto7Ticket::Lotto7Ticket( const CustomSet<int>& numbers, int round )
{
    m_round=round;
    m_numbers=numbers;
    if(m_numbers.size()<=7){
        m_cost=2;
    }
    else{
        m_cost=2*calculateC(7,m_numbers.size());
    }
}

int Lotto7Ticket::claimPrize( const CustomSet<int>& prizeNumbers, int round )
{
    if(m_round!=round){
        return 0;
    }

    CustomSet<int> common(m_numbers.intersection(prizeNumbers));
    if(common.size()<=3){return 0;}
    int prize_1=0;
    int prize_2=0;
    int prize_3=0;
    int prize_4=0;

    if(common.size()>=7){prize_1=1;}
    if(common.size()>=6){prize_2=calculateC(6,common.size())*calculateC(7-6,m_numbers.size()-common.size());}
    if(common.size()>=5){prize_3=calculateC(5,common.size())*calculateC(7-5,m_numbers.size()-common.size());}
    if(common.size()>=4){prize_4=calculateC(4,common.size())*calculateC(7-4,m_numbers.size()-common.size());}

    return prize_1*2000000+prize_2*4500+prize_3*75+prize_4*5;

}

Lotto6Ticket::Lotto6Ticket()
{
    m_round=1;
    m_cost=2;
}

Lotto6Ticket::Lotto6Ticket( const CustomSet<int>& numbers, int round )
{
    m_round=round;
    m_numbers=numbers;
    if(m_numbers.size()<=6){
        m_cost=2;
    }
    else{
        m_cost=2*calculateC(6,m_numbers.size());
    }
}

int Lotto6Ticket::claimPrize( const CustomSet<int>& prizeNumbers, int round )
{
    if(m_round!=round){
        return 0;
    }

    CustomSet<int> common(m_numbers.intersection(prizeNumbers));
    if(common.size()<=2){return 0;}
    int prize_1=0;
    int prize_2=0;
    int prize_3=0;
    int prize_4=0;

    if(common.size()>=6){prize_1=1;}
    if(common.size()>=5){prize_2=calculateC(5,common.size())*calculateC(6-5,m_numbers.size()-common.size());}
    if(common.size()>=4){prize_3=calculateC(4,common.size())*calculateC(6-4,m_numbers.size()-common.size());}
    if(common.size()>=3){prize_4=calculateC(3,common.size())*calculateC(6-3,m_numbers.size()-common.size());}
    return prize_1*2000000+prize_2*4500+prize_3*75+prize_4*5;
}