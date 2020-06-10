#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int * set_a;
    int * set_b;
    int original_size=5,new_size=5,num_a=0,num_b=0;
    set_a=(int *)malloc(original_size*sizeof(int));
    set_b=(int *)malloc(original_size*sizeof(int));

    printf("Please input the set A:\n");
//setA
    for(int i=0 ; ; i++,num_a++,original_size=new_size){

        scanf("%d",&set_a[i]);

        if(set_a[i]==-1){
            break;
        }

        if(i==new_size-1){
			int temp_a[original_size];
			for(int t=0;t<original_size;t++){
				temp_a[t]=set_a[t];
			}
			
            new_size=2*original_size;
            printf("(resize) from %d to %d\n",original_size,new_size);
            set_a=(int *)malloc(new_size*sizeof(int));
			
			for(int t=0;t<original_size;t++){
				set_a[t]=temp_a[t];
			}
        }
    }

    printf("Please input the set B:\n");
    original_size=5,new_size=5;
//setb
     for(int i=0 ; ; i++,num_b++,original_size=new_size){

        scanf("%d",&set_b[i]);

        if(set_b[i]==-1){
            break;
        }

        if(i==new_size-1){
			int temp_b[original_size];
			for(int t=0;t<original_size;t++){
				temp_b[t]=set_b[t];
			}
			
            new_size=2*original_size;
            printf("(resize) from %d to %d\n",original_size,new_size);
            set_b=(int *)malloc(new_size*sizeof(int));
			
			for(int t=0;t<original_size;t++){
				set_b[t]=temp_b[t];
			}
        }
    }

    int set_result[num_b];    
    
    for(int i=0,sum=0,min;i<(num_a-num_b+1);i++,sum=0){
        for(int f=i,g=0;g<num_b;f++,g++){
            int test=fabs(set_a[f]-set_b[g]);
            sum=sum+test;
        }

        if(i==0){
            min=sum;
            for(int h=0,j=i;h<num_b;h++,j++){
                set_result[h]=set_a[j];
            }
        }
    
        if (sum<min){
            min=sum;
            for(int h=0,j=i;h<num_b;h++,j++){
                set_result[h]=set_a[j];
            }       
        }
        
    }

    printf("---Result---\n");
    for(int i=0;i<num_b;i++){
        printf("%d ",set_result[i]);
    }

    free(set_a);
    free(set_b);
    return 0;
}