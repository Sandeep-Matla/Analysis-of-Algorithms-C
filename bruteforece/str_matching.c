#include<stdio.h>
#include<string.h>

int string_match(char str[],char match[],int l1,int l2){
	int count = 0;
	int flag = 0;
	for(int i=0;i<=l1-l2;i++){
		count = 0;
		// printf("%c",str[i]);
		for(int j=0;j<l2;j++){
			if(str[i+j] == match[j])
				count++;
		}
		if(count == l2){
			flag = 1;
			printf("Match Found\n");
		}
	}
	if(flag == 0)
		printf("Match doesn't found");
}
void main(){
	char c;
	char str[100];
	char match[100];
	printf("ENter main str : ");
	scanf("%[^\n]s",str);
	getchar();
	printf("ENter str to match : ");
	scanf("%[^\n]s",match);

	int l1=strlen(str);
	int l2=strlen(match);

	// printf("%s\n",str );
	// printf("%s\n",match );
	string_match(str,match,l1,l2);
}