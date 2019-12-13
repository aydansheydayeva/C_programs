#include<stdio.h>
#include<stdlib.h>

void fill_mx(int row, int col, int (*buff)[col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d", &buff[i][j]);
		}
	}
}
/*
void fill_rec_rev(int row, int col, int (*buff)[col]){
	if(row==0)
		return;
	for(int i=0; i<col; i++){
		scanf("%d", &buff[row-1][i]);
	}
	fill_rec(row-1, col, buff);
}

void fill_rec(int r, int col, int (*buff)[col], int cmp){
	if(r==cmp)
		return;
	for(int i=0; i<col; i++){
		scanf("%d", &buff[r][i]);
	}
	fill_rec(r+1, col, buff, cmp);
}
*/
void print_mx(int row, int col, int (*buff)[col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ", buff[i][j]);
		}
		printf("\n");
	}
}
/*
void print_rec_mx_rev(int row, int col, int (*buff)[col]){
	if(row==0)
		return;
	//printf("row=%d, col=%d", row, col);
	for(int i=0; i<col; i++){
		printf("%d ", buff[row-1][i]);
	}
	printf("\n");
	print_rec_mx(row-1, col, buff);
}

void print_rec_mx(int r, int col, int (*buff)[col], int row){
	if(r==row)
		return;
	for(int i=0; i<col; i++){
		printf("%d ", buff[r][i]);
	}
	printf("\n");
	print_rec_mx(r+1, col, buff, row);
}
*/

void print_diagonal_main_and_secondary(int row, int col, int (*buff)[col]){
	printf("main diagonal:\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==j){
				printf("%d", buff[i][j]);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\nsecondary diagonal:\n");

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i+j==row-1){
				printf("%d", buff[i][j]);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void mult_mx1_and_mx2(int row1, int col1, int (*buff1)[col1], int row2, int col2, int (*buff2)[col2]){
	int buff3[row1][col2];
	for(int z=0; z<col2; z++){
		for(int i=0; i<row1; i++){
			int m=0;
			for(int j=0; j<col1; j++){//or j<row2
				m+=buff1[i][j]*buff2[j][z];
			}
			buff3[i][z]=m;
		}
	}
	print_mx(row1, col2, buff3);
}

int max_num(int row, int col, int (*buff)[col]){
	int max=-1e9;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(buff[i][j]>max){
				max=buff[i][j];
			}
		}
	}
	return max;
}

int main(){
	printf("FIRST MATRIX\n");
	int row1, col1;
	printf("enter row_num: ");
	scanf("%d", &row1);
	printf("enter col_num: ");
	scanf("%d", &col1);
	int buff1[row1][col1];

	//fill_rec(0, col, buff, row);
	fill_mx(row1, col1, buff1);
	//print_diagonal_main_and_secondary(row, col, buff);
	//print_mx(row, col, buff);
	//print_rec_mx_rev(row, col, buff);
	//print_rec_mx(0, col, buff, row);
	/*
	printf("SECOND MATRIX\n");
	int row2, col2;
	printf("enter row_num: ");
	scanf("%d", &row2);
	printf("enter col_num: ");
	scanf("%d", &col2);
	int buff2[row2][col2];

	fill_mx(row2, col2, buff2);

	if(col1==row2){
		mult_mx1_and_mx2(row1, col1, buff1, row2, col2, buff2);
	}
	else{
		printf("warning: not correct dimensions\n");
	}	
*/
	int max=max_num(row1, col1, buff1);
	printf("max = %d\n", max);
	return 0;
}
