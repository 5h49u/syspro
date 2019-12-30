#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct n {
     char pname[20];
     int arrivalT,burstT,priority;
     struct n *next;

}node;

node *head,*last;

void create(char pn[20],int at,int bt,int pt) {
     node *p;
     p = (node *)malloc(sizeof(node));
     strcpy(p->pname,pn);
     p->arrivalT=at;
     p->burstT=bt;
     p->priority=pt;
     p->next=NULL;
     
     if(head == NULL) {
     head=p;
     }
     
     else {
     last->next=p;
     }
     
     last=p;

}
void swap(node *s,node *r) { 

     char temp1[20];
     int temp;
     
     strcpy(temp1,s->pname);
     strcpy(s->pname,r->pname);
     strcpy(r->pname,temp1);
     
     temp=s->arrivalT;
     s->arrivalT=r->arrivalT;
     r->arrivalT=temp;
     
     temp=s->burstT;
     s->burstT=r->burstT;
     r->burstT=temp;
     
     
     temp=s->priority;
     s->priority=r->priority;
     r->priority=temp;

}

void sort() {

     node *p,*q;
     
     for(p=head;p!=NULL;p=p->next) {
          for(q=p->next;q!=NULL;q=q->next) {
               if(p->arrivalT > q->arrivalT) {
               swap(p,q);
               }
          }
          }
          
          
     for(p=head;p!=NULL;p=p->next) {
          if(p == head) {
          continue;
          }
          for(q=p->next;q!=NULL;q=q->next) {
                   if(p->priority < q->priority){
                   swap(p,q);
                   } 
          }
     }     
}




void print() {

node *p;
     for(p=head;p!=NULL;p=p->next) {
          printf("%s\t%d\t%d\t%d\n",p->pname,p->arrivalT,p->burstT,p->priority);
     }
}

int main(void) {

     int n,arrivalT,burstT,priority;
     char pname[20];
     
     printf("Enter the number of processes-:\n");
     scanf("%d",&n);
     
     for(int i=0;i<n;i++) {
     printf("Enter the Process name ,Arrival Time, Burst Time, Priority(Highest is 1 and lowest is 5)\n");
     scanf("%s%d%d%d",pname,&arrivalT,&burstT,&priority);
     create(pname,arrivalT,burstT,priority);
     }
     
     sort();
     print();
}


