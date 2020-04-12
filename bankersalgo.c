#include<stdio.h>
int main()
{
int q, allocation[10], max[10], need[10], available,i,j,flag[10],x=0,sequence[10],c=0;
printf("Enter the number of process \n");
scanf("%d",&q);
for (i=0;i<q;i++)
{
    flag[i]=0;  //initially no process have been allocated resources
}
for(i=0;i<q;i++)
{
    printf("Enter the allocation for process Q[%d]\n",i);
    scanf("%d",&allocation[i]);
    printf("Enter the max for process Q[%d]\n",i);
    scanf("%d",&max[i]);
}
printf("Enter the available resources");
    scanf("%d",&available);
for(i=0;i<q;i++)
{
    need[i]=max[i]-allocation[i];
}
for(i=0;i<q;i++)
{
    printf("Need of Q[%d] is %d\n",i,need[i]);
}
for(i=0;i<q;i++) 
{
    for(j=0;j<q;j++)
    {
        if(flag[j]==0&&need[j]<=available) 
        {
        available=available+allocation[j];
        flag[j]=1;
        printf("Process %d has been allocated resources\n",j);
        sequence[c]=j;
        c++;
        }
    }
}
for(i=0;i<q;i++)
{
    if(flag[i]==0)
    {
    printf("system is in unsafe state\n");
    x=1;
    break;
    }
}
if(x==0)
{
printf("System is in safe state\n");
printf("Safe sequence is \n");
for(i=0;i<q;i++)
{
    printf("Q[%d],",sequence[i]);
}
}
printf("\n");
}
