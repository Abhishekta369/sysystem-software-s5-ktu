#include<stdio.h>
struct process{
int pid,at,bt,ct,wt,tat,pr;
};
void read(struct process ar[],int n){
for(int i=0;i<n;i++){
printf("Enter the arrival time of p%d: ",i+1);
scanf("%d",&ar[i].at);
printf("Enter the burst time of p%d: ",i+1);
scanf("%d",&ar[i].bt);
 printf("enter the priority: ");
 scanf("%d",&ar[i].pr);
ar[i].pid = i+1;
}}
void sort(struct process ar[],int n){
struct process temp;
for(int i=0;i<n-1;i++){
for(int j=0;j<n-1-i;j++){
if(ar[j].at>ar[j+1].at){
temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;
}}}}
void work(struct process ar[],int n){
int temp,tag;
struct process Temp;
ar[0].ct=ar[0].at + ar[0].bt;
ar[0].tat = ar[0].ct - ar[0].at;
ar[0].wt = ar[0].tat - ar[0].bt;
temp=ar[0].ct;
for(int i=1;i<n;i++){
tag=i;
for(int j=i;j<n;j++){
if(ar[j].pr>ar[tag].pr && ar[j].at<=temp){ 
//use ar[j].pr>ar[tag].pr when higher number represent higher 
priority
tag = j; 
//ar[j].pr<ar[tag].pr when lower number represent higher 
priority
}
}
Temp= ar[i];
ar[i]=ar[tag];
ar[tag]=Temp;
ar[i].ct=ar[i-1].ct + ar[i].bt;
 ar[i].tat = ar[i].ct - ar[i].at;
 ar[i].wt = ar[i].tat - ar[i].bt;
temp=ar[i].ct;
}}
void print_after(struct process ar[],int n){
 printf("\nafter scheduling:\npid\tat\tbt\tct\ttat\twt\n------
---------------------------------------\n");
 for(int i=0;i<n;i++){
 
printf("%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt,ar[
i].ct,ar[i].tat,ar[i].wt);
 }
 printf("\n");
}
void print_before(struct process ar[],int n){
 printf("\nbefore scheduling:\npid\tat\tbt\n------------------
--\n");
 for(int i=0;i<n;i++){
 printf("%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt); }
 printf("\n");
}
void calc(struct process ar[],int n,float *avg_tat,float 
*avg_wt){
float tat=0,wt=0;
for (int i = 0; i < n; i++){
tat+=ar[i].tat;
wt+=ar[i].wt;
}
*avg_tat=tat;
*avg_wt=wt;
}
void main(){
int n;
float total_tat,total_wt;
printf("Enter the no of processes: ");
scanf("%d",&n);
struct process ar[n];
read(ar,n);
print_before(ar,n);
sort(ar,n);
work(ar,n);
calc(ar,n,&total_tat,&total_wt);
print_after(ar,n);
printf("average waiting time= %.2fms\naverage turn around 
time =%.2fms\n",total_wt/n,total_tat/n);
}
