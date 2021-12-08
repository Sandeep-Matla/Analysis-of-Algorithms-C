// Matrix chain multiplication

#include<stdio.h>
#include<limits.h>
int mcm(int dim[],int l, int n){
	if(l>=n )
		return 0;
	int min = INT_MAX;
	for(int k=l;k<n;k++){
		int res = mcm(dim,l,k)+mcm(dim,k+1,n)+ dim[l-1]*dim[k]*dim[n];
		if(min > res)
			min = res;
	}
	return min;
}
void main(){
	int n;
	printf("Enter no of arrays");
	scanf("%d",&n);
	int dim[n+1];

	printf("Enter dimension Array \n");
	for(int i=0 ; i<n+1;i++)
		scanf("%d",&dim[i]);
	printf("muls : %d",mcm(dim,1,n));
}
