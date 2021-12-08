#include<stdio.h>
typedef struct
{
	int wt,cost;
}Item;
void main(){
		int n;
		printf("Enter no of elemnts : ");
		scanf("%d",&n);

		Item items[n];
		for(int i=0;i<n;i++)
			scanf("%d %d",items[i].wt,items[i].cost);
	
}