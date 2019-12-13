#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>

struct array_char{
	char *buff;
	char size;
	int pos;
};

struct array_char* init(int size){
	struct array_char *arr=(struct array_char*)malloc(sizeof(struct array_char));
	arr->buff=(char*)malloc(sizeof(char)*size);
	arr->size=size;
	arr->pos=0;
	return arr;
}

struct array_char* find_extension(char *name){
	int n;
	struct array_char *arr=init(10);
	int m=strlen(name);
	while(n!=strlen(name)-1 && name[n]!='.'){
		n+=1;
	}

	for(int i=n+1; i<m; i++){
		arr->buff[arr->pos]=name[i];
		arr->pos+=1;
	}
	return arr;
	
}

struct array_char* joined_name(char *path, struct array_char *file_ext){//here it would be better to pass char *extn->buff;
	struct array_char *new_dir_name=init(128);
	for(int i=0; i<strlen(path); i++){
		new_dir_name->buff[i]=path[i];
		new_dir_name->pos+=1;
	}

	new_dir_name->buff[new_dir_name->pos+0]='/';
	new_dir_name->buff[new_dir_name->pos+1]='f';
	new_dir_name->buff[new_dir_name->pos+2]='i';
	new_dir_name->buff[new_dir_name->pos+3]='l';
	new_dir_name->buff[new_dir_name->pos+4]='e';
	new_dir_name->buff[new_dir_name->pos+5]='_';

	new_dir_name->pos+=6;

	for(int i=0; i <=file_ext->pos; i++){
		new_dir_name->buff[new_dir_name->pos+i]=file_ext->buff[i];
	}
	new_dir_name->pos+=file_ext->pos;

	return new_dir_name;

}

struct array_char* join(char *path, char *filename){
	struct array_char *new_p=init(128);
	for(int i=0; i<strlen(path); i++){
		new_p->buff[i]=path[i];
		new_p->pos+=1;
	}
	new_p->buff[new_p->pos+0]='/';
	new_p->pos+=1;
	for(int i=0; i<strlen(filename); i++){
		new_p->buff[new_p->pos+i]=filename[i];
	}

	return new_p;
}

void divide_extensions(char *path){
	DIR *dir=opendir(path);
	struct dirent *dir_walk;

	while((dir_walk=readdir(dir))!=NULL){
		struct array_char *extn=find_extension(dir_walk->d_name);
		struct array_char *newname=joined_name(path, extn);
		struct array_char *remove_file=join(path, "/file_");
		struct array_char *remove_file_2=join(path, "/file_.");
		if(mkdir(newname->buff, 0777)!=0 && strcmp(newname->buff,remove_file->buff)!=0 && strcmp(newname->buff,remove_file_2->buff)!=0)
			mkdir(newname->buff, 0777);

		remove(remove_file->buff);
		remove(remove_file_2->buff);
		struct array_char *old_path=join(path, dir_walk->d_name);
		struct array_char *new_path=join(newname->buff, dir_walk->d_name);
		rename(old_path->buff, new_path->buff);
}
}


int main(){
	char path[128];
	scanf("%s",path);

	divide_extensions(path);

	return 0;
}
