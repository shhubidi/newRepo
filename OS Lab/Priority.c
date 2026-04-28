#include <stdio.h> //Include Required Library

int main()
{
    int pid[10]={0},bt[10]={0},tat[10]={0},wt[10]={0},p[10]={0},ct[10]={0};
        float totaltat=0,totalwt=0;
        int n;
        printf("Enter the number of Process");
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            pid[i] = i+1;
        }
        for (int i =0;i<n;i++)
        {
            printf("Enter the Burst Time for P%d ",i+1);
            scanf("%d",&bt[i]);
            printf("Enter the Priority of P%d ",i+1);
                scanf("%d",&p[i]);
        }
        for (int i=0;i<n-1;i++)
        {
            for (int j=0;j<n-i-1;j++)
            {
                if (p[j]>p[j+1])
                {
                    int temp =p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                    temp=bt[j];
                    bt[j]=bt[j+1];
                    bt[j+1]=temp;
                    temp=pid[j];
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
                    tat[i]=ct[i];
                    wt[i]=tat[i]-bt[i];
                    totaltat=totaltat+tat[i];
                    totalwt=totalwt+wt[i];
                }
                printf("P\tPr\tbt\tct\ttat\twt\n");
                for (int i=0;i<n;i++)
                {
                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],p[i],bt[i],ct[i],tat[i],wt[i]);
                }
                printf("\nAverage Turn Around Time %.2f \n",totaltat/n);
                printf("Average Waiting Time %.2f",totalwt/n);
    return 0;
            }

