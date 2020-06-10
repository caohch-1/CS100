#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define RES_SIZE 128
#define NAME_SIZE 64

typedef struct{
    char name[NAME_SIZE];
    float score;
}Student; 


typedef struct {
    Student * data;
    struct Node * next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}LinkedList; 

int compare (const char* str1, const char* str2){
    for(int i=0;;i++){
        if( (str1[i]!='\0' && str2[i]=='\0') || (str1[i]>str2[i]) ){
            return 1;
            break;
        }
        else if( (str2[i]!='\0' && str1[i]=='\0') || (str1[i]<str2[i]) ){
            return -1;
            break;
        }
        else if(str1[i]=='\0' && str2[i]=='\0' ){
            return 0;
            break;
        }
    }
}

void string_sort (char* strings[], int size){
    for(int i=0; i<size ;i++){
        for(int j=1; j<size ;j++){
            int judge=compare(strings[j-1],strings[j]);
            if(judge==1){
                char * temp;
                temp=strings[j-1];                
                strings[j-1]=strings[j];                
                strings[j]=temp;                
            }
        }
    }
}

Student* new_student(const char* _name, float _score){
    Student * ptr=(Student*)malloc(sizeof(Student));
    ptr->score=_score;
    strcpy(ptr->name,_name);
    return ptr;
}

void list_init(LinkedList* l){
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
}

void list_insert(LinkedList* l, Student* stu_ptr){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=stu_ptr;
    temp->next=NULL;
    if(l->head!=NULL){
        l->tail->next=temp;
    }
    l->tail=temp;
    if(l->head==NULL){
        l->head=temp;
    }
    l->size++;
}

void list_erase(LinkedList* l){
    Node *current;
    while(l->head){
    current=l->head;
    l->head=l->head->next;
    free(current->data);
    free(current);
    }
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
}

Node* list_remove(LinkedList* l, Node* target){
    Node *current,*prev;
    current=l->head;
    for(int i=0;i<l->size;i++){
        if(current==target){
            break;
        }
        prev=current;
        current=current->next;
    }
    if(current==target){
        if(current==l->head && current!=l->tail){
            l->head=current->next;
            l->size--;
            free(current->data);
            free(current);
            return l->head;
        }
        else if(current==l->tail && current!=l->head){
            prev->next=NULL;
            l->tail=prev;
            l->size--;
            free(current->data);
            free(current);
            return NULL;
        }
        else if(current==l->tail && current==l->head){
            l->head=NULL;
            l->tail=NULL;
            l->size--;
        }
        else{
            prev->next=current->next;
            l->size--;
            free(current->data);
            free(current);
            return current->next;
        }
        free(current->data);
        free(current);
    }

    else{
        return NULL;
    }
}

/*******************************Part3: Searching*******************************************/
Node* list_search_by_name(LinkedList* l, char* search_name){
    Node *current;
    current=l->head;
    int a=2;
    for(int i=0;i<l->size;i++){
        a=compare(current->data->name,search_name);
        if(a==0){
            return current;
        }
        else if(i==l->size-1){
            return NULL;
        }
    current=current->next;
    }
}

int list_search_by_score(LinkedList* l, 
                        float lower_bound,
                        float upper_bound,
                        char* result[RES_SIZE])
{
    Node *current;
    current=l->head;
    int num=0;
    for(int i=0;i<l->size;i++){
        if(current->data->score>=lower_bound && current->data->score<=upper_bound){
            result[num]=current->data->name;
            num++;
        }
        current=current->next;
    }
    string_sort(result,num);
    return num;
}

/*******************************Your Main Function*****************************************/
//DO NOT submit main function to OJ, or compile error may happen!
int main(){
    Student* caohch=new_student("Hongchen Cao",20.0);
    Student* youch=new_student("Cunhan You",100.0);
    Student* gengza=new_student("Genzi Ang",90.0);
    Student* xicb=new_student("Chenbo Xi",88.0);

    LinkedList *test=(LinkedList*)malloc(sizeof(LinkedList));

    list_init(test);
    int a;
    char* result_[RES_SIZE];
    list_insert(test,caohch);
    list_insert(test,youch);
    list_insert(test,gengza);
    list_insert(test,xicb);
    //a=list_search_by_score(test,1x2,98.0,result_);
    //printf("%d",a);

    //list_erase(test);

    /*char *results;
    list_search_by_score(test,0.0,100.0,results);*/

    /*int a;
    char *results;
    a=list_search_by_score(test,10.0,30.0,results);
    printf("%d",a);*/

    Node * god_choose_you;
    god_choose_you=list_search_by_name(test,"hdgd");
    if(god_choose_you==NULL){
        printf("1");
    }
    //printf("%s",god_choose_you->data->name);

    /*Node *current;
    Node *first;
    first=test->head;
    Node *last;
    last=test->tail;
    Node *noraml;

    current=test->head;
    for(int i=0;i<1;i++){
        current=current->next;
    }
    noraml=current;
    printf("%s\n",noraml->data->name);

    /*current=test->head;
    while(current!=NULL){
        printf("%s\n",current->data->name);
        current=current->next;
    }*/

    /*list_remove(test,first);
    current=test->head;

    while(current!=NULL){
        printf("%s\n",current->data->name);
        current=current->next;
    }*/

    return 0;
}