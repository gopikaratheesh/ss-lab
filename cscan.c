#include<stdio.h>


void main(){
	int head,n,i,j;
	float total_seek=0.00;
	printf("SCAN CPU scheduling\n");
	printf("%d\t%d",0,500);
	printf("\nEnter the initial head process\n");
	scanf("%d",&head); 
	printf("Enter the no of process\n");
	scanf("%d",&n); int arr[n];
	printf("Enter the arrival time of processes");
	for (i=0;i<n;i++)	{
		scanf("%d",&arr[i]); 
		}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	i=0;
	while(head>=arr[i]){
		i=i+1;
		}
	int t=i,temp;
	for(i=t;i<n;i++){
	 	temp=abs(head-arr[i]);
		head=arr[i];
		total_seek+=temp;
		}
	temp=abs(head-arr[t-1]);
	head=arr[t-1];
	total_seek+=temp;
	for(i=t-2;i>=0;i--){
		temp=abs(head-arr[i]);
		head=arr[i];
		total_seek+=temp;
		}
	printf("The total seek time=\t%f\nThe avg seek time=\t%f\n",total_seek,(total_seek/n));
}
