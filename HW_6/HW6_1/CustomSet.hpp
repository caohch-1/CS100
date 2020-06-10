#ifndef CUSTOMSET_INCLUDED
#define CUSTOMSET_INCLUDED
#include<vector>
#include<iostream>
#include<utility>
template < typename T >
class CustomSet
{
private:
    std::vector< T > m_data;
    int m_size;
    
public:
//constructors and destructors
    CustomSet();

    CustomSet( const CustomSet& other );

    CustomSet( T arr[] , int size );

    ~CustomSet(){};

//member fuctions
    int size() const{return m_size;};
    void change_size( int new_size ){m_size=new_size;};

    std::vector<T> data() const{return m_data;};

    bool add( const T& item );

    T* find( const T& item );

    bool erase( const T& item );

    CustomSet intersection( const CustomSet& other );

    void sortSet();

    void printSet();

//operators
    CustomSet operator+( const T& item ){
        CustomSet<T> result(*this);
        result.add(item);
        return result;
    };

    CustomSet& operator+=( const T& item ){
        add(item);
        return *this;
    };

    CustomSet operator+( const CustomSet& that ){
        CustomSet<T> result(*this);
        for( int i=0; i<that.size(); i++){
            result.add(that.data()[i]);
        }
        return result;
    };

    CustomSet operator+=( const CustomSet& that ){
        for(int i=0;i<that.size();i++){add(that.data()[i]);}
        return *this;
    }


    CustomSet operator-( const T& item ){
        CustomSet<T> result(*this);
        result.erase(item);
        return result;
    };

    CustomSet operator-( const CustomSet& that ){
        CustomSet<T> result(*this);
        for( int i=0; i<that.size(); i++){
            result.erase(that.data()[i]);
        }
        return result;
    };

    CustomSet& operator-=( const T& item ){
        erase(item);
        return *this;
    };

    CustomSet& operator-=( const CustomSet& that ){
        *this=*this-intersection(that);
        return *this;
    };

    CustomSet<std::pair<T,T>> operator* ( const CustomSet& that ){
        CustomSet<std::pair<T,T>> result_set;
        //result_set.change_size(size()*that.size());
        for(int i=0; i< size(); i++){
            for(int j=0; j<that.size(); j++){
                std::pair<T,T> result(data()[i],that.data()[j]);
                result_set+=result;
            }
        }
        return result_set;
    };
};


//implemention
template <class T>
CustomSet<T>::CustomSet()
{
    m_size=0;
}

template <class T>
CustomSet<T>::CustomSet( const CustomSet& other )
{
    m_size=other.size();
    m_data.assign(other.m_data.begin(),other.m_data.end());
}

template <class T>
CustomSet<T>::CustomSet( T arr[] , int size )
{
    for(int i=0; i<size; i++){
        m_data.push_back(arr[i]);
    }
    m_size=size;

    for(int i=0;i<m_size;i++){
        for(int j=0;j<m_size;j++){
            if(j==i){continue;}
            if(m_data[i]==m_data[j]){
            m_data.erase(m_data.begin()+i);
            m_size--;
            }
        }
    }
}

template <class T>
bool CustomSet<T>::add( const T& item )
{
    typename std::vector<T>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if(*it == item){
            return false;
        }
    }
    m_data.push_back(item);
    m_size++;
    return true;
}

template <class T>
T* CustomSet<T>::find( const T& item )
{
    for( int i=0; i<m_size; i++){
        if(m_data[i] == item){
            return &m_data[i];
        }
    }
    return nullptr;
}

template <class T>
bool CustomSet<T>::erase( const T& item )
{
    typename std::vector<T>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if(*it == item){
            it = m_data.erase(it);
            m_size--;
            return true;
        }
    }
    return false; 
}

template <class T>
CustomSet<T> CustomSet<T>::intersection( const CustomSet& other )
{
    CustomSet<T> set;
    int size=0;
    typename std::vector<T>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        for(int i=0; i<other.size(); i++){
            if(*it == other.data()[i]){
                set.add(*it);
                size++;
            }
        }
    }
    set.change_size(size);
    return set;
}

template <class T>
void CustomSet<T>::sortSet()
{
    sort(m_data.begin(),m_data.end());
}

template <class T>
void CustomSet<T>::printSet()
{
    std::cout<<"{";
    for(int i=0; i<m_data.size(); i++){
        std::cout<<m_data[i];
        if(i != m_data.size()-1){std::cout<<", ";}
        else{std::cout<<"}"<<std::endl;}
    }
}
#endif