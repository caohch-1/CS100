#include"gechatuser.h"

GechatUser::GechatUser(string username)
{
    m_username=username;
}

bool GechatUser::haveFriend(shared_ptr<GechatUser> user)//something
{
    for(int i=0;i<m_friends.size();i++){
        if(m_friends[i]->userName()==user->userName()){return true;}
    }
    return false;
}

bool GechatUser::addFriend(shared_ptr<GechatUser> user)
{
    if(user==nullptr){return false;}
    for(int i=0;i<m_friends.size();i++){
        if(m_friends[i]->userName()==user->userName()){
            return false;
        }
    }
    m_friends.push_back(user);
    return true;
}

bool GechatUser::singleDelete(shared_ptr<GechatUser> user)
{
    for(int i=0;i<m_friends.size();i++){
        if(m_friends[i]->userName()==user->userName()){
            m_friends.erase(m_friends.begin()+i);
            return true;
        }
    }
    return false;  
}

bool GechatUser::singleDelete(string username)
{
    for(int i=0;i<m_friends.size();i++){
        if(m_friends[i]->userName()==username){
            m_friends.erase(m_friends.begin()+i);
            return true;
        }
    }
    return false;
}

bool GechatUser::doubleDelete(shared_ptr<GechatUser> user)
{
    if(haveFriend(user) && user!=nullptr){
        doubleDelete(user->userName());
        return true;
    }
    return false;
}

bool GechatUser::doubleDelete(string username)
{
        //TODO delete this from that
        for(int i=0;i<m_friends.size();i++){
            if(m_friends[i]->userName()==username){
                m_friends[i]->singleDelete(m_username);
                singleDelete(username);
                return true;
            }
        }     
    return false;
}