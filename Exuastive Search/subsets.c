void Int_Subsets(int n){
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