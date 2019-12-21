#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct n {
    char pname[20][20];
    int arrivalT,burstT;
     struct n *next;
}node;

node *head,*last;


void create(char pn[20][20],int at,int bt) {
    node *p; 
    p = (node*)malloc(sizeof(node));
    strcpy(p->pname,pn);
    p->arrivalT=at;
    p->burstT=bt;
    p->next=NULL;
    if(head == NULL) {
        head=p;
    }

    else {
        last->next=p;
        
    }

last = p;
}

void sort() {
    node *p,*q;
    int temp;
    int exit=0;
    char tem[20];
    for(p=head;p!=NULL;p=p->next) {
           for(q=p->next;q!=NULL;q=q->next) {
               if(p->arrivalT > q->arrivalT) {
                   strcpy(tem,p->pname);
                   strcpy(p->pname,q->pname);
                   strcpy(q->pname,tem);

                   temp=p->arrivalT;
                   p->arrivalT=q->arrivalT;
                   q->arrivalT=temp;

                   temp=p->burstT;
                   p->burstT=q->burstT;
                   q->burstT=temp;
               }
           }
       }

       print();
        for(p=head;p!=NULL;p=p->next) {
           for(q=p->next;q!=NULL;q=q->next) { 
               if(p==head) {
                   exit = p->burstT;
               }
               else {
                   if(q->arrivalT <= exit && p->burstT > q->burstT) {
                       strcpy(tem,p->pname);
                      strcpy(p->pname,q->pname);
                      strcpy(q->pname,tem);

                       temp=p->arrivalT;
                       p->arrivalT=q->arrivalT;
                       q->arrivalT=temp;

                        temp=p->burstT;
                    p->burstT=q->burstT;
                         q->burstT=temp;
                   }
               }
         
         
           }
           exit = exit + p->burstT;
        }
        printf("\n");
        print();

}

void print() {
    node *p;

    for(p=head;p!=NULL;p=p->next) {
        printf("%s\t",p->pname);
    }
}

int main() {
    int n,arrivalT,burstT;
    char pname[20][20];
    printf("How many process do you want to run ?");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        printf("Enter the process name, Arrival Time, Burst Time-:\n");
        scanf("%s%d%d",&pname,&arrivalT,&burstT);
        create(pname,arrivalT,burstT);
    }

    sort();
   // calc();
  // print();





}