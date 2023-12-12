#include<stdio.h>
main()
{
	int no_of_process,no_of_resource=3,available[10],work[10], max[10][10],need[10][10],allocation[10][10];
	int i,j,flag=0,ss[10],k=0,finish[10],l;
	printf("Enter number of processes and resources:");
	scanf("%d%d",&no_of_process,&no_of_resource);
	printf("Enter allocation matrix\n");
	for(i=0;i<no_of_process;i++)
		for(j=0;j<no_of_resource;j++)
			scanf("%d",&allocation[i][j]);
	printf("Enter max matrix\n");
	for(i=0;i<no_of_process;i++)
		for(j=0;j<no_of_resource;j++)
			scanf("%d",&max[i][j]);
	printf("Enter available resources\n");
	for(i=0;i<no_of_resource;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	for(i=0;i<no_of_process;i++)
		finish[i]=0;
	for(i=0;i<no_of_process;i++)
		for(j=0;j<no_of_resource;j++)
			need[i][j]=max[i][j]-allocation[i][j];// compute Need Matrix
	printf("Need Matrix is\n");		
	for(i=0;i<no_of_process;i++)
	{
		for(j=0;j<no_of_resource;j++)
			printf("%d ",need[i][j]);// print Need Matrix in matrix format
		printf("\n");	
	}
	for(l=0;l<no_of_process;l++)
	{
		for(i=0;i<no_of_process;i++)
		{
			flag=0;
			if(finish[i]==0)// select an unfinished process and check its need<=work if not select next process in the list
			{
				for(j=0;j<no_of_resource;j++)
				{	
					if(need[i][j]>work[j])// select next process in order 
					{
						flag=1;
						break;
					}
				}
				if(flag==0)//found an unfinished process and  need<=work
				{	
					for(j=0;j<no_of_resource;j++)
					{
						work[j]+=allocation[i][j];// update work
					}
					ss[k]=i;// insert the process into safe sequence 
					k=k+1;
					finish[i]=1;// mark it as finished 
				}
			}
		}	
	}

	flag=1;
	for(i=0;i<no_of_process;i++)
	{
		if(finish[i]==0)// if finish[i]=0 for any one of the process state is not safe
		{
			flag=0;
			printf("System is not safe\n");
			break;
		}
	}
	if(flag==1)// if finish[i]=1 for all the process state is  safe and print safe sequence
	{
		printf("Safe Sequence is:")	;
		for(i=0;i<no_of_process-1;i++)
			printf("P%d->",ss[i]);
		printf("P%d",ss[no_of_process-1]);	
	}
}
