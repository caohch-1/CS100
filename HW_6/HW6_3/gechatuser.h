#ifndef USER_INCLUDED
#define USER_INCLUDED
#include<iostream>
#include<memory>
#include<string>
#include"customset.h"
using namespace std;
class GechatUser
{
public:
//Constructors and destructors
    GechatUser(){};
    GechatUser(string username);
    ~GechatUser(){};
//accessor
    int numFriends() {return m_friends.size();};
    string userName() const{return m_username;};
    vector<shared_ptr<GechatUser>> frineds() {return m_friends;};

    bool haveFriend(shared_ptr<GechatUser> user);
    void setUsername(string username){m_username=username;};
    bool addFriend(shared_ptr<GechatUser> user);
    bool singleDelete(shared_ptr<GechatUser> user);
    bool singleDelete(string username);
    bool doubleDelete(shared_ptr<GechatUser> user);
    bool doubleDelete(string username);

    friend ostream& operator<<(ostream& out, GechatUser& t){
        out<<t.userName()<<" (friends: "<<t.m_friends.size()<<")";
        return out;
    };
    friend bool operator==(const GechatUser& left,const GechatUser& right){
        if(left.userName()==right.userName()){return true;}
        return false;
    };
    friend bool operator<(const GechatUser& left,const GechatUser& right){
        if(left.userName()<right.userName()){return true;}
        return false;
    };
private:
    vector<shared_ptr<GechatUser>> m_friends;
    string m_username;
};

#endif
