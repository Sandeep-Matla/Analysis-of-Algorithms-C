#include<stdio.h>
#include<stdlib.h>
int isSafe(int n,int board[n][n],int row, int col){
	for(int j=col ;j>=0 ;--j){
		if(board[row][j])
			return 0;	
	}
	for(int i=row , j=col ; i>=0 && j>=0 ;i--,j--){
		if(board[i][j])
			return 0;	
	}
	for(int i=row , j=col ; i<n && j>=0 ;i++,j--){
		if(board[i][j])
			return 0;
	}
	return 1;
}
int nqueen(int n ,int board[n][n] , int col){
	if(col>=n)
		return 1;
	for(int row =0 ;row<n;row++){
		if(isSafe(n,board,row,col)){
			board[row][col] = 1;

			if(nqueen(n,board,col+1))
				return 1;
			board[row][col] = 0;
		}
	}
	return 0;
}
void main(){
	int n;
	printf("Enter n :");
	scanf("%d",&n);

	int Board[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			Board[i][j] = 0;

	int res = nqueen(n,Board,0);
	if(res){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",Board[i][j]);
			printf("\n");
		}
	}
	else
		printf("Connot COnstruct\n");
		
}