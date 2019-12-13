#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//not completed
void sort_alphab_by_every_letter(int n, char buff[n][64]){
	//printf("+");
	char buff2[64];
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(buff[i], buff[j])>0){
				strcpy(buff2, buff[i]);
				strcpy(buff[i], buff[j]);
				strcpy(buff[j], buff2);
			}
		}
	}
}
//in some cases it considers only the first letter, but sometimes all of them;
void sort_by_first_and_save_rest(int n, char buff[n][64]){
	char buff2[64];
	for(int i=0; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(buff[i][0]>buff[j][0] && buff[i][0]!=buff[j][0]){
				strcpy(buff2, buff[i]);
				strcpy(buff[i], buff[j]);
				strcpy(buff[j], buff2);
			}
		}
	}
}


int main(){
	printf("how many words would be sorted: ");
	int n;
	scanf("%d", &n);

	char buff[n][64];
	for(int i=0; i<n; i++){
		char buff2[64];
		scanf("%s", buff2);
		strcpy(buff[i], buff2);
	}

	//buff is the matrix with words as strings in each row
	//and we should get the matrix
	//with words in each row but in alphabetical order

	//sort_alphab_by_every_letter(n, buff);
	//sort_by_first_and_save_rest(n, buff);

	printf("\n");
	for(int i=0; i<=n; i++){
		for(int j=0; j<strlen(buff[i]); j++){
			printf("%c", buff[i][j]);
		}
		printf("\n");
	}

	return 0;
}
