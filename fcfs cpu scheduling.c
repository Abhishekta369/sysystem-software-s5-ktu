#include<stdio.h>
struct pro{
 int pid,at,bt,ct,tat,wt;
};
void read(struct pro a[],int n){
 for(int i=0;i<n;i++){
 printf("Enter the process id: ");
 scanf("%d",&a[i].pid);
 printf("Enter the arrival time: ");
 scanf("%d",&a[i].at);
 printf("Enter the buffer time: ");
 scanf("%d",&a[i].bt);
 }
}
void sort(struct pro a[],int n){
 struct pro temp;
 for(int i=0;i<n-1;i++){
 for(int j=0;j<n-i-1;j++){
 if(a[j].at>a[j+1].at){
 temp=a[j+1];
 a[j+1]=a[j];
 a[j]=temp;
 }
 }
 }
}
void calc(struct pro a[],int n,float *tat,float *wt){
 a[0].ct=a[0].bt+a[0].at;
 a[0].tat=a[0].ct-a[0].at;
 a[0].wt=a[0].tat-a[0].bt;
 for(int i=1;i<n;i++){
 a[i].ct=a[i-1].ct+a[i].bt;
 a[i].tat=a[i].ct-a[i].at;
 a[i].wt=a[i].tat-a[i].bt;
 }
 int tat_s=0,wt_sum=0;
 for(int i=0;i<n;i++){
 tat_s+=a[i].tat;
 wt_sum+=a[i].wt;
 }
 *tat= (float) tat_s/n;
 *wt = (float) wt_sum/n;
}
2
BVB
void print(struct pro a[],int n,int c){
 if(c){
 printf("\nafter scheduling:\npid\tat\tbt\tct\ttat\twt\n----
-----------------------------------------\n");
 for(int i=0;i<n;i++){
 
printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pid,a[i].at,a[i].bt,a[i]
.ct,a[i].tat,a[i].wt);
 }
 printf("\n");
 }
 else{
 printf("\nbefore scheduling:\npid\tat\tbt\n------------
-------------------\n");
 for(int i=0;i<n;i++){
 printf("%d\t%d\t%d\n",a[i].pid,a[i].at,a[i].bt);
 }
 printf("\n");
 } 
}
void main(){
 int a;
 float avg_tat=0,avg_wt=0;
 printf("Enter the no of processes: ");
 scanf("%d",&a);
 struct pro ar[a];
 read(ar,a);
 print(ar,a,0);
 sort(ar,a);
 calc(ar,a,&avg_tat,&avg_wt);
 print(ar,a,1);
 printf("average waiting time: %.2fms",avg_wt);
 printf("\naverage turn around time: %.2fms",avg_tat);
}
