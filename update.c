#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* create(int data){
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	return nn;
}

void append(struct node **head, int item){
	struct node* temp=*head;
	struct node *new=create(item);
	if (*head==NULL){
		*head=new;
		return;
	}
	while (temp->next !=NULL){
		temp=temp->next;
	}

	temp->next=new;
	new->next=NULL;
}

void traverse(struct node *head){
	struct node *temp=head;
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void update(struct node **head, int data_old, int data_new){
	struct node* temp=*head;
	struct node* prev=*head;
	if ((*head)->data==data_old){
		temp->next->data=data_new;
		return;
	}

	while(temp->data != data_old){
		prev=prev->next;
		temp=temp->next;
		if (prev->next->data==data_old)
			break;
		if (prev->next->next->next==NULL){
			prev->next->data=data_new;
			return;
		}
	}
	temp=temp->next;
	prev->data=data_new;
	temp->next->data=data_new;

}

int main(){
	struct node* head=NULL;
	int a;
	int n;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a);
		append(&head,a);
	}
	printf("\n");
	traverse(head);
	int x,y;
	scanf("%d", &x);
	scanf("%d", &y);
	printf("\n");
	update(&head,x,y);
	traverse(head);
}
