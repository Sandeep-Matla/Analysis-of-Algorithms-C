// Dynamic Programming
// Recursion + Memorisation.

#include<stdio.h>

typedef struct
{
	int wt;
	int cost;
}Item;
int max(int a, int b){
	return (a>b) ? a : b;
}

////// Main Funbction....
int KnapSack_Util(Item items[], int w , int n ,int mem[n+1][w+1] ){
	if( n<=0 || w==0)
		return 0;
	else if( mem [n][w] != -1)
		return mem[n][w];

	else{
		if(items[n-1].wt > w )
			return mem[n][w] = KnapSack_Util(items, w, n-1 ,mem);
		else
			return mem[n][w] = max((items[n-1].cost + KnapSack_Util(items, w-items[n-1].wt , n-1 , mem)), KnapSack_Util(items, w, n-1 , mem));
	}
}

////
int KnapSack(Item items[], int Weight , int n ){
	int mem [n+1][Weight+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=Weight;j++)
			mem[i][j] = -1;

	int res = KnapSack_Util(items , Weight , n , mem);

	for(int i=0;i<n+1;i++){
		for(int j=0;j<Weight+1;j++)
			printf(" %d ", mem[i][j] );
		printf("\n");
	}
}
void main(){
	 //return mem[n][Weight];
	return res;
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
