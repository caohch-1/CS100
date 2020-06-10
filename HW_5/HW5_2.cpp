#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReportParser
{
public:
    // Add your own functions and variables here
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
private:
    // Add your own functions and variables here
    int m_numStudents;
    int m_numInfos;
    string **data;
};

ReportParser::ReportParser(int numStudents, int numInfos) 
{
    // Your code here
    m_numStudents=numStudents;
    m_numInfos=numInfos;
    data=new string*[numStudents];
    for(int i=0;i<numStudents;i++){
        data[i]=new string[numInfos];
    }
} 

ReportParser::~ReportParser() 
{
    // Your code here

}

void ReportParser::readReport()
{
    //Your code here
    for(int i=0;i<m_numStudents;i++){
        for(int j=0;j<m_numInfos;j++){
            cin>>data[i][j];
        }
        getchar();
    }
}

void ReportParser::writeStructuredReport(int sortOption)
{
    // Your code here

    //sort
    for(int i=0;i<m_numStudents;i++){
        for(int j=1;j<m_numStudents;j++){
            string temp[m_numInfos];

            if(data[j-1][sortOption]>data[j][sortOption]){

                for(int k=0;k<m_numInfos;k++){
                    temp[k]=data[j-1][k];               
                }
                for(int k=0;k<m_numInfos;k++){
                    data[j-1][k]=data[j][k];
                }
                for(int k=0;k<m_numInfos;k++){
                    data[j][k]=temp[k];
                }
            }
        }
    }
    //length of every col
    int max_of_col[m_numInfos];
    for(int i=0;i<m_numInfos;i++){
        max_of_col[i]=data[0][i].length();
        for(int j=1;j<m_numStudents;j++){
            if(max_of_col[i]<data[j][i].length()){
                max_of_col[i]=data[j][i].length();
            }
        }
    }
    //char of every row
    int sum=0;
    for(int i=0;i<m_numInfos;i++){
        sum=sum+max_of_col[i];
    }

    //display
    int num_=0;
    for(int i=0;i<sum+m_numInfos*2+m_numInfos;i++){   //first row
        if(i==0){
            cout<<'/';
        }
        if(i==sum+m_numInfos*2+m_numInfos-1){
            cout<<'\\'<<endl;
            break;
        }
        cout<<'-';
    }
    for(int j=0;j<m_numStudents*2-1;j++){     
        if(j%2==0){                            //normal row
            for(int k=0;k<m_numInfos;k++){
                cout<<'|'<<' '<<data[j-num_][k]<<' ';
                for(int h=0;h<max_of_col[k]-data[j-num_][k].length();h++){
                    cout<<' ';
                }
            }
            cout<<'|'<<endl;
        }
        else if(j%2==1){                     //------row
            for(int k=0;k<m_numInfos;k++){
                cout<<'|';
                for(int h=0;h<max_of_col[k]+2;h++){
                    cout<<'-';
                }
            }
            cout<<'|'<<endl;
            num_++;
        }
    }       
    for(int i=0;i<sum+m_numInfos*2+m_numInfos;i++){   //last
        if(i==0){
                cout<<'\\';
        }
        if(i==sum+m_numInfos*2+m_numInfos-1){
            cout<<'/'<<endl;
            break;
        }
        cout<<'-';
    }
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////

int main()
{
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(m, n);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}

