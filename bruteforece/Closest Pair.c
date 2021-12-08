#include<stdio.h>
#include<math.h>

typedef struct {
	int x; int y;
} Point;

void FindClosest(Point[] , int);
void main(){
	int n=6;
	Point pts[n];

	// Reading Points..
	printf("Enter the Points : \n");
	for (int i=0;i<n;i++)
		scanf("%d %d",&pts[i].x , &pts[i].y);
	printf("\n");
	for (int i=0;i<n;i++)
		printf("%d %d\n",pts[i].x , pts[i].y);	

	FindClosest(pts,n);

}

void FindClosest(Point pts[], int n){
	float d , min_d = 9999999999999999;

	Point close_pair[2];
	for(int i=0;i<n;i++){
		for(int j =0;j<n ; j++){
			if(i != j){
				// will find the closest distance .

				int a = (pts[i].x - pts[j].x);
				int b = (pts[i].y - pts[j].y);

				d = sqrt(a*a + b*b);

				printf(" %.2f" , min_d);
				if(d < min_d){
					min_d = d;

					close_pair[0] = pts[i];
					close_pair[1] = pts[j];
				}

			}
		}
	}

	printf("closest pair is : (%d , %d ) & (%d , %d)",close_pair[0].x,close_pair[0].y, close_pair[1].x , close_pair[1].y);

	printf("min Distance : %.2f", min_d);
}