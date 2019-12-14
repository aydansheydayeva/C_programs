#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ARRAY of person struct elements
struct person{
	char name[20];
	char surname[20];
	int age;
};

struct person* create(char *name, char *surname, int age){
	struct person *p=(struct person*)malloc(sizeof(struct person));
	strcpy(p->name,name);
	strcpy(p->surname,surname);
	p->age=age;
	return p;
}

struct vector{
	struct person *buff;
	int count_people;
	int pos;
};

struct vector *init(int people_num){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(struct person*)malloc(sizeof(struct person)*people_num);
	v->count_people=people_num;
	v->pos=-1;
	return v;
}

int main(){
	struct person *p1=create("name1", "Surname1", 18);
	struct person *p2=create("name2", "Surname2", 28);
	struct person *p3=create("name3", "Surname3", 38);

	struct vector *v=init(3);
	v->pos+=3;
	v->buff[0]=*p1;
	v->buff[1]=*p2;
	v->buff[2]=*p3;

	for(int i=0; i<=v->pos; i++){
		v->buff[i].age+=10;
	}
	for(int i=0; i<=v->pos; i++){
		printf("%d\n" ,v->buff[i].age);
	}

	return 0;
}

//MATRIX CREATED BY TWO STRUCTS(vectors)
struct s_vector{
	int *buff;
	int size;
	int pos;
};

struct s_vector* init_1(int size){
	struct s_vector *v=(struct s_vector*)malloc(sizeof(struct s_vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->size=size;
	v->pos=-1;
	return v;
}

struct mx{
	struct s_vector *buff;
	int row_count;
	int pos;
};

struct mx* init_2(int vector_count){
	struct mx *mx=(struct mx*)malloc(sizeof(struct mx));
	mx->buff=(struct s_vector*)malloc(sizeof(struct s_vector)*vector_count);
	mx->row_count=vector_count;
	mx->pos=-1;
	return mx;
}
int main(){
	struct s_vector *v1=init_1(3);
	struct s_vector *v2=init_1(3);

	v1->buff[0]=34;
	v1->buff[1]=78;
	v1->buff[2]=39;

	v2->buff[0]=12;
	v2->buff[1]=99;
	v2->buff[2]=56;

	struct mx *mx=init_2(2);
	mx->buff[0]=*v1;
	mx->buff[1]=*v2;

	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			printf("%d ", mx->buff[i].buff[j]);
		}
		printf("\n");
	}

	return 0;
}

//this code takes the name of author, the book and year and returns structs in mx in sorted order based on year

struct book{
	char author_name[20];
	char book_name[20];
	int year;
};

struct book* create(char *author, char *book, int year){
	struct book *bk=(struct book*)malloc(sizeof(struct book));
	strcpy(bk->author_name,author);
	strcpy(bk->book_name, book);
	bk->year=year;
	return bk;
}

void q_sort(struct book *temp, int low, int high){
	if(low<high){
		int l=low;
		int h=high;
		int pivot=(low+high)/2;
		while(l<h){
			while(temp[l].year<=temp[pivot].year)
				l+=1;
			while(temp[h].year>temp[pivot].year)
				h-=1;
			if(l<h){
				struct book m=temp[l];
				temp[l]=temp[h];
				temp[h]=m;
			}
		}
		struct book n=temp[h];
		temp[h]=temp[pivot];
		temp[pivot]=n;
		q_sort(temp, low, h-1);
		q_sort(temp, h+1, high);
	}
}

void print_in_sorted_order(int row, int col, struct book mx[row][col]){
	struct book temp[row*col];
	int c=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			temp[c]=mx[i][j];
			c+=1;
		}
	}
	q_sort(temp, 0, row*col-1);

	int x=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			mx[i][j]=temp[x];
			x+=1;
		}
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ", mx[i][j].year);
		}
		printf("\n");
	}
}

int main(){
	struct book mx[2][2];

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			char author[20], book[20];
			int year;
			printf("enter author: ");
			scanf("%s", author);
			printf("enter bookname: ");
			scanf("%s", book);
			printf("enter year: ");
			scanf("%d", &year);

			struct book *bk=create(author, book, year);
			mx[i][j]=*bk;
		}
	}

	print_in_sorted_order(2, 2, mx);

	return 0;
}
