// Dynamic Programming ->1. Memorisation 
// Fibonacci Series...

#include<stdio.h>

int fib(int n , int mem[]){ // Array for memorisation.....
	if(n <= 1){
		mem[n] = n;
		return n;
	}
	else{
		if(mem[n] == -1)
			mem[n] = fib(n-2, mem) + fib(n-1 , mem) ;
		else
			return mem[n];
	}
}
int Fibonacci(int n){
	int Memory[n+1];
	for(int i=0 ;i<n+1;i++)
		Memory[i] = -1;
	return fib(n,Memory);
}
void main(){
	int n;
	printf("Enter no : \n");
	scanf("%d",&n);
	printf("Its Fibonacci Value is : %d \n",Fibonacci(n) );
}