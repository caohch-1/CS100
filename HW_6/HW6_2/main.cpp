#include<iostream>
#include"lotterystation.h"
using namespace std;
int main(){
    LotteryStation sample;
    sample.newRound();

    int prizeArr[7]={22,14,3,4,5,6,7};
    CustomSet<int> prizeSet(prizeArr,7);
    sample.setPrizeNumbers(prizeSet,7);

    int buyArr[8]={1,2,3,4,5,6,7,8};
    CustomSet<int> buySet(buyArr,8);
    LotteryTicket* buyTicket = sample.buy(buySet,7);
    //cout<<buyTicket->getRound()<<endl;
    sample.claimPrize(buyTicket);
    //cout<<buyTicket->getRound()<<endl;
}