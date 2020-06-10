#include <iostream>
#include <vector>
#include <math.h>

const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser() {};
    virtual ~DataAnalyser() {};
    /** 
     * virtual function "calculate"
     * @param data: the data array need to be calculated
     * @param size: the length of the data
     * @return: the calculated result
     */
    virtual float calculate(float* data, size_t size)
    {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};


// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser
{
    // Your code here.
    public:
        MaximumAnalyser(){};
        virtual ~MaximumAnalyser(){};
        virtual float calculate(float* data, size_t size);
};

float MaximumAnalyser::calculate(float* data, size_t size){
    float temp=data[0];
    for(int i=0;i<size;i++){
        if(data[i]>temp){
            temp=data[i];
        }
    }
    return temp;
}

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser
{
    // Your code here.
    public:
        MinimumAnalyser(){};
        virtual ~MinimumAnalyser(){};
        virtual float calculate(float* data, size_t size);
};

float MinimumAnalyser::calculate(float* data, size_t size){
    float temp=data[0];
    for(int i=0;i<size;i++){
        if(data[i]<temp){
            temp=data[i];
        }
    }
    return temp;
}

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
    // Your code here.
    public:
        AverageAnalyser(){};
        virtual ~AverageAnalyser(){};
        virtual float calculate(float* data, size_t size);
};

float AverageAnalyser::calculate(float* data, size_t size){
    float sum=0;
    for(int i=0;i<size;i++){
        sum=sum+data[i];
    }
    return sum/size;
}

// MedianAnalyser
class MedianAnalyser : public DataAnalyser
{
    // Your code here.
    public:
        MedianAnalyser(){};
        virtual ~MedianAnalyser(){};
        virtual float calculate(float* data, size_t size);
};

float MedianAnalyser::calculate(float* data, size_t size){
    for(int i=0; i<size ;i++){
        for(int j=1; j<size ;j++){
            if(data[j-1]>data[j]){
                float temp;
                temp=data[j-1];
                data[j-1]=data[j];
                data[j]=temp;
            }
        }
    }

    if(size%2==0){
        return (data[size/2]+data[size/2-1])/2;
    }
    else{
        return data[(size-1)/2];
    }   
}

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser
{
    // Your code here
    public:
        StdDevAnalyser(){};
        virtual ~StdDevAnalyser(){};
        virtual float calculate(float* data, size_t size);
};

float StdDevAnalyser::calculate(float* data, size_t size){
    float sum_1=0;
    for(int i=0;i<size;i++){
        sum_1=sum_1+data[i];
    }
    float arg=sum_1/size;

    float sum_2=0;
    for(int i=0;i<size;i++){
        sum_2=sum_2+(data[i]-arg)*(data[i]-arg);
    }
    return sqrt(sum_2/size);
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    float data[]={1.4,3.44,5,7  };
    size_t size=4;
    /*MaximumAnalyser max;
    float a=max.calculate(data,size);
    std::cout<<a;*/

    /*MinimumAnalyser min;
    float a=min.calculate(data,size);
    std::cout<<a;*/

    /*AverageAnalyser arg;
    float a=arg.calculate(data,size);
    std::cout<<a;*/

    MedianAnalyser med;
    float a=med.calculate(data,size);
    std::cout<<a;

    /*StdDevAnalyser std_;
    float a=std_.calculate(data,size);
    std::cout<<a;*/

    /* Your can write your own main for testing */
    return 0;
}