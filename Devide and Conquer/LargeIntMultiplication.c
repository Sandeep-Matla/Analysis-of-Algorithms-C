// Not Acuurate..
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(x,y) (x > y)? x: y ;
long multiply(long n1,long n2){
	if(n1 <10 || n2<10 )
		return n1*n2;
	else{
		printf(" n1: %d n2: %d\n",n1,n2);
		int l1 = log10(n1) +1; /// no of dig.
		int l2 = log10(n2) +1;
		
		
		int n = MAX(l1,l2);
		printf("%d\n",n );

		int nd = n/2;
		// Split num into 2 parts
		int split = pow(10,nd);
		
		printf(" n1: %d n2: %d %d %d %d\n",n1,n2,n,nd , split);

		int a0 = n1/split ;
		int a1 = n1 % split ;

		int b0 = n2 / split ;
		int b1 = n2 % split ;

		printf("%d %d %d %d \n", a0,a1,b0,b1);

		long c0 = multiply(a0,b0);
		long c2 = multiply(a1,b1);
		long c1 = multiply((a0+a1), (b0+b1)) - c0 - c2;
		//printf("%d %d %d\n",c0 ,c1 , c2);

		return (c0*pow(10,2*nd) + c1*pow(10, nd)+ c2);
	}
}

void main(){

	long n1 = 1235;
	long n2= 3897;

	printf("%ld\n",n1*n2 );
	printf("%ld\n",multiply(n1,n2) );
}