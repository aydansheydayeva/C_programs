#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

void red(){
	printf("\033[1;31m");
}

void green(){
	printf("\033[1;32m");
}

void blue(){
	printf("\033[1;34m");
}

void ls_a(char *path){
	DIR *dir = opendir(path);
	struct dirent *dir_walk;

	while((dir_walk=readdir(dir))!=NULL){
		if(dir_walk->d_name[0]=='.')
			red();
		else if(dir_walk->d_type==DT_DIR)
			blue();
		else if(dir_walk->d_type==DT_REG)
			green();
		
		printf("%s\n", dir_walk->d_name);

	}
	closedir(dir);
}

void ls_r(char *path){
	DIR *dir=opendir(path);
	struct dirent *dir_walk;

	char files[128][25];
	memset(files, 0, sizeof(files));
	int c=0;
	while ((dir_walk=readdir(dir))!=NULL){
		if(dir_walk->d_type==DT_DIR)
			blue();
		if(dir_walk->d_type==DT_REG)
			green();
		if(dir_walk->d_name[0]!='.'){
			for(int i=0; i<strlen(dir_walk->d_name); i++){
				files[c][i]=dir_walk->d_name[i];
			}
			c+=1;
		}
	}
	closedir(dir);
//issue with colors
	for(int i=c-1; i>=0; i--){
		for(int j=0; j<25; j++){
			printf("%c", files[i][j]);
		}
		printf("\n");
	}

}

void ls_l(char *path){

	DIR *dir=opendir(path);
	struct dirent *dir_walk;
	struct stat filestat;
	char buff[512];

	while ((dir_walk=readdir(dir))!=NULL){
		if(dir_walk->d_name[0]!='.'){
			if(dir_walk->d_type==DT_DIR)
				blue();
			if(dir_walk->d_type==DT_REG)
				green();
			

			sprintf(buff, "%s/%s", path, dir_walk->d_name);
			stat(buff, &filestat);
			printf("%u  ", filestat.st_uid);
			printf("%u  ", filestat.st_gid);
			printf("%u  ", filestat.st_mode);
			printf("%d  ", filestat.st_size);
			printf("%s\n", dir_walk->d_name);
		}
	}
	closedir(dir);
}

int main(int argc, char *argv[]){
	if (argc==3){
		if(strcmp(argv[1],"-l")==0)
			ls_l(argv[2]);
		if(strcmp(argv[1],"-r")==0)
			ls_r(argv[2]);
		if(strcmp(argv[1],"-a")==0)
			ls_a(argv[2]);

	}

	return 0;
}
