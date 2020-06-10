#include<stdio.h>
#include<stdlib.h>
int swap_1(int *x,int *y);
float swap_2(float *x,float *y);

int main(){
    int num=0;
    int * ptr_1;
    float * ptr_2;
    int orginal_length=5,new_length=5;
    ptr_2=(float *) malloc(orginal_length * sizeof(float));
    ptr_1=(int *) malloc(orginal_length * sizeof(int));

    printf("Please type scores to be calculated:\n");
  
    for(int i=0 ; ; i++, num++ ,orginal_length=new_length){

        scanf("%d %f",&ptr_1[i],&ptr_2[i]);

        if(ptr_1[i]==-1 && ptr_2[i]==-1){
            break;
        }

        if(i==new_length-1){
			int temp_1[orginal_length];
			float temp_2[orginal_length];
			for(int t=0;t<orginal_length;t++){
				temp_2[t]=ptr_2[t];
				temp_1[t]=ptr_1[t];
			}
			
            new_length=2*orginal_length;
            printf("(resize) from %d to %d\n",orginal_length,new_length);
            printf("(resize) from %d to %d\n",orginal_length,new_length);
            ptr_2=(float *) malloc(new_length * sizeof(float));
            ptr_1=(int *) malloc(new_length * sizeof(int));
			
			for(int t=0;t<orginal_length;t++){
				ptr_1[t]=temp_1[t];
				ptr_2[t]=temp_2[t];
			}
        }

    }

    printf("---Result---\n");

    for(int i=0; i<num ;i++){
        for(int j=1; j<num ;j++){
            if(ptr_2[j-1]>ptr_2[j]){
                swap_2(&ptr_2[j-1],&ptr_2[j]);
                swap_1(&ptr_1[j-1],&ptr_1[j]);
            }
            if((ptr_2[j-1]==ptr_2[j]) && (ptr_1[j-1]>ptr_1[j])){
                swap_2(&ptr_2[j-1],&ptr_2[j]);
                swap_1(&ptr_1[j-1],&ptr_1[j]);
            }
        }
    }

    for(int i=0;i<num;i++){
        printf("%d %.1f\n",ptr_1[i],ptr_2[i]);
    }
    free(ptr_1);
    free(ptr_2);

    return 0;
}

float swap_2(float *x,float *y){
    float temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int swap_1(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    }