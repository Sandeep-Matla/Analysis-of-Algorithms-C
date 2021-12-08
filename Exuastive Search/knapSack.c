// Exuastive November....

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct {
	int weight;
	int cost;
}item;
int Best_cost_In_Bag(item items[],int n ,int bag_weight){

	// Subsets Code
	int total = 1<< n; // 1<<x == 2**x
	int subsets[total][n];

	//printf("%d\n\n",(1 & 1<<0));
	int s=0; // subset index.
	for(int i=0;i<total;i++){
		// int subset[n]
		int ind=0;
		for(int mask=0 ; mask<n ; mask++){
			if(i & 1<<mask){
				subsets[s][ind] = mask;
				//printf("%d ",mask );
				ind++;
			}
		}
		subsets[s][ind++] = -1;
		s++;	
	}
	//Printing All aubsets.
	for(int s=0;s<total;s++){
		for(int k=0 ; k<n && subsets[s][k]!=-1 ;k++)
			printf("%d ",subsets[s][k]);
		printf("\n");
	}
	// --- Knap Sack Code..
	//01234.....n
	// int** subsets;
	//subsets = Int_Subsets(int n);

	int max_cost = 0,cost,weight;
	for(int s=0;s<total;s++){
		cost =0 ; weight = 0;
		for(int k=0 ; k<n && subsets[s][k]!=-1 ;k++){
			cost += items[subsets[s][k]].cost;	// cost of all ele in subset
			weight +=  items[subsets[s][k]].weight; // weight of all ele in subset

		}
		printf(" Cost : %d\n",cost );
		if(weight <= bag_weight && cost > max_cost){
			max_cost = cost;
		}

	}

	return max_cost;

}

int** Int_Subsets(int n ){
	
	// -- Bitmasking......
	int total = 1<< n; // 1<<x == 2**x
	int subsets[total][n];

	//printf("%d\n\n",(1 & 1<<0));
	int s=0; // subset index.
	for(int i=0;i<total;i++){
		int ind=0;
		for(int mask=0 ; mask<n ; mask++){
			if(i & 1<<mask){
				subsets[s][ind] = mask+1;
				ind++;
			}
		}
		subsets[s][ind++] = -1;
		s++;	
	}
	//Printing All aubsets.
	for(int s=0;s<total;s++){
		for(int k=0 ; k<n && subsets[s][k]!=-1 ;k++)
			printf("%d ",subsets[s][k]);
		printf("\n");
	}
	return subsets;
}
void main(){
	int n= 3;
	int total = 1<<n; // Total no of subsets.
	int** subsets;
	item Items[n];
	int bag_weight = 16;
	// Read Items..
	printf("Enter Items ... :\n");
	for(int i=0;i<n;i++){
		printf("Item %d :",i);
		 scanf("%d%d",&Items[i].weight , &Items[i].cost);
	}
	printf("Enter Bag weight : ");
	scanf("%d",&bag_weight);

	int cost = Best_cost_In_Bag(Items, n , bag_weight );
	printf("%d\n", cost );
}
