#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#define QUEUESIZE 1000

//QUEUE implementation with array

struct queue{
	int *buff; //body of queue
	int first; //position of first element
	int last;  //position of last element
	int count; //number of queue elements
};

struct queue* init_queue(){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->buff=(int*)malloc(sizeof(int)*(QUEUESIZE+1));
	q->first=0;
	q->last=QUEUESIZE-1;
	q->count=0;
	return q;
}

void enqueue(struct queue *q, int x){
	if(q->count>=QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n", x);
	else{
		q->last=(q->last+1)%QUEUESIZE;
		q->buff[q->last]=x;
		q->count=q->count+1;
	}
}

int dequeue(struct queue *q){
	int x;
	if(q->count >0 ){
		x=q->buff[q->first];
		q->first=(q->first+1)%QUEUESIZE;
		q->count = q->count - 1;
	}
	return(x);
}

int headq(struct queue *q){
	return (q->buff[q->first]);
}

bool empty_queue(struct queue *q){
	if(q->count <= 0)
		return true;
	else
		return false;
}

void destroy_queue(struct queue *q){
	free(q->buff);
	//free(q);
}

void print_queue(struct queue *q){
	int i, j;

	i=q->first;

	while(i != q->last){
		printf("%d ", q->buff[i]);
		i = (i+1) % QUEUESIZE;
	}

	printf("%2d ", q->buff[i]);//without this line we can not get q->first
	printf("\n");
}

int main(){
	struct queue *q=init_queue();
	enqueue(q, 5);
	enqueue(q, 6);
	enqueue(q, 10);
	enqueue(q, 93);
	enqueue(q, 45);
	print_queue(q);
	printf("%d\n", headq(q));

	printf("%d\n",dequeue(q));
	printf("%d\n",dequeue(q));
	print_queue(q);
	destroy_queue(q);
/*	print_queue(q);
	printf("%d\n", q->count);
	if(empty_queue(q))
		printf("empty\n");
	else
		printf("not empty\n");
*/
	return 0;	
}

/*
//STACK implementation with linked list
struct node{
	int data;
	struct node* next;
};

struct node* init(int data){
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	return nn;
}

void append(struct node **head, int data){
	struct node *new=init(data);
	if(*head==NULL){
		*head=new;
		return;
	}
	new->next=*head;
	*head=new;
}

int top(struct node **head){
	return (*head)->data;
}

void pop(struct node **head){
	if((*head)!=NULL){
		struct node *temp=*head;
		*head=(*head)->next;
		free(temp);
	}
}

void traverse(struct node **head){
	struct node *temp=*head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	struct node *head=NULL;
	append(&head, 76);
	append(&head, 89);
	append(&head, 48);
	append(&head, 32);
	append(&head, 19);
	traverse(&head);
	pop(&head);
	printf("%d\n", top(&head));
	traverse(&head);

	return 0;
}

//STACK implementation with array

struct vector{
	int *buff;
	int buff_size;
	int top;
};

struct vector* init(int size){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->buff_size=size;
	v->top=-1;
	return v;
}

void push(struct vector *v, int data){
	if(v->top < v->buff_size-1){
		v->top+=1;
		v->buff[v->top]=data;
	}
}

int top(struct vector *v){
	return v->buff[v->top];
}

void pop(struct vector *v){
	if(v->top >= 0){
		v->top = v->top - 1;
	}
}

int main(){
	struct vector *v=init(7);
	push(v, 7);
	push(v, 6);
	push(v, 9);
	push(v, 6);
	pop(v);
	for(int i=0; i<=v->top; i++){
		printf("%d ", v->buff[i]);
	}
	printf("\n%d\n", top(v));

	return 0;
}



 //CIRCULAR LINKED LIST WITH CIRCLE ANYWHERE (DOESN'T ACCEPT 
 //THE CASE WITH ONLY 1 ITEM)
struct node{
	int data;
	struct node *next;
};

struct node* create(int data){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	return new;
}

void create_cll(struct node **head, int num_el, int n_cycle_start){
	if(num_el==1){//this part when there is one
	       	      //element in cycle doesn't work
		int data;
		scanf("%d", &data);
		struct node *new=create(data);
		*head=new;
		struct node *temp=*head;
		temp->next=new;
	}
	else{
		for(int i=0; i<num_el; i++){
			int data;
			scanf("%d", &data);
			struct node *new=create(data);
			if(*head==NULL){
				*head=new;
			}
			else{
				struct node *temp=*head;
				while (temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=new;
			}
		}
	}
	int c=0;
	struct node *temp1=*head;
	while(temp1->next!=NULL){
		c+=1;
		if(c==n_cycle_start){
			struct node *temp2=temp1;
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			temp2->next=temp1;
			return;
		}
		temp1=temp1->next;
	}
}

void display_cll(struct node **head, int n_cycle_start){
	//can also be written using the number of nodes 
	//in and outside the cycle
	//IDEA WITH ADDRESSES OF THE NODES(IN ARRAYS) THAT CREATE LOOP
	struct node *temp = *head;
	int c=0;
	while(temp!=NULL){
		c+=1;
		printf("%d ",temp->data);
		if(c==n_cycle_start){
			struct node *temp2=temp;
			while(temp!=NULL){
				temp=temp->next;
				printf("%d ", temp->data);
				if(temp->next==temp2)
					return;
			}
		}
		temp=temp->next;
		
	}
}

bool is_cll(struct node **head){
	struct node *temp=*head;
	if(temp==NULL || temp->next==NULL || temp->next->next==NULL){
		return false;
	}
	struct node *slow=*head;
	struct node *fast=*head;

	slow=slow->next;
	fast=fast->next->next;
	while(true){
		if(fast==NULL){
			return false;
		}
		if(fast==slow || fast->next==slow){
			return true;
		}
		fast=fast->next->next;
		slow=slow->next;
	}
}

int main(){
	struct node *head=NULL;
	create_cll(&head, 9, 5);
	display_cll(&head, 5);
	if(is_cll(&head))
		printf("is circular\n");
	else
		printf("is not circular\n");

	return 0;
}

//LINKED LIST
struct node{
	int data;
	struct node *next;
};

struct node *create(int data){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	return new;
}

void append_to_right(struct node **head, int data){
	struct node *new=create(data);
	if(*head==NULL){
		*head=new;
		return;
	}

	struct node *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new;
}
//void append_to_the_start();

void append_by_pos(struct node **head, int num, int data){
	assert(num>-2);
	struct node *new=create(data);
	if(*head==NULL){
		*head=new;
		return;
	}
	if(num==-1){
		new->next=*head;
		*head=new;
		return;
	}
	struct node *temp=*head;
	while(num>1){
		temp=temp->next;
		num-=1;
	}
	new->next=temp->next;
	temp->next=new;
}

void append_to_the_start(struct node **head, int data){
	struct node *new=create(data);
	if(*head==NULL){
		*head=new;
		return;
	}
	new->next=*head;
	*head=new;
}

void delete_first(struct node **head){
	struct node *temp=*head;
	*head=(*head)->next;
	free(temp);
}

void delete_by_pos(struct node **head, int pos){
	if(*head!=NULL){
		if(pos==1){
			struct node *r_temp=*head;
			*head=(*head)->next;
			free(r_temp);
			return;
		}
		struct node *temp=*head;
		while(pos>2){
			temp=temp->next;
			pos-=1;
		}
		printf("-%d-\n", temp->data);
		struct node *r_temp=temp->next;
		temp->next=temp->next->next;
		free(r_temp);
	}
}

void delete_last(struct node **head){
	struct node *temp=*head;
	if(*head!=NULL){
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		struct node *r_temp=temp->next;
		temp->next=NULL;
		free(r_temp);
	}
}

void delete_by_data(struct node **head, int data){
	if(*head!=NULL){
		if((*head)->data==data){
			struct node *temp=*head;
			*head=(*head)->next;
			free(temp);
			return;
		}
		struct node *temp=*head;
		while (temp->next->data!=data){
			temp=temp->next;
		}
		struct node *r_temp=temp->next;
		temp->next=temp->next->next;
		free(r_temp);
	}
}

void traverse(struct node **head){
	struct node *temp=*head;
	while(temp!=NULL){
		printf("%d\n", temp->data);
		temp=temp->next;
	}
}

void delete_whole_linked_list(struct node **head){
	while (*head!=NULL){
		struct node *temp=*head;
		*head=(*head)->next;
		free(temp);
	}
	if(*head==NULL){
		printf("No linked list!\n");
	}
}

void delete_last_n_nodes(struct node **head, int n){
	struct node *temp=*head;
	int c_n=0;
	while(temp!=NULL){
		temp=temp->next;
		c_n+=1;
	}

	struct node *s_temp=*head;
	int beginning=c_n-n;
	int counter=0;
	while(s_temp->next!=NULL){
		counter+=1;
		if(counter==beginning){
			for(int i=0; i<n; i++){
				struct node *t_temp=s_temp->next;
				s_temp->next=s_temp->next->next;
				free(t_temp);
			}
			break;
		}
		s_temp=s_temp->next;
	}
}

void replace_m_with_n(struct node **head, int m, int n){
	struct node *temp=*head;
	int c=0;
	int c2=0;
	int data_m=0;
	int data_n=0;
	while(temp!=NULL){
		c+=1;
		if(c==m){
			data_m=temp->data;
		}
		if(c==n){
			data_n=temp->data;
		}
		temp=temp->next;
	}
	struct node *temp2=*head;
	while(temp2!=NULL){
		c2+=1;
		if(c2==m){
			temp2->data=data_n;
		}
		if(c2==n){
			temp2->data=data_m;
		}
		temp2=temp2->next;
	}
}

int main(){
	struct node *head =NULL;
	append_to_right(&head, 20);
	append_to_right(&head, 55);
	append_to_right(&head, 37);
	append_to_right(&head, 88);
	append_to_the_start(&head, 99);
	append_to_the_start(&head, 100);
	append_by_pos(&head, 3, 67);
	traverse(&head);
	//delete_first(&head);
	//delete_by_pos(&head, 1);
	//delete_last(&head);
	//delete_by_data(&head, 99);
	//printf("--------------\n");
	//delete_whole_linked_list(&head);
	//delete_last_n_nodes(&head, 4);
	printf("----------------\n");
	replace_m_with_n(&head, 2, 7);
	traverse(&head);

	return 0;
}

//DYNAMIC ARRAY
struct vector{
	int *buff;
	int buff_size;
	int start;
	int pos;
};

struct vector* init(int size){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->buff_size=size;
	v->start=0;
	v->pos=-1;
	return v;
}

void append_to_end_2(struct vector *v, int data){
	assert(v->pos<v->buff_size-1);
	v->pos+=1;
	v->buff[v->pos]=data;
}

void append_to_end(struct vector *v, int data){
	if((v->pos+1)v!=buff_size){//i guess it should be like this
		v->pos+=1;
		v->buff[v->pos]=data;
	}
	else{
		printf("Out of space!");
	}
}

void append_to_mid(struct vector *v, int data, int index){
	int *v2=(int*)malloc(sizeof(int)*v->buff_size);
	if(v->pos < v->buff_size - 1){
		//struct vector *v2=init(v->buff_size);
		for(int i=0; i<index; i++){
			v2[i]=v->buff[i];
		}
		v2[index]=data;
		for(int i=index+1; i<=v->pos+1; i++){
			v2[i]=v->buff[i-1];
		}
		free(v->buff);
		v->buff=v2;
		v->buff_size=v->buff_size;
		v->pos=v->pos+1;
		//free(v->buff);
	}
}

void append_to_start(struct vector *v, int data){
	int *v2=(int*)malloc(sizeof(int)*v->buff_size);
	if(v->pos < v->buff_size - 1){
		v2[0]=data;
		for(int i=0; i<=v->pos; i++){
			v2[i+1]=v->buff[i];
		}
		free(v->buff);
		v->buff=v2;
		v->pos=v->pos+1;
		v->buff_size=v->buff_size;
		v->start=0;
	}
}

int pop_from_end(struct vector *v){//returns last and deletes it
	int num = v->buff[v->pos];
	v->pos=v->pos-1;
	return num;
}

int pop_from_mid_by_index(struct vector *v, int index){
	int num;
	for(int i=0; i<=v->pos; i++){
		if(i==index){
			num=v->buff[i];
			for(int j=i; j<v->pos; j++){
				v->buff[j]=v->buff[j+1];
			}
			v->pos=v->pos-1;
			break;
		}
	}
	return num;
}

int pop_by_data(struct vector *v, int data){
	for(int i=0; i<=v->pos; i++){
		if(v->buff[i]==data){
			for(int j=i; j<v->pos; j++){
				v->buff[j]=v->buff[j+1];
			}
			v->pos=v->pos-1;
			break;
		}
	}
}

int pop_from_start(struct vector *v){
	int num = v->buff[v->start];
	for(int i=0; i<v->pos; i++){
		v->buff[i]=v->buff[i+1];
	}
	v->pos=v->pos-1;

	return num;
}


void print_vector(struct vector *v){
	for(int i=0; i<=v->pos; i++){
		printf("%d ", v->buff[i]);
	}
	printf("\n");
}

void resize_vector(struct vector *v, int new_size){
	int *new_buff=(int*)malloc(sizeof(int)*new_size);
	if(new_size > v->buff_size){
		for(int i=0; i<=v->pos; i++){
			new_buff[i]=v->buff[i];
		}
		free(v->buff);
		v->buff=new_buff;
		v->buff_size=new_size;
		v->pos=v->pos;
		v->start=0;
	}
}

void shift_to_right(struct vector *v, int n){
	int *v_new=(int*)malloc(sizeof(int)*v->buff_size);
	int c=0;
	for(int i=v->pos; i>v->pos-n; i--){
		v_new[c]=v->buff[i];
		c+=1;
	}

	for(int i=0; i<=v->pos-n; i++){
		v_new[i+n]=v->buff[i];
	}

	free(v->buff);
	v->buff=v_new;
}

//Can be written the same way as shift_to_the_right
//void shift_to_left(struct vector *v, int n){
//	return 0;
//}

int main(){
	struct vector *v=init(10);
	printf("Enter array of 5 elements: ");

	for(int i=0; i<5; i++){
		int data;
		scanf("%d", &data);
		append_to_end(v, data);
	}
	printf("With lement at the end: ");
	print_vector(v);

	append_to_mid(v, 34, 3);
	printf("With element at the mid: ");
	print_vector(v);

	append_to_start(v, 77);
	printf("With element at the beginning: ");
	print_vector(v);

	int x=pop_from_end(v);
	printf("popped num from end: %d\n", x);
	printf("With popped from end: ");
	print_vector(v);

	int y=pop_from_start(v);
	printf("popped num from start: %d\n", y);
	printf("With popped from start: ");
	print_vector(v);

	int z=pop_from_mid_by_index(v, 2);
	printf("popped from the mid: %d\n", z);
	printf("With popped from the mid: ");
	print_vector(v);

	resize_vector(v,20);
	printf("%d\n",v->buff_size);

	pop_by_data(v, 8);
	print_vector(v);

	shift_to_right(v, 6);
	print_vector(v);
	free(v->buff);
	free(v);

	return 0;
}
*/
