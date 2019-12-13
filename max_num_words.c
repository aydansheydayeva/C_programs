#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//!!!
int num_of_words(char *buff){
	int i=0;
	int num=0;
	while(i!=strlen(buff)){
		if(buff[i]==' ' || buff[i]=='\n')//not completed
			num+=1;
		i+=1;
	}

	return num;
}

int max_num_words_in_line(char *path){
	char buff[256];
	int max=0;
	FILE *f=fopen(path, "a+");
	while(fgets(buff, 256, f)!=NULL){
		int n=num_of_words(buff);
		if(n>max){
			max=n;
		}
	}

	fclose(f);
	return max;
}

int line_with_max_num_words(char *path){
	char buff[256];
	int max=max_num_words_in_line(path);
	int line_max=1;
	FILE *f=fopen(path, "a+");
	while(fgets(buff,256,f)!=NULL){
		int n=num_of_words(buff);
		if(n!=max){
			line_max+=1;
		}
		else{
			printf("%s", buff);
			break;
		}
	}

	fclose(f);
	return line_max;
}

int main(){
	char path[128];
	printf("enter the path: ");
	scanf("%s", path);

	int x=max_num_words_in_line(path);
	printf("max num is %d\n", x);
	//by using this function find the num of line where num of words is max

	int n=line_with_max_num_words(path);
	printf("max number of words is on the %dth line\n", n);

	return 0;
}
