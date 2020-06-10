#ifndef TICKET_INCLUDED
#define TICKET_INCLUDED
#include"customset.h"

class LotteryTicket
{
public:
//constructors and destructors
    LotteryTicket(){};
    LotteryTicket( const CustomSet<int>& numbers, int round );
    virtual ~LotteryTicket(){};

//member functions
    virtual int getRound() const =0;
    virtual int getCost() const =0;

    long long calculateC(int m,int n) const {
        if(m<=0 || n<=0){return 0;}
        long long result_1=1;
        for(int i=1;i<=m;i++){
            result_1=result_1*i;
        }
        long long result_2=1;
        for(int i=1;i<=n;i++){
            result_2=result_2*i;
        }
        long long result_3=1;
        for(int i=1;i<=n-m;i++){
            result_3=result_3*i;
        }
        return result_2/(result_3*result_1);
    };

    virtual int getTicketType()=0;
    void setCost( const int& cost ){m_cost=cost;};
    virtual void setRound(int number)=0;
    virtual int claimPrize( const CustomSet<int>& prizeNumbers, int round )=0;

private:
    CustomSet<int> m_numbers;
    int m_round;
    int m_cost;
};

class Lotto7Ticket : public LotteryTicket
{
public:
    Lotto7Ticket();
    Lotto7Ticket( const CustomSet<int>& numbers, int round );
    virtual ~Lotto7Ticket(){};

    virtual int getRound() const{return m_round;};
    virtual int getCost() const{return m_cost;};
    CustomSet<int>* getNumber(){return &m_numbers;};
    virtual int getTicketType(){return 7;};
    virtual void setRound(int number){m_round=number;};
    void setCost( const int& cost ){m_cost=cost;}

    virtual int claimPrize( const CustomSet<int>& prizeNumbers, int round );
private:
    CustomSet<int> m_numbers;
    int m_round;
    int m_cost;
};

class Lotto6Ticket : public LotteryTicket
{
public:
    Lotto6Ticket();
    Lotto6Ticket( const CustomSet<int>& numbers, int round );
    virtual ~Lotto6Ticket(){};

    virtual int getRound() const{return m_round;};
    virtual int getCost() const{return m_cost;};
    CustomSet<int>* getNumber(){return &m_numbers;};
    virtual int getTicketType(){return 6;};
    virtual void setRound(int number){m_round=number;};
    void setCost( const int& cost ){m_cost=cost;}

    virtual int claimPrize( const CustomSet<int>& prizeNumbers, int round );
private:
    CustomSet<int> m_numbers;
    int m_round;
    int m_cost;
};
#endif