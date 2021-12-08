#include<stdio.h>
#include<math.h>

int ncr(int n, int r){
	if( n==1 || r== 0 || r == n )
		return 1;
	else{
		return ncr(n-1,r-1)+ncr(n-1,r);
	}
}
void main(){
	int n,r;
	printf("ENter n  & r : ");
	scanf("%d %d",&n,&r);

	if(n<r)
		printf("n should be greater than r");
	else
		printf("%d",ncr(n,r));

}