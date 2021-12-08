// Convex Hull.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	int x,y;
} pt;

void Hull(pt[],int);
void main(){

	int n=7;
	pt pts[n];

	printf("ENter points : \n");
	for(int i=0; i<n ;i++)
		scanf("%d %d ",&pts[i].x , &pts[i].y);

	// for(int i=0; i<n ;i++)
	// 	printf("%d %d \n",pts[i].x , pts[i].y);

	Hull(pts,n);

	///////// TESTING ....

	// pt p1 = pts[2];
	// pt p2 = pts[3];

	// printf("(%d , %d) (%d ,%d) \n",p1.x , p1.y , p2.x , p2.y );
	// int a = p2.y - p1.y;
	// int b = p1.x - p2.x;
	// int c = p1.x*p2.y - p1.y*p2.x ;

	// printf("(%d , %d, %d)\n\n",a,b,c );
	// int L_pts =0 , R_pts =0;
	// for(int k=0;k<n;k++){
	// 	pt p = pts[k];
	// 	printf("(%d , %d) \t",p.x , p.y);
	// 	printf("%d + %d -%d \t",a*(p.x),b*(p.y),c );
	// 	if((a*(p.x) + b*(p.y) - c )< 0)
	// 		printf("L\n");
	// 	else if((a*(p.x) + b*(p.y) - c )> 0)
	// 		printf("R\n");
	// 	else 
	// 		printf("\n");
	//}
}

void Hull(pt pts[],int n){
	pt Convex_set[n];
	for(int i=0 ; i<n ;++i){
		for(int j=0; j<n;j++){
			if(i!=j){
				pt p1 = pts[i];
				pt p2 = pts[j];
				//printf("(%d , %d) (%d ,%d) \n",p1.x , p1.y , p2.x , p2.y );
				int a = p2.y - p1.y;
				int b = p1.x - p2.x;
				int c = p1.x*p2.y - p1.y*p2.x ;

				int L_pts =0 , R_pts =0;
				for (int k=0;k<n;k++){
					
					pt p = pts[k];
					if(k != i && k!= j){
						if((a*(p.x) + b*(p.y) - c )< 0)
							L_pts ++;
						else if((a*(p.x) + b*(p.y) - c )> 0)
							R_pts ++;
					}
				}
				//printf("%d %d \t", L_pts,R_pts );
				if( L_pts ==0 ||R_pts ==0){
					printf("(%d , %d) (%d ,%d) \n",p1.x , p1.y , p2.x , p2.y );
					//Convex_set[i] = 
					break;
				}

			}
		}
		

		// ax+by+c the line eqn bn i & j 


	}
}