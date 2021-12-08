#include <stdio.h>
#include<limits.h>
void floyeds(int n , int path[n][n]){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				path[i][j] = path[i][j] || (path[i][k] && path[k][j]) ;
}
void main(){
	printf("Enter no of nodes : ");
	int n;
	scanf("%d",&n);

	printf("Enter path matrix :\n");
	int paths[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&paths[i][j]);

	floyeds(n,paths);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d",paths[i][j]);
		printf("\n");
	}	
}