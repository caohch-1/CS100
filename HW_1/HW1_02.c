#include<stdio.h>
#include<math.h>
int main(){
	double x_1,x_2,x_3,y_1,y_2,y_3;
	
	printf("Input vertex 1: ");
	scanf("%lf %lf",&x_1,&y_1);
	printf("Input vertex 2: ");
	scanf("%lf %lf",&x_2,&y_2);
	printf("Input vertex 3: ");
	scanf("%lf %lf",&x_3,&y_3);
	
	double max,min,x_c=(x_1 + x_2 +x_3)/3,y_c=(y_1 + y_2 + y_3)/3;
	
	printf("The center of the triangle is: %.1lf %.1lf",x_c,y_c);
	double dis_B=sqrt((x_c-x_2)*(x_c-x_2)+(y_c-y_2)*(y_c-y_2));
	double dis_C=sqrt((x_c-x_3)*(x_c-x_3)+(y_c-y_3)*(y_c-y_3));
	double dis_A=sqrt((x_c-x_1)*(x_c-x_1)+(y_c-y_1)*(y_c-y_1));
	
	if((dis_A > dis_B)&&(dis_A > dis_C)){max=dis_A;}
	else if((dis_B > dis_A)&&(dis_B > dis_C)){max=dis_B;}
	else{max=dis_C;}
	
	if((dis_A < dis_B)&&(dis_A < dis_C)){min=dis_A;}
	else if((dis_B < dis_A)&&(dis_B < dis_C)){min=dis_B;}
	else{min=dis_C;}
	
	printf("\nThe maximum distance between center and vertices: %.2lf",max);
	printf("\nThe minimum distance between center and vertices: %.2lf",min);
	return 0;
}