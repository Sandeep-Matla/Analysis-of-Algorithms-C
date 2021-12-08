#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ncr(int n,int r){
	int mem[n][r];
	for (int i=0;i<n;i++)
		for(int j=0;j<r;j++){
			if(i == 1|| j==0 || i==j)
				mem[i][j]  = 1;
			else
				mem[i][j] = 0;
		}	
	for (int i=1;i<n;i++){
		for(int j=1;j<r;j++){
				mem[i][j] = mem[i-1][j-1]+mem[i-1][j];
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<r;j++)
			printf("%d ", mem[i][j]);
		printf("\n");
	}
	return mem[n-1][r-1];

}
void main(){
	int n,r;
	printf("Enter n  & r : ");
	scanf("%d %d",&n,&r);

	if(n<r)
		printf("n should be greater than r");
	else
		printf("%d",ncr(n+1,r+1));
}