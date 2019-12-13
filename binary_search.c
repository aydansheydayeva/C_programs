#include<stdio.h>
#include<stdlib.h>

struct vector{
	int *buff;
	int pos;
	int size;
};

struct vector* init(int size){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->pos=-1;
	v->size=size;
	return v;
}

void append(struct vector *v, int num){
	if(v->pos-1<v->size){
		v->pos+=1;
		v->buff[v->pos]=num;
	}
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void quick_sort(int *buff, int low, int high){
	if(low<high){
		int i=low;
		int j=high;
		int pivot=low;
		while(i<j){
			while(buff[i]<buff[pivot])
				i++;
			while(buff[j]>buff[pivot])
				j--;
			if(i<j){
				swap(&buff[i],&buff[j]);
			}
		}
		swap(&buff[j],&buff[pivot]);
		quick_sort(buff, low, pivot-1);
		quick_sort(buff, pivot+1, high);
	}
}

int binary_search(int *buff, int low, int high, int elem){
	while(low<=high){
		int m=(low+high)/2;
		if(buff[m]==elem){
			return m;
		}
		else if(buff[m]<elem)
			low=m+1;
		else
			high=m-1;
	}
	return -1;
}

int main(){
	struct vector *v=init(10);
	append(v, 4);
	append(v, 5);
	append(v, 99);
	append(v, 30);
	append(v, 56);
	append(v, 19);
	append(v, 9);
	quick_sort(v->buff, 0, v->pos);
	for(int i=0; i<=v->pos; i++){
		printf("%d ", v->buff[i]);
	}
	printf("\n");

	int x=binary_search(v->buff, 0, v->pos, 99);
	printf("%d\n", x);

	return 0;
}
