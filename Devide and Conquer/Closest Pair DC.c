#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	int x; int y;
} Point;
int abs(int n){
	return (n <0) ? -1*n : n;
}
float min(float a ,float b){
	return (a<b) ?  a :  b;
}
int comapreX(const void* a , const void* b){
	Point *p1 = (Point*) a;
	Point *p2 = (Point*) b;

	return (p1->x - p2->x);

}
int comapreY(const void* a , const void* b){
	Point *p1 = (Point*) a;
	Point *p2 = (Point*) b;

	return (p1->y - p2->y);

}
float dist(Point p, Point q){
	int a = (p.x - q.x);
	int b = (p.y - q.y);
	
	float d = sqrt(a*a + b*b);
	// printf("dist : %f\n",d );
	return d;
}
float BruteForce(Point pts[] , int n){
	float d , min_d = 999999999;

	for(int i=0;i<n;i++){
		for(int j =0;j<n ; j++){
			if(i != j){
				d = dist(pts[i],pts[j]);
				//printf("BruteForce : %f\n",d );
				if(d < min_d)
					min_d = d;
			}
		}
	}
	return min_d;
}
float stripClosest(Point strip[], int size, float min_d){

	//sort_y(strip,n);
	qsort(strip, size, sizeof(Point),comapreY);
	
	// Appliying BruteForce...

	for(int i=0;i<size;i++){
		for(int j= i+1; j<size; j++){
			float dis = dist(strip[j] ,strip[i]);
			if( dis < min_d)
				min_d = dis;
		}
	}
	return min_d;
}
float min_distance(Point pts[], int n){

	if(n<=3){
		return BruteForce(pts, n);
	}
	else{
		int mid = (int)(n/2);
		//printf("%d\n",mid  );

		Point mid_pt = pts[mid];
		//printf("(%d %d) %d",mid_pt.x, mid_pt.y ,mid);

		float dl = min_distance(pts,mid);
		float dr = min_distance(pts+mid,n-mid);

		float d = min(dl,dr);

		// Considering poibnts on either side of the mid line..

		// => closest pair in the strip mid+d , mid-d

		Point strip[n];
		int j=0;
		for(int i=0 ; i<n ;i++){
			if(abs(pts[i].x - mid_pt.x) < d){
				strip[j] = pts[i];
				j++;
			}
		}
		return min(d, stripClosest(strip,j,d)); // j becomes the length of strip arr..
	}	
}
float FindClosest(Point pts[], int n){

	// Sort the points by x comp.

	qsort(pts,n,sizeof(Point),comapreX);
	// for (int i=0;i<n;i++)
	// 	printf("%d %d\n",pts[i].x , pts[i].y);

	return min_distance(pts,n);
}
void main(){
	int n=6;
	Point pts[n];

	// Reading Points..
	printf("Enter the Points : \n");
	for (int i=0;i<n;i++)
		scanf("%d %d",&pts[i].x , &pts[i].y);
	printf("\n");
		

	float closest_d = FindClosest(pts,n);
	printf("\n\n The Closest Distance :  %.4f ",closest_d);

}