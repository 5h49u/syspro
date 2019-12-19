//First Come First Serve CPU scheduling algorithm using arrays




#include<stdio.h>
#include<string.h>

int main(void)
{
    char processName[10],tem[10];
    int arrivalT[10],burstT[10],startT[10],exitT[10],tat[10],wt[10],i,j,n,temp;
    int totalwt=0,totaltat=0;

    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the ProcessName, Arrival Time& Burst Time:");
        scanf("%s%d%d",&processName[i],&arrivalT[i],&burstT[i]);
    }
    for(i=0; i<n; i++)         //Sort depending on arrival time
    {
        for(j=0; j<n; j++)
        {
            if(arrivalT[i]<arrivalT[j])
            {
                temp=arrivalT[i];
                arrivalT[i]=arrivalT[j];
                arrivalT[j]=temp;
                temp=burstT[i];
                burstT[i]=burstT[j];
                burstT[j]=temp;
                strcpy(tem,processName[i]);
                strcpy(processName[i],processName[j]);
                strcpy(processName[j],tem);
            }
 
        }
    }
    for(i=0; i<n; i++)              //Calculate times based on arrival times
    {
        if(i==0)
            startT[i]=arrivalT[i];
        else
            startT[i]=exitT[i-1];
           exitT[i]=startT[i]+burstT[i];
           tat[i]=exitT[i]-arrivalT[i];
           wt[i]=tat[i]-burstT[i];
       
    }
    printf("\nProcess Name\tArrival Time\tBurst Time\tWait Time\tStart\tTAT\tExit Time");
    for(i=0; i<n; i++)
    {
        printf("\n%s\t%12d\t%12d\t%12d\t%12d\t%3d\t%3d",processName[i],arrivalT[i],burstT[i],wt[i],startT[i],tat[i],exitT[i]);
        totalwt+=wt[i];
        totaltat+=tat[i];
    }

    printf("\n");

    printf("|  %d  |",arrivalT[0]);

    for(i=0; i<n; i++)
    {
        printf("%3d |",exitT[i]);

    }

    printf("\nAverage Waiting time:%f",(float)totalwt/n);
    printf("\nAverage Turn Around Time:%f",(float)totaltat/n);
    
    
}