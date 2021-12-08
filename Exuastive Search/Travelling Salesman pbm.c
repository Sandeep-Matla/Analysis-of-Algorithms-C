// Travelling Sales man Problem;

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int** perms;
int c =0;

void swap(int *a , int l, int r){
	int temp = a[l];
	a[l] = a[r];
	a[r] = temp;
}
void Int_permute(int *a, int l , int r ){

	if(l == r){
		
		int* perm ;
		perm = (int*) malloc((r+1)*sizeof(int));
		int k;
		for(k=0;k<=r;k++)
			perm[k] = a[k];

		perms[c] = perm; 
		c++;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(a,l,i);
			//printf("%s\n",a);
			Int_permute(a,l+1,r);
			swap(a,l,i);
		}
	}
	
}
void Min_path(int** paths, int n ,int map[n][n]){
	//{123 132 213 231 321 312}
	int min_d = (1<<31)-1; // max value of int in c is 2**31 -1;
	int min_path_ind ;
	for(int i=0;i<tgamma(n);i++){
		int d =0;
		for(int j=0;j<n-1;j++){
			//path[j] = paths[i][j];
			int node = paths[i][j];
			if(j==0 || j==n-2){
				d += map[node][0];
			}
			else{
				int next = paths[i][j+1];
				d += map[node][next];
			}
		}
		if(d<min_d){
			min_d = d;
			min_path_ind = i;
		}

	}
	printf("Min Path is : ");
	printf("0 -> ");
	for(int i=0;i<n-1;i++)
		printf("%d -> ",paths[min_path_ind][i]);
	printf(" %d\n",0);
}
void main(){
	int n  = 4;

	int nodes[n];// "0123"
	for(int i =1;i<n;i++)
		nodes[i-1] = i;
	for(int y=0;y<n-1;y++)
			printf("%d ",nodes[y] );
		printf("\n");

	int map[n][n]; // Assumed its a complete graph. every node is connected ech another node
	printf("Enter distances between nodes :\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);

	// Calculating Permi=uattion
	int total = tgamma(n); // Gamma fun in math.h . i.e, tgamma(n) = factorial(n-1)

	perms  = (int**)malloc(total*sizeof(int*));
	Int_permute(nodes, 0 ,n-2);

	int** paths = perms;

	for(int x = 0;x<total;x++){
		for(int y=0;y<n-1;y++)
			printf("%d ",paths[x][y] );
		printf("\n");
	}

	Min_path(paths ,n,map);
	
}