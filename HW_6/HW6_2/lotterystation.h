#ifndef STATION_INCLUDED
#define STATION_INCLUDED
#define LOTTO6 6
#define LOTTO7 7
#include"tickets.h"

class LotteryStation
{
public:
    LotteryStation();
    ~LotteryStation();

    LotteryTicket* buy( CustomSet<int> numbers, int tickettype );
    void claimPrize( LotteryTicket* ticket );
    void newRound();
    bool setPrizeNumbers( CustomSet<int> numbers, int tickettype );

private:
    int m_round;
    CustomSet<int> prizeTicket_6;
    CustomSet<int> prizeTicket_7;
};
#endif
