// Dynamic Programming
// Recursion.

#include<stdio.h>

typedef struct
{
	int wt;
	int cost;
}Item;

int max(int a, int b){
	return (a>b) ? a : b;
}
int KnapSack(Item items[], int Weight , int n ){
	if( n<=0 || Weight==0)
		return 0;
	else if(items[n-1].wt > Weight ) /// n-1 is just for indexing items[n-1] = nth item.
		return KnapSack(items, Weight, n-1 );
	else
		return max((items[n-1].cost + KnapSack(items, Weight-items[n-1].wt , n-1)), KnapSack(items, Weight, n-1));
}
void main(){
	int n;
	printf("Enter no.of items : ");
	scanf("%d",&n);

	Item items[n];

	printf("Enter item_weight item_cost \n");
	for(int i=0;i<n;i++){
		scanf("%d %d",&items[i].wt,&items[i].cost);
	}
	int Bag_weight;
	printf("Enter Bag Max_weight : ");
	scanf("%d",&Bag_weight);
	printf("%d\n",KnapSack(items,Bag_weight,n) );

}
