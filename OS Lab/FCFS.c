#include <stdio.h> //Required Library

int main()
{
    int at[10]={0},bt[10]={0},ct[10]={0},tat[10]={0},wt[10]={0};
    float totaltat=0,totalwt=0; // Intializing everything;
    int n;
    printf("Enter the Number Of Process ");
    scanf("%d",&n);//Intiazing n]
    int pid[10];
    for(int i = 0; i < n; i++)
        pid[i] = i + 1;
    for(int i =0;i<n;i++)
    {
        printf("Arrival Time of P[%d] ",i+1);
        scanf("%d",&at[i]);
        printf("Burst Time of P[%d] ",i+1);
        scanf("%d",&bt[i]);
    }//Intializing AT and BT
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (at[j]>at[j+1])
            {
                int temp =at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }// Sorting According to Arrival Time
    int sum = 0;
    for (int j=0;j<n;j++)
    {
        if (sum<at[j])
        {
            sum=at[j];
        }
        sum = sum + bt[j];
        ct[j]=sum;
    }// Calculating CT
    for (int k=0;k<n;k++)
    {
        tat[k]=ct[k]-at[k];
        totaltat=totaltat+tat[k];
    }// Calculating TAT
    for (int k=0;k<n;k++)
    {
        wt[k]=tat[k]-bt[k];
        totalwt=totalwt+wt[k];
    }// Calculation WT
    printf("Solution \n");
    printf("P\tAT\tBT\tCT\tTAT\tWT \n");
    for (int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }// solution Table
    printf("The Average Turn Around Time is %f",totaltat/n); //Calculating Average TAT
    printf("\nThe Average Waiting Time is %f",totalwt/n); //Calculating Average WT
}
