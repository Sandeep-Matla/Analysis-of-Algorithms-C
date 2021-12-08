// Greedy method 
// 0|1 Kanp SAck

#include<stdio.h>

typedef struct
{
	int wt;
	int cost;
}Item;
int max(int a, int b){
	return (a>b) ? a : b;
}
int max_Arr(float arr[] , int len){

	float max = 0;
	int max_ind = -1;
	for(int i=0;i<len;i++){
		if(arr[i] > max){
			max = arr[i];
			max_ind = i;
		}
	}
	return max_ind;
}
////// Main Function....
int KnapSack(Item items[], int bw , int n ){
	int Cost=0;
	float unit_costs [n];
	printf("Fractions : ");
	for(int i=0;i<n;i++){
		unit_costs[i] = (float)items[i].cost / items[i].wt;
		printf("%f ",unit_costs[i] );
	}
	printf("\n");
	int max_ind = max_Arr ( unit_costs , n);
	while(bw >= items[max_ind].wt){
		// Insert that weight an cost corresponding to that  max_Index .

		Cost += items[max_ind].cost;
		bw = bw - items[max_ind].wt;
	
		printf("cost : %d ",Cost );
		unit_costs[max_ind] = -1;
		
		max_ind = max_Arr ( unit_costs , n);
	}
	if(bw >0){
		max_ind = max_Arr ( unit_costs , n);
		
		Cost += bw * unit_costs[max_ind];
	}
	return Cost;
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
	printf("\n\nMax_cost : %d\n",KnapSack(items,Bag_weight,n) );

}
