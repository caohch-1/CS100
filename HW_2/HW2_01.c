#include<stdio.h>
#include<stdlib.h>

int main(){
    int orginal_length=5,new_length=5,num=0;
    float sum=0,average;
    float * ptd;
    ptd=(float *) malloc(orginal_length * sizeof(float));

    printf("Please type scores to be calculated:\n");

    for(int i=0 ; ; i++,num++,orginal_length=new_length){

        scanf("%f",&ptd[i]);

        if(ptd[i]==-1){
            break;
        }
        sum=sum+ptd[i];

        if(i==new_length-1){
            new_length=2*orginal_length;
            printf("(resize) from %d to %d\n",orginal_length,new_length);
            ptd=(float *) malloc(new_length * sizeof(float));
        }

    }
    average=sum/num;
    printf("Average score: %.2f",average);

    free(ptd);

    return 0;
}