#include<stdio.h>
int main(){
	int n;
	float pre,max,min;
	printf("Please type number of inputs: ");
	scanf("%d",&n);
	scanf("%f",&pre);
	max=min=pre;
	for(int i=1 ; i<n ; i++){
		scanf("%f",&pre);
		if(pre>max){max=pre;}
		else if(pre<min){min=pre;}
	}
	printf("Max value: %.1f",max);
	printf("\nMin value: %.1f",min);
	return 0;
}