//FIRST COME FIRST SORT SCHEDULING ALGORITHM

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct n
{

    char pname[20];
    int accessTime, burstTime, exitTime, startTime, tat, waitTime;
    struct n *next;
} node;
static int totalwt = 0, totaltat = 0;
node *head, *last;

void create(char pname[20], int at, int bt)
{

    node *p;
    p = (node *)malloc(sizeof(node));
    strcpy(p->pname, pname);
    p->accessTime = at;
    p->burstTime = bt;
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

void sort() //Sort according to Arrival Time
{

    node *p, *q;
    int t;
    char name[20];

    for (p = head; p != NULL; p = p->next) //Bubble Sort
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->accessTime > q->accessTime)
            {
                strcpy(name, p->pname);
                strcpy(p->pname, q->pname);
                strcpy(q->pname, name);

                t = p->accessTime;
                p->accessTime = q->accessTime;
                q->accessTime = t;

                t = p->burstTime;
                p->burstTime = q->burstTime;
                q->burstTime = t;
            }
        }
    }
}

void calc()//Calculate Start time ,End Time, Turn around time, Wait time for each process(Common logic for all Scheduling Programs)
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        if (p == head)
        {
            p->startTime = p->accessTime; //Start time for each process would be its arrival time
            p->exitTime = p->burstTime;     //End time for first process would be its burst time
            p->tat = p->exitTime - p->accessTime;//Turn around time = Exit time - arrival time
            p->waitTime = p->tat - p->burstTime;// Wait time = Turn around time - Burst time of the process
        }
        for (q = p->next; q != NULL; q = q->next)
        {

            if (q->accessTime > p->exitTime)
            {
                q->startTime = q->accessTime;
            }
            else
                q->startTime = p->exitTime; //Start time of subsequent process would be the end time of previous process
            q->exitTime = q->startTime + q->burstTime;//End time would be the Start time + Burst time of the process
            q->tat = q->exitTime - q->accessTime;
            q->waitTime = q->tat - q->burstTime;

            break;
        }
    }
}

void print() //Printing the data in a tabluar form (Common logic for all scheduling programs)
{
    node *p;
    printf("Pname\tArrival\tBurst\tStart\texit\ttat\twait\n");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->accessTime, p->burstTime, p->startTime, p->exitTime, p->tat, p->waitTime);
        totaltat += p->tat;
        totalwt += p->waitTime;
    }
}

void printg() //Printing Gantt Chart(Common logic for all scheduling programs)
{

    node *current, *p = head, *q = head;

    for (current = head; current->next != NULL; current = current->next)
        ;

    printf("Exit Times -\t");
    printf("%d\t\t", p->startTime);

    for (int i = 0; i <= current->exitTime; i++)
    {
        if (i == p->exitTime)
        {

            printf("%d\t\t", p->exitTime);
            p = p->next;
        }
    }
    printf("\n");
    printf("Pname\t\t");
    for (int i = 0; i <= current->exitTime; i++)
    {
        if (i == q->exitTime)
        {

            printf("\t%s\t", q->pname);
            q = q->next;
        }
    }

    printf("\n");
}

int main(void)
{

    char pname[20];
    int at, bt, n;
    printf("How many processes?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the process name and arrival time and burst time\n");
        scanf("%s%d%d", pname, &at, &bt);
        create(pname, at, bt);
    }
    sort();
    calc();
    print();
    printf("\nAverage Waiting time:%f", (float)totalwt / n);
    printf("\nAverage Turn Around Time:%f\n", (float)totaltat / n);
    printg();
}