#include  <stdio.h> //include Required Library

int main()
{
    int pid[10]={0},bt[10]={0},ct[10]={0},tat[10]={0},wt[10]={0};
    float totaltat=0,totalwt=0;
    int n;
    printf("Enter the number of Process ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        pid[i]=i+1;
    }
    for (int i=0;i<n;i++)
    {
        printf("Enter the Burst Time for P[%d]",i+1);
        scanf("%d",&bt[i]);
    }
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (bt[j]>bt[j+1])
            {
                int temp = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp = pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
            }
        }
    }
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum = sum+bt[i];
        ct[i]=sum;
        tat[i]=sum;
        totaltat=totaltat+tat[i];
    }
    for (int i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        totalwt=totalwt+wt[i];
    }
    printf("Solution \n");
    printf("P\tbt\tct\ttat\twt \n");
    for (int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\%d\t%d\n",pid[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("The Average TAT is : %.2f\n",totaltat/n);
    printf("The Average WT is : %.2f",totalwt/n);
}
