#include<stdio.h>
int main(){
	int num_lecture ,hour_begin,minute_begin,hour_end,minute_end,hour_end_pre=8,minute_end_pre=0;
	float mood=100;
	
	printf("How many lectures today?\n");
	scanf("%d",&num_lecture);
	
	for(int i=0;i < num_lecture;i++,hour_end_pre=hour_end,minute_end_pre=minute_end){
		
		scanf("%d:%d-%d:%d",&hour_begin,&minute_begin,&hour_end,&minute_end);
		int difference_lecture=(hour_end*60+minute_end)-(hour_begin*60+minute_begin);
		int difference_rest=(hour_begin*60+minute_begin)-(hour_end_pre*60+minute_end_pre);
		
		
		float drop_mood;
		float add_mood=difference_rest*0.5;
		
		if(difference_lecture<=60){drop_mood=difference_lecture*0.4;}
		else{drop_mood=24+(difference_lecture-60)*0.8;}
		
		mood=mood+add_mood;
		if(mood>=100){mood=100;}
		
		mood=mood-drop_mood;
		
		if(mood<=0){
			printf("Gezi Wang has been sent to hospital.");
		    break;
			}
	}
	
	if((mood>0)&&(mood<=100)){
	mood=mood+(22*60-(hour_end*60+minute_end))*0.5;
	if((mood>0)&&(mood<=100)){printf("His mood level is %.1f at the end of the day.",mood);}
	else{printf("His mood level is 100.0 at the end of the day.");}
	}
	
	else if(mood>100){printf("His mood level is 100.0 at the end of the day.");}
		
	return 0;
}