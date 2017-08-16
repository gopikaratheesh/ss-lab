#include <stdio.h>
void main(){
	int bt[20],at[20],wt[20],tt[20],n,i,j,sat,total_time=0;
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++){
		printf("Enter burst time of process %d: ", i);
		scanf("%d",&bt[i]);
		printf("Enter arrival time of process %d: ", i);
		scanf("%d",&at[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(at[j]>at[j+1]){
				int temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
			}
		}
	}
	float twt=0, ttt=0;
	sat=at[0];
	wt[0]=0;
	ttt=tt[0]=bt[0];
	total_time=sat+bt[0];
	for(i=1;i<n;i++){
		if(total_time - at[i] > 0)
			wt[i] = total_time - at[i];
		else{
			wt[i] = 0;
			total_time = at[i];
		}
	 	tt[i] = wt[i] + bt[i];
	 	twt+=wt[i];
		ttt+=tt[i];
		total_time+=bt[i];
	}
	printf("\nSl\tA.T\tB.T.\tW.T.\tT.T.");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t", i, at[i], bt[i], wt[i], tt[i]);
	}
	printf("\nAverage Waiting Time: %f\nAverage Turn Around Time: %f\n", twt/n, ttt/n);
}
