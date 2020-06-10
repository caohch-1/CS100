#include"CustomSet.hpp"
#include<algorithm>
using namespace std;

int main(){
    //create
    int a[7]={2,3,5,1,7,6,3};
    int b[2]={3,12};
    CustomSet<int> sample1(a,7);cout<<sample1.size()<<endl;
    CustomSet<int> sample2(b,2);cout<<sample2.size()<<endl;
    //CustomSet<int> sample3(sample1);cout<<sample3.size()<<endl;
    CustomSet<pair<int,int>> sample3;
    sample3=sample1*sample2;
    
    //judge constructors
    sample1.printSet();sample2.printSet();sample3.printSet();
    sample1.sortSet();sample2.sortSet();sample3.sortSet();
    sample1.printSet();sample2.printSet();sample3.printSet();
    
    //judge +,-
    (sample1+sample2).printSet();cout<<(sample1+sample2).size()<<endl;
    (sample1-sample2).printSet();cout<<(sample1-sample2).size()<<endl;
    (sample1-7).printSet();cout<<(sample1-7).size()<<endl;
    (sample1+99).printSet();cout<<(sample1+99).size()<<endl;
    return 0;
    
    //judge+=
    sample1+=sample2;sample1.printSet();cout<<sample1.size()<<endl;
    sample1+=99;sample1.printSet();cout<<sample1.size()<<endl;
    return 0;

    //judge-=
    sample1-=sample2;sample1.printSet();cout<<sample1.size()<<endl;
    sample1-=7;sample1.printSet();cout<<sample1.size()<<endl;
    return 0;

    //judge find()
    cout<<*(sample1.find(7))<<endl;return 0;
    
    //judge *
    for(int i=0;i<12;i++){
        cout<<sample3.data()[i].first<<"->"<<sample3.data()[i].second<<endl;
    }
    cout<<sample3.size();
    return 0;
}