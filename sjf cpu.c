#include<stdio.h>
struct process{
int pid,at,bt,ct,wt,tat;
};
void read(struct process ar[],int n){
for(int i=0;i<n;i++){
printf("Enter the arrival time of p%d: ",i+1);
scanf("%d",&ar[i].at);
printf("Enter the burst time of p%d: ",i+1);
scanf("%d",&ar[i].bt);
ar[i].pid = i+1;
}
}
void sort(struct process ar[],int n){
struct process temp;
for(int i=0;i<n-1;i++){
for(int j=0;j<n-1-i;j++){
if(ar[j].at>ar[j+1].at){
temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;
}
}
}
}
void work(struct process ar[],int n){
int temp,small;
struct process Temp;
ar[0].ct=ar[0].at + ar[0].bt;
ar[0].tat = ar[0].ct - ar[0].at;
ar[0].wt = ar[0].tat - ar[0].bt;
temp=ar[0].ct;
for(int i=1;i<n;i++){
small=i;
for(int j=i;j<n;j++){
if(ar[j].bt<ar[small].bt && ar[j].at<=temp){
small = j;
}
}
Temp= ar[i];
ar[i]=ar[small];
ar[small]=Temp;
ar[i].ct=ar[i-1].ct + ar[i].bt;
 ar[i].tat = ar[i].ct - ar[i].at;
 ar[i].wt = ar[i].tat - ar[i].bt;
temp=ar[i].ct;
}
}
void print(struct process ar[],int n){
 printf("\nafter scheduling:\npid\tat\tbt\tct\ttat\twt\n--
-------------------------------------------\n");
 for(int i=0;i<n;i++){
 
printf("%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt
,ar[i].ct,ar[i].tat,ar[i].wt);
 }
 printf("\n");
}
void calc(struct process ar[],int n,float *t_wt,float 
*t_tat){
int total_wt=0,total_tat=0;
for (int i = 0; i < n; ++i)
{
total_wt+=ar[i].wt;
total_tat+=ar[i].tat;
}
*t_tat=total_tat;
*t_wt=total_wt;
}
void main(){
int n;
float t_wt,t_tat;
printf("Enter the no of processes: ");
scanf("%d",&n);
struct process ar[n];
read(ar,n);
sort(ar,n);
work(ar,n);
print(ar,n);
calc(ar,n,&t_wt,&t_tat);
printf("\naverage waiting time= %0.2fms\naverage turn 
around time=%0.2fms\n",t_wt/n,t_tat/n);
}
