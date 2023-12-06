#include<stdio.h>
struct sjf
{
 int pno;
 int at;
 int bt;
 int wt;
 int ct;
 int tat;
 int rebt;
};
void sort(struct sjf s[],int n);
void display(struct sjf s[],int n);
void main()
{
 struct sjf s[10];
 int rq[20],k,ts,l;
 int n,i,j,flag[10];
 float avg_wt=0,avg_tat=0;
 printf("Enter the number of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter the processes no:");
 scanf("%d",&s[i].pno);
 printf("Enter the arrival time of processes 
%d:",s[i].pno);
 scanf("%d",&s[i].at);
 printf("Enter the burst time of processes %d:",s[i].pno);
 scanf("%d",&s[i].bt);
 s[i].wt=0;
 s[i].ct=0;
 s[i].tat=0;
 flag[i]=0;
 s[i].rebt=s[i].bt;
 }
 printf("Enter time slice:");
 scanf("%d",&ts);
 printf("Before Scheduling\n");
 printf("*****************\n");
 display(s,n);
 sort(s,n);
 display(s,n);
 // For calculating the completion time.
 //first process
 if(s[0].bt<ts)
 {
 s[0].ct+=s[0].bt+s[0].at;
 s[0].rebt=0;

 }
 else
 {
 s[0].ct+=ts+s[0].at;
 s[0].rebt=s[0].rebt-ts;
 }
 flag[0]=1;//taken this process
 k=1;
 for(i=1;i<n;i++)
 {
 if(s[i].at<=s[0].ct)
 {
 rq[k++]=i;
 flag[i]=1;
 }
 }
 if(s[0].rebt>0)
 rq[k++]=0;
 for(i=1;i<k;i++)//take process from ready queue
 {
 if(s[rq[i]].rebt<ts)
 {
 
 s[rq[i]].ct=s[rq[i-1]].ct+s[rq[i]].rebt;
 s[rq[i]].rebt=0; 
 }
 else
 {
 s[rq[i]].ct=s[rq[i-1]].ct+ts;
 s[rq[i]].rebt=s[rq[i]].rebt-ts; 
 }
 for(j=0;j<n;j++)
 {
 if(s[j].at<=s[rq[i]].ct && flag[j]==0)
 {
 rq[k++]=j;
 flag[j]=1;
 }
 }
 if(s[rq[i]].rebt>0)
 rq[k++]=rq[i];
 }
 for(l=0;l<k;l++)
 printf("Ready Queue:%d ",s[rq[l]].pno);
 // For calculating the turn around time.
 for(i=0;i<n;i++)
 {
 s[i].tat+=s[i].ct-s[i].at; 
 }
 // For calculating the waiting time.

 for(i=0;i<n;i++)
 {
 s[i].wt=s[i].tat-s[i].bt;
 }
 printf("\nAfter Scheduling\n");
 printf("****************\n");
 display(s,n);
 // For calculating the Avg waiting time.
 for(i=0;i<n;i++)
 {
 avg_wt+=s[i].wt;
 }
 avg_wt=(float)avg_wt/n;
 for(i=0;i<n;i++)
 {
 avg_tat+=s[i].tat;
 }
 avg_tat=avg_tat/(float)n;
 printf("\nAverage waiting time=%0.2fms",avg_wt);
 printf("\nAverage turn around time=%0.2fms\n",avg_tat);
}
void sort(struct sjf s[],int n)
{
 int i,j;
 struct sjf temp;
 for(i=0;i<n;i++)
 for(j=0;j<n-i-1;j++)
 {
 if((s[j].at>s[j+1].at ) )
 {
 temp=s[j];
 s[j]=s[j+1];
 s[j+1]=temp;
 }
 }
}
void display(struct sjf s[],int n)
{
 int i;
 printf("Process No Arr.Time Burst.Time Wait.Time 
Com.Time Turn aroud.Time\n");
 for(i=0;i<n;i++)
 {
 
printf("%d\t\t%d\t\t%d\t%d\t\t%d\t\t%d\n",s[i].pno,s[i].at,s[i].b
t,s[i].wt,s[i].ct,s[i].tat);
 }
}
