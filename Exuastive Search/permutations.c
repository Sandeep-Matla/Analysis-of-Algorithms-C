/// Permutations of  a String.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void swap(char *a , int l, int r){
	int temp = a[l];
	a[l] = a[r];
	a[r] = temp;
}
char **perms;

int c=0;
// void permute(char *a , int l , int r){

// 	if(l == r){
// 		printf("%s\n",a);
// 	}
// 	for(int i=l;i<=r;i++){
// 		swap(a,l,i);
// 		//printf("%s\n",a);
// 		permute(a,l+1,r);
// 		swap(a,l,i);
// 	}
// }
void permute(char *a , int l , int r){

	if(l == r){
		// printf("%s %d %s\n",a,c,perms[c]);
		char* perm = (char*) malloc((r+1)*sizeof(char));
		int k;
		for(k=0;k<=r;k++)
			perm[k] = a[k];
		perm[k] = '\0';
		perms[c] = perm;
		//printf("%s\n",a );
		c++;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(a,l,i);
			//printf("%s\n",a);
			permute(a,l+1,r);
			swap(a,l,i);
		}
	}
	
}
void main(){
	int n;
	printf("Enter string length : \n");
	scanf("%d",&n);
	char a[n];
	printf("ENter string :");
	scanf("%s",a);
	//perms = (char**)malloc(sizeof(char*)*3);

	perms = (char**)malloc(tgamma(n+1)*sizeof(char*)); // tgamma is gamma fun in math.h. tgamma(n+1) = factorial (n)
	permute(a,0,n-1);

	for(int i=0;i<tgamma(n+1);i++)
		printf("%s\n",perms[i]);


}
