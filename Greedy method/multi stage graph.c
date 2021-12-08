#include <stdio.h>
#include<limits.h>
int msg(int n, int dis[n][n]){

	int cost[n];
	int parent[n];
	int min=0;
	for(int i=0;i<n;i++)
		cost[i] = 0;
	parent[n-1] = n-1;
	for(int i=n-2;i>=0;i--){
		min = INT_MAX;
		for(int j=i+1;j<n;j++){
			if(dis[i][j] && dis[i][j] + cost[j] < min){
				min = dis[i][j]+cost[j];
				//printf("cost[%d][%d] = %d\n",i,j,min );
				parent[i] = j;
			}
		}
		cost[i] = min;
	}
	for(int i=0 ; i<n ;i++)
		printf("%d ",cost[i] );
	printf("\n");
	for(int i=0 ; i<n ;i++)
		printf("%d ",parent[i] );
	printf("\n");
	printf("min cost : %d",cost[0]);
	// printing path
	int path[n];
	
	printf("\n path :  %d ",0 );
	int par = parent[0];
	for(int i=0;i<n;i++){

		printf(" -> %d",par );
		par = parent [par];
		if(par == n-1){
			printf(" -> %d\n",n-1 );
			break;
		}
		
	}
}
void main(){
	int n;
	printf("Enter no of nodes : ");
	scanf("%d",&n);

	int Distance [n][n];

	printf("Enter dis matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&Distance[i][j]);

	msg(n,Distance);
		

}