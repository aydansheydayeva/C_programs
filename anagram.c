#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void sort_word(char *strng){
	for(int i=0; i<strlen(strng)-1; i++){
		for(int j=i+1; j<strlen(strng); j++){//j=0??
			if(strng[i]>strng[j]){
				char temp=strng[i];
				strng[i]=strng[j];
				strng[j]=temp;
			}

		}
	}
}

bool find(char *strng1, char *strng2){
	int n1=strlen(strng1);
	int n2=strlen(strng2);
	if(n1==n2){
		sort_word(strng1);
		sort_word(strng2);
		int num=0;
		for(int i=0; i<n1; i++){
			if(strng1[i]==strng2[i])
				num+=1;
		}
		if(num==n1){
			return true;
		}
		/*OR
		 * if(strcmp(strng1,strng2)==0)
		 	return true;
		*/
	}
	else{
		return false;
	}
}

int main(){
	char word[20]="apple";
	char mix[64]="elppa";
	char mix2[64]="laepp";

	if(find(word,mix))
		printf("+\n");
	else
		printf("-\n");

	if(find(word,mix2))
		printf("+\n");
	else
		printf("-\n");
	return 0;
}
