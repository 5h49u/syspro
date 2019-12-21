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

void create(char pn[20], int at, int bt)
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

void sort()
{
    node *p, *q;
    int temp;
    int end = 0;
    char tem[20];
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->arrivalT > q->arrivalT)
            {
                strcpy(tem, p->pname);
                strcpy(p->pname, q->pname);
                strcpy(q->pname, tem);

                temp = p->arrivalT;
                p->arrivalT = q->arrivalT;
                q->arrivalT = temp;

                temp = p->burstT;
                p->burstT = q->burstT;
                q->burstT = temp;
            }
        }
    }

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p == head)
            {
                end = p->burstT;
            }
            else
            {
                if (q->arrivalT <= end && p->burstT > q->burstT)
                {
                    strcpy(tem, p->pname);
                    strcpy(p->pname, q->pname);
                    strcpy(q->pname, tem);

                    temp = p->arrivalT;
                    p->arrivalT = q->arrivalT;
                    q->arrivalT = temp;

                    temp = p->burstT;
                    p->burstT = q->burstT;
                    q->burstT = temp;
                }
            }
        }
        end = end + p->burstT;
    }
}

void calc()
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        if (p == head)
        {
            p->startT = p->arrivalT;
            p->endT = p->burstT;
            p->tat = p->endT - p->arrivalT;
            p->waitT = p->tat - p->burstT;
        }
        for (q = p->next; q != NULL; q = q->next)
        {

            if (q->arrivalT > p->endT)
            {
                q->startT = q->arrivalT;
            }
            else
                q->startT = p->endT;
            q->endT = q->startT + q->burstT;
            q->tat = q->endT - q->arrivalT;
            q->waitT = q->tat - q->burstT;

            break;
        }
    }
}

void print()
{
    node *p;
    printf("Pname\tArrival\tBurst\tStart\tend\ttat\twait\n");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->arrivalT, p->burstT, p->startT, p->endT, p->tat, p->waitT);
        totaltat += p->tat;
        totalwt += p->waitT;
    }
}

void printg()
{

    node *current, *p = head, *q = head;

    for (current = head; current->next != NULL; current = current->next)
        ;

    printf("end Ts -\t");
    printf("%d\t\t", p->startT);

    for (int i = 0; i <= current->endT; i++)
    {
        if (i == p->endT)
        {
            printf("%d\t\t", p->endT);
            p = p->next;
        }
    }
    printf("\n");
    printf("Pname\t\t");
    for (int i = 0; i <= current->endT; i++)
    {
        if (i == q->endT)
        {
            printf("\t%s\t", q->pname);
            q = q->next;
        }
    }

    printf("\n");
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