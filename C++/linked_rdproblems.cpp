#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};

void insertion_at_begining(struct node *head,int info){
  struct node *temp=NULL;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=info;
  temp->link=head;
  head=temp;
}
void print(struct node* head){
  struct node* ptr=head;
  while(ptr!=NULL){
    printf("%d \n",ptr->data);
    ptr=ptr->link;
  }
}
void count_node(struct node *head){
    int count=0;
    if(head==NULL){
        printf("no node");
    }
    struct  node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
   count++;
   ptr=ptr->link;
    }
    printf("%d",count);
}
int main() {
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));   // fitst node
    head->data=45;
    head->link=NULL;

    struct node *current =(struct node *)malloc(sizeof(struct node)); // second node
    current->data=90;
    current->link=NULL;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));  // thidrd node
    current->data=135;
    current->link=NULL;
    head->link->link=current;
    
    insertion_at_begining(head,324);
    count_node(head);
    printf("\n");
    print(head);
    
return 0;
}
