#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//not completed
struct array_char{
	char *buff;
	int buff_size;
	int pos;
};

struct array_char* init(int size){
	struct array_char *arr=(struct array_char*)malloc(sizeof(struct array_char));
	arr->buff=(char*)malloc(sizeof(char)*size);
	arr->buff_size=size;
	arr->pos=0;
	return arr;
}

struct array_char* replace_name(char *path){
	struct array_char* new_name=init(strlen(path)+10);
	int i=strlen(path)-1;
	while(path[i]!='/'){
		i-=1;
	}
	for(int j=0; j<=i; j++){
		new_name->buff[j]=path[j];
		new_name->pos+=1;
	}
	
	new_name->buff[i+1]='r';
	new_name->buff[i+2]='e';
	new_name->buff[i+3]='p';
	new_name->buff[i+4]='l';
	new_name->buff[i+5]='a';
	new_name->buff[i+6]='c';
	new_name->buff[i+7]='e';
	new_name->buff[i+8]='.';
	new_name->buff[i+9]='t';
	new_name->buff[i+10]='x';
	new_name->buff[i+11]='t';
	i+=11;
	new_name->pos+=10;

	return new_name;

}

void find_and_replace(char *path, char *old, char *new){
	FILE *f=fopen(path, "a+");

	struct array_char *new_name=replace_name(path);
	FILE *f2=fopen(new_name->buff, "a+");
	
	char buff[512];
	while(fgets(buff, 512, f)!=NULL){
		if(!strstr(buff, old)){
			fputs(buff,f2);
		}
		else{
			int i=0;
			while(i<strlen(buff)){
				if(buff[i]==old[0] && buff[i-1]!='c' && i+strlen(old)==strlen(buff)-1){//signs at the end should be considered
					int length=0;
					int same=0;
					int x=i;
					while(x!=strlen(buff)-1){
						if(buff[x]==old[x-i])
							same+=1;
						length+=1;
						x+=1;
					}
					if(same==length){
						for(int j=0; j<strlen(new); j++){
							buff[i+j]=new[j];
						}
					}
				}
				else if(buff[i]==old[0] && buff[i-1]!='c')//or any other sign and letter except for space)
				{
					int length=0;
					int same=0;
					int x=i;
					while(buff[x]!=' '){
						if(buff[x]==old[x-i])
							same+=1;
						length+=1;
						x+=1;
					}
					if(same==length){
						for(int j=0; j<strlen(new); j++){
							buff[i+j]=new[j];
						}
					}
				}

				i+=1;
			}


			fputs(buff, f2);
		}
	}

	fclose(f);
	fclose(f2);

	remove(path);
	rename(path, new_name->buff);
	//change name after replacement
}

int main(){
	char path[128];
	printf("enter the path: ");
	scanf("%s", path);

	char old[15], new[15];
	printf("enter new word: ");
	scanf("%s", old);
	printf("enter old word: ");
	scanf("%s", new);

	find_and_replace(path, old, new);

	return 0;
}
