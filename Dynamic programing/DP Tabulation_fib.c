// Dynamic Programming -> 2. Tabulation 
// Fibonacci Series...

#include<stdio.h>
int fib(int n){
	int table[n+1];
	if(n < 0)
		return -1;
	else{
		table[0] = 0;
		table[1] = 1;

		for(int i = 2; i<=n ; i++){
			table[i] = table[i-1] + table[i-2] ;
		}
	}
	return table[n];
}
void main(){
	int n;
	printf("Enter no : ");
	scanf("%d",&n);
	printf("Fib values of %d is : %d ",n,fib(n));
}