#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment);
    LookupTable(){};
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
};
LookupTable::~LookupTable(){}

class SquareLookupTable : public LookupTable
{
    // Your code here.
    public:
        SquareLookupTable(double start, double end, double increment){
            num=(end-start)/increment+1;
            for(int i=0;i<num;i++){
                m_x.push_back(start+i*increment);
                m_fx.push_back((start+i*increment)*(start+i*increment));
            }
            m_increment=increment;
        };

        virtual~SquareLookupTable(){};

        virtual double getValue(double x){
            int index;
            for(int i=1;i<num;i++){
                if(m_x[i-1]<=x && m_x[i]>=x){
                    index=i;
                }
            }
            double x_low=m_x[index-1];
            double x_high=m_x[index];
            double fx_low=m_fx[index-1];
            double fx_high=m_fx[index];
            double require=((x-x_low)*fx_high+(x_high-x)*fx_low)/m_increment;
            return require;
        };

    private:
        int num;
        float m_increment;
        vector<double> m_x;
        vector<double> m_fx;
};


class SinLookupTable : public LookupTable
{
    // Your code here.
    public:
        SinLookupTable(double start, double end, double increment){
            num=(end-start)/increment+1;
            for(int i=0;i<num;i++){
                m_x.push_back(start+i*increment);
                m_fx.push_back(sin(start+i*increment));
            }
            m_increment=increment;
        };

        virtual~SinLookupTable(){};

        virtual double getValue(double x){
            int index;
            for(int i=1;i<num;i++){
                if(m_x[i-1]<=x && m_x[i]>=x){
                    index=i;
                }
            }
            double x_low=m_x[index-1];
            double x_high=m_x[index];
            double fx_low=m_fx[index-1];
            double fx_high=m_fx[index];
            double require=((x-x_low)*fx_high+(x_high-x)*fx_low)/m_increment;
            return require;
        };

    private:
        int num;
        float m_increment;
        vector<double> m_x;
        vector<double> m_fx;
};

class LogLookupTable : public LookupTable
{
    // Your code here.
    public:
        LogLookupTable(double start, double end, double increment){
            num=(end-start)/increment+1;
            for(int i=0;i<num;i++){
                m_x.push_back(start+i*increment);
                m_fx.push_back(log(start+i*increment));
            }
            m_increment=increment;
        };

        virtual~LogLookupTable(){};

        virtual double getValue(double x){
            int index;
            for(int i=1;i<num;i++){
                if(m_x[i-1]<=x && m_x[i]>=x){
                    index=i;
                }
            }
            double x_low=m_x[index-1];
            double x_high=m_x[index];
            double fx_low=m_fx[index-1];
            double fx_high=m_fx[index];
            double require=((x-x_low)*fx_high+(x_high-x)*fx_low)/m_increment;
            return require;
        };

    private:
        int num;
        float m_increment;
        vector<double> m_x;
        vector<double> m_fx;
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    // Your code here.
    SinLookupTable test(1,9,2);
    double test_=test.getValue(4);
    cout<<test_;
    return 0;
}

