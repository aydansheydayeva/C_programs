#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void replace_line(char *path, int n, char *str){
	
	char *new_path=strdup(path);
	int len_new_path=strlen(new_path);
	int n_start_txt=len_new_path-4;
	new_path[n_start_txt]='2';
	new_path[n_start_txt+1]='.';
	new_path[n_start_txt+2]='t';
	new_path[n_start_txt+3]='x';
	new_path[n_start_txt+4]='t';
	new_path[n_start_txt+5]='\0';

	FILE *f1=fopen(path, "a+");
	FILE *f2=fopen(new_path, "a+");

	char buff[128];
	int z=1;
	while(fgets(buff, 128, f1)!=NULL){
		if(z==n){
			fputs(str, f2);
			//fprintf(f2, "%s", str);
		}
		else{
			fputs(buff, f2);
		}
		z+=1;
	}
	remove(path);
	rename(new_path, path);
}


void file_read(char *path){
	FILE *f=fopen(path, "a+");
	char buff[128];
	while(fgets(buff,128,f)!=NULL){
		fputs(buff,stdout);
	}
}

int main(){
	char path[128];
	char str[128];
	int n;
	printf("Input the new line: ");
	fgets(str, 128, stdin);//reads with '\0' and '\n' i guess
	printf("Enter the path: ");
	scanf("%s", path);
	printf("The number of the line: ");
	scanf("%d", &n);
//	When the next two lines are not placed first then fgets() reads the first output of string in path(i guess)
//	printf("Input the  new line: ");
//	fgets(str,128,stdin);

	//scanf("%1023[^\n]",str);

	//file_read(path);
	replace_line(path, n, str);
	//file_read(path);
	return 0;
}
