#include<stdio.h>
#include<stdlib.h>

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
	if((*head)==NULL){
		*head=new;
		return;
	}
	struct node *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new;
}

void traverse(struct node **head){
	struct node *temp=*head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
}

int node_num(struct node **head){
	struct node *temp=*head;
	int num=0;
	while(temp!=NULL){
		num+=1;
		temp=temp->next;
	}
	return num-1;
}

int data_node(struct node **head, int pos){
	int data_n=0;
	struct node *temp=*head;
	if((*head)!=NULL){
		while(pos>0){
			temp=temp->next;
			pos-=1;
		}
		data_n=temp->data;
	}
	return data_n;
	
}

void swap(struct node **head, int f, int l){
	struct node *temp=*head;
	struct node *temp1;
	struct node *temp2;

	while(temp!=NULL){
		if(f==0)
			temp1=temp;
		if(l==0)
			temp2=temp;
		f-=1;
		l-=1;
		temp=temp->next;
	}
	int d=temp1->data;
	temp1->data=temp2->data;
	temp2->data=d;
}

void quick_sort(struct node **head, int first, int last){
	if(first<last){
		int f=first;
		int l=last;
		int pivot=first;
		while(f<=l){
			int f_data=data_node(head, f);
			int l_data=data_node(head, l);
			int p_data=data_node(head, pivot);
			if(f_data<=p_data)
				f+=1;
			if(l_data>p_data)
				l-=1;
			if(f<l)
				swap(head, f, l);
		}
		swap(head, l, pivot);
		quick_sort(head, first, l-1);
		quick_sort(head, l+1, last);
	}
}

int main(){
	struct node *head=NULL;
	append(&head, 56);
	append(&head, 98);
	append(&head, 34);
	append(&head, 12);
	append(&head, 30);
	append(&head, 72);
	append(&head, 11);
	append(&head, 28);
	append(&head, 22);

	traverse(&head);
	printf("\n");
//	swap(&head, 6, 3);
//	traverse(&head);
	int num=node_num(&head);//==length-1;
//	printf("%d\n", num);
//	int x=data_node(&head, 4, num);
//	printf("%d\n", x);
	quick_sort(&head, 0, num);
	traverse(&head);
	printf("\n");

	return 0;
}
