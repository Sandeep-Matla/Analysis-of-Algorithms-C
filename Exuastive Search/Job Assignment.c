#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **perms;
int c=0;
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
void Job_Schedule(int ** Assigns ,int n , int Job_cost[n][n] ){

	int min_cost = (1<<31)-1;
	int cost, min_ass_ind;
	for(int i=0;i<(tgamma(n+1));i++){
		cost = 0; 
		for(int j=0;j<n;j++)
			cost += Job_cost[j][Assigns[i][j]]; 

		if(cost<min_cost){
			min_cost = cost;
			min_ass_ind = i ;
		}
	}

	printf("Min Cost : %d\n", min_cost);
	printf("The Assignment : \n");
	for(int k=0;k<n;k++)
		printf(" %d -> %d ",k,Assigns[min_ass_ind][k] );
}
void main(){
	int n  = 4;

	int Jobs[n];// "0123"
	for(int i =0;i<n;i++)
		Jobs[i] = i;

	int JobCost_emp[n][n]; // Assumed its a complete graph. every node is connected ech another node
	printf("Enter cost for Job for each emp :\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&JobCost_emp[i][j]);

	// Calculating Permuattion
	int total = tgamma(n+1); // Gamma fun in math.h . i.e, tgamma(n+1) = factorial(n)

	perms  = (int**)malloc(total*sizeof(int*));
	Int_permute(Jobs, 0,n-1);

	int **Assigns = perms;

	Job_Schedule(Assigns , n,  JobCost_emp);


}