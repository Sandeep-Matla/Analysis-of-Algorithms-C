#include<stdio.h>
#include<limits.h>
int min_node(int n,int wt[],int visit[]){
	int min = INT_MAX;
	int min_ind;
	for(int i=0;i<n;i++){
		if(visit[i] == 0 && wt[i]<min){
			min = wt[i];
			min_ind = i;
		}
	}
	printf("min : %d",min_ind );
	return min_ind;
}
void mst(int n, int map[n][n]){
	int wt[n];
	int visit[n];
	int parent[n];

	for(int i=0;i<n;i++){
		visit[i] = 0;
		wt[i] = INT_MAX;
	}
	wt[0] = 0;
	parent [0] = -1;
	int sum=0;
	int root = 0;
	for(int i=0;i<n-1;i++){

		for(int j=0; j<n;j++){
			if(map[root][j] && visit[j] ==0 && map[root][j] < wt[j]){
				parent[j] = root;
				//printf("%d ",j);
				wt[j] = map[root][j];
			}
		}
		root = min_node(n,wt,visit);

		sum += wt[root];
		visit[root] = 1;
		printf("\nroot %d : \n", root);
		
	}
	printf("tree : \n");
	for(int i=0;i<n;i++)
		printf("%d ",parent[i] );
	for(int i=0;i<n;i++)
		printf("%d ",wt[i]);

	printf("\n %d",sum);
	
}
void main(){
	int n;
	printf("Enter no of nodes: ");
	scanf("%d",&n);

	int map[n][n];

	printf("Enter graph : \n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);

	mst(n,map);

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++)
	// 		printf(" %d",map[i][j]);
	// 	printf("\n");
	// }

}