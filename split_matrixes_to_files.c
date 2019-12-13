#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct vector{
	int pos;
	int size;
	int *buff;
};

struct vector* init(int size){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->pos=-1;
	v->size=size;
	return v;
}

void pr_vector(struct vector *v){
	for(int i=0; i<=v->pos; i++){
		printf("%d ", v->buff[i]);
	}
	printf("\n");
}

void append(struct vector *v, int data){
	if((v->pos+1)!=v->size){
		v->pos+=1;
		v->buff[v->pos]=data;
	}
}

void fill_mx(int row, int col, int buff[row][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d", &buff[i][j]);
		}
	}
}

void print_mx(int row, int col, int buff[row][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ", buff[i][j]);
		}
		printf("\n");
	}
}

struct vector_c{
	char *buff;
	int size;
};

struct vector_c* init_c(int size){
	struct vector_c* v=(struct vector_c*)malloc(sizeof(struct vector));
	v->buff=(char*)malloc(sizeof(char)*size);
	v->size=size;
	return v;
}

struct vector_c* new_name(char *strng, int a, int b){
	struct vector_c *pathname=init_c(strlen(strng)+3);
	int n=strlen(strng);
	strcpy(pathname->buff,strng);
	pathname->buff[n]='F';
	pathname->buff[n+1]=a+'0';
	pathname->buff[n+2]=b+'0';

	return pathname;
}

void move_mx_with_beginning_ij_to_file_f(FILE *f, int row, int col, int buff[row][col],int i, int j, int r_c, int c_c){
	for(int m=i; m<i+r_c; m++){
		for(int n=j; n<j+c_c; n++){
			fprintf(f, "%d ", buff[m][n]);
		}
		fputs("\n", f);
	}
}

void split_to_files(int row, int col, int buff[row][col], int r, int c){
	int r_c=row/r;
	int c_c=col/c;
	struct vector *v_r=init(r);
	struct vector *v_c=init(c);

	for(int i=0; i<row; i+=r_c){
		append(v_r, i);
	}

	for(int j=0; j<col; j+=c_c){
		append(v_c, j);
	}
	for(int i=0; i<=v_r->pos; i++){
		for(int j=0; j<=v_c->pos; j++){
			struct vector_c *pathname=new_name("./", v_r->buff[i], v_c->buff[j]);
			FILE *f=fopen(pathname->buff, "a+");
			move_mx_with_beginning_ij_to_file_f(f, row, col, buff, v_r->buff[i], v_c->buff[j], r_c, c_c);
			fclose(f);
		}
	}

}

int main(){
	int row;
	int col;
	printf("enter row_num: ");
	scanf("%d", &row);
	printf("enter col_num: ");
	scanf("%d", &col);
	int buff[row][col];

	fill_mx(row, col, buff);
	int r, c;
	printf("to what number split the rows: ");
	scanf("%d", &r);
	printf("to what number split the columns: ");
	scanf("%d", &c);
	//print_mx(row, col, buff);
	split_to_files(row, col, buff, r, c);

	return 0;
}
