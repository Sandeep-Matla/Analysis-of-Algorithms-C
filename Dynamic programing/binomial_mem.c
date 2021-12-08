#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ncr(int n, int r , int mem[n][r]){
	
	if( n==1 || r== 0 || r == n )
		return mem[n][r] = 1;
	else if(mem[n][r] != -1)
		return mem[n][r];
	else{
		return mem[n][r] = ncr(n-1,r-1,mem)+ncr(n-1,r,mem);
	}
}
int ncr_util(int n,int r){
	int mem[n][r];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mem[i][j] = -1;
	return ncr(n,r,mem);
}
void main(){
	int n,r;
	printf("Enter n  & r : ");
	scanf("%d %d",&n,&r);

	if(n<r)
		printf("n should be greater than r");
	else
		printf("%d",ncr_util(n,r));
}