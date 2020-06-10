#include<iostream>
#include<cstring>
class DynamicArray
{
private:
    int* data;
    int size;
    int capacity;

public:
    DynamicArray();
    DynamicArray(const DynamicArray & other);
    ~DynamicArray();

    int getSize() const;
    int getCapacity() const;
    int at (int index) const;

    void assign(const DynamicArray & other);
    void push(const int item);
    bool remove(const int index);
};

DynamicArray::DynamicArray()
{
    size=0;
    capacity=5;
    data=new int [5];
};

DynamicArray::DynamicArray(const DynamicArray & other)
{
    data=new int [other.getCapacity()];
    capacity=other.getCapacity();
    if(data != NULL){
        memcpy(data,other.data,sizeof(int)*other.getSize());
        size=other.getSize();
    }
    else{
        size=0;
        capacity=0;
    }
};

DynamicArray::~DynamicArray()
{
    if(data!=NULL){
        delete []data;
    }
};

int DynamicArray::getSize() const
{
    return size;
};

int DynamicArray::getCapacity() const
{
    return capacity;
};

int DynamicArray::at(int index) const
{
    return data[index];
};

void DynamicArray::assign(const DynamicArray & other)
{
    delete []data;
    data=new int [other.getCapacity()];
    memcpy(data,other.data,sizeof(int)*other.getSize());
    size=other.getSize();
    capacity=other.getCapacity();
};

void DynamicArray::push(const int item)
{
    data[size]=item;
    size++;

    if(size==capacity){
    int* temp=new int [2*capacity];
    memcpy(temp,data,sizeof(int)*size);
    delete []data;
    capacity=2*capacity;
    data=new int [capacity];
    memcpy(data,temp,sizeof(int)*size);
    printf("(resize) from %d to %d\n",capacity/2,capacity);
    delete []temp;
    }
};

bool DynamicArray::remove(const int index)
{
    if(index>=0 && index<size){
        int* temp=new int [capacity];
        for(int i=0;i<size-1;i++){
            if(i<index){
                temp[i]=data[i];
            }
            else if(i>=index){
                temp[i]=data[i+1];
            }
        }
        delete []data;
        data=new int [capacity];
        memcpy(data,temp,sizeof(int)*size);
        size--;
        delete []temp;
        return true; 
    }
    else{
        return false;  
    }
    
};