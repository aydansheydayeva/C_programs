#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct person{
	float x_pos;
	float y_pos;
	float arr_x[128];
	float arr_y[128];
	float rad;
	int pos;
};

struct person* init(float x, float y, float r){
	struct person *p =(struct person*)malloc(sizeof(struct person));
	p->x_pos = x;
	p->y_pos = y;
	p->rad = r;
	p->pos = 0;
	return p;
}

void walk(struct person *p, float x_new, float y_new){
	if (p->pos == 0){
		p->arr_x[p->pos]=p->x_pos;
		p->arr_y[p->pos]=p->y_pos;
		p->pos = p->pos + 1;
		p->arr_x[p->pos] = x_new;
		p->arr_y[p->pos] = y_new;
	}
	else{
		p->pos = p->pos + 1;
		p->arr_x[p->pos] = x_new;
		p->arr_y[p->pos] = y_new;
	}
}

void num_in_vision_zone(struct person *p_first, struct person *p_second){
	int c=0;
	for (int i=0; i<= p_first->pos; i++ ){
		for (int j=0; j <= p_second->pos; j++){
			float x = sqrt( pow(p_first->arr_x[i] - p_second->arr_x[j],2)  +  pow(p_first->arr_y[i]-p_second->arr_y[j],2) );
			if ( (p_first->rad + p_second->rad) >= x){
				printf("Intersection steps: p1(%d), p2(%d) ", i, j);
				printf("\n");
				c+=1;

			}
		}
	}
	printf("\n");
	printf("The number of itersections: %d", c);
}
int main(){
	float a, b, c;
	printf("Enter initial x, y, r for p1: ");
	scanf("%f %f %f", &a, &b, &c);
	float a1, b1, c1;
	printf("Enter initial x, y, r  for p2: ");
	scanf("%f %f %f", &a1, &b1, &c1);
	struct person *p1= init(a,b,c);
	struct person *p2= init(a1, b1, c1);
	walk(p1, 10, 10);
	walk(p2, 4, 16);
	walk(p2, 10, 8);
	walk(p1, 17, 2);
	walk(p2, 14, 15);
	walk(p1, 21, 5);
	walk(p2, 21, 8);

	num_in_vision_zone(p1, p2);
	printf("\n");
	return 0;

}
