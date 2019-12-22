#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct n
{
    char pname[20];
    int arrivalT, burstT, startT, endT, waitT, tat;
    struct n *next;
} node;

node *head, *last;
int totalwt = 0;
int totaltat = 0;

void create(char pn[20], int at, int bt) //Create nodes accordingly
{
    node *p;
    p = (node *)malloc(sizeof(node));
    strcpy(p->pname, pn);
    p->arrivalT = at;
    p->burstT = bt;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }

    else
    {
        last->next = p;
    }

    last = p;
}


void swap (node *p,node *q) {
    int temp;
    char tem[20];

    strcpy(tem,p->pname);
    strcpy(p->pname,q->pname);
    strcpy(q->pname,tem);

    temp= p->arrivalT;
    p->arrivalT=q->arrivalT;
    q->arrivalT=temp;

    temp=p->burstT;
    p->burstT=q->burstT;
    q->burstT=temp;

}

void sort () {
    
}

int main()
{
    int n, arrivalT, burstT;
    char pname[20];
    printf("How many process do you want to run ?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the process name, Arrival T, Burst T-:\n");
        scanf("%s%d%d", pname, &arrivalT, &burstT);
        create(pname, arrivalT, burstT);
    }

    sort();
    calc();
    print();
    printf("\nAverage Waiting time:%f", (float)totalwt / n);
    printf("\nAverage Turn Around Time:%f\n", (float)totaltat / n);
    printg();
}