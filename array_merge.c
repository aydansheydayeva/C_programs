#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vector{
	int *buff;
	int buff_size;
	int pos;
	int start;
};

struct vector* init(int size){
	struct vector *v = (struct vector*)malloc(sizeof(struct vector));
	v->buff = (int*)malloc(sizeof(int)*size);
	v->buff_size=size;
	v->pos=-1;
	v->start=0;
	return v;
}

struct vector* array_merge(struct vector* v_first, struct vector* v_second){
	//struct vector* v_first = *v_f;
	//struct vector* v_second = *v_s;
	struct vector *v_third=init(v_first->buff_size + v_second->buff_size);
	for(int i=0; i<=v_first->pos; i++){
		//printf("%d\n", v_first->buff[i]);
		v_third->buff[i]=v_first->buff[i];
		//printf("%d\n", v_first->buff[i]);
	}
	for(int i=0; i<=v_second->pos; i++){
		v_third->buff[v_first->pos+1+i]=v_second->buff[i];
	}
	return v_third;
}

int main(){
	struct vector *v=init(5);
	struct vector *u=init(7);

	for(int i=0; i<5; i++){
		scanf("%d", &v->buff[i]);
		v->pos+=1;
	}

	for(int i=0; i<7; i++){
		scanf("%d", &u->buff[i]);
		u->pos+=1;
	}

	struct vector *v_new = array_merge(v, u);
	for(int i=0; i< v->buff_size + u->buff_size; i++){
		printf("%d ", v_new->buff[i]);
	}

	return 0;
}
