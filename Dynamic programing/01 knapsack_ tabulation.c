// Dynamic Programming
// Recursion + Tableorisation.

#include<stdio.h>

typedef struct
{
	int wt;
	int cost;
}Item;
int max(int a, int b){
	return (a>b) ? a : b;
}

////// Main Function....
int KnapSack(Item items[], int w , int n ){
	int Table [n+1][w+1];
	for(int i=0;i<=n;i++)
		Table[i][0] = 0;
	for(int j=0;j<=w;j++)
		Table[0][j] = 0;

	//  Filiing values into  table

	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(items[i-1].wt <= j)
				Table[i][j] = max(items[i-1].cost + Table[i-1][j- items[i-1].wt] , Table[i-1][j]);
			else
				Table[i][j] = Table[i-1][j];
		}
	}
	// for(int i=0;i<n+1;i++){
	// 	for(int j=0;j<w+1;j++)
	// 		printf(" %d ", Table[i][j] );
	// 	printf("\n");
	// }
	return Table[n][w];
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
