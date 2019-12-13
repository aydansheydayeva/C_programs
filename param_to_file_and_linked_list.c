#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char *data;
	struct node *next;
};

struct node* init(char *strng){
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=(char*)malloc(sizeof(char)*(strlen(strng)-1));
	strcpy(nn->data,strng);
	nn->next=NULL;
	return nn;
}

void append(struct node **head, char *strng){
	struct node *new=init(strng);
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

void traverse();

void from_file_to_list(char *strng){
	struct node *head=NULL;
	FILE *f=fopen(strng, "a+");
	char buff[32];
	while(fgets(buff, 32, f)!=NULL){
		append(&head, buff);
		//printf("->%s\n", buff);
	}
	fclose(f);
	remove(strng);
	traverse(&head);
}

void traverse(struct node **head){
	struct node *temp=*head;
	while(temp!=NULL){
		printf("%s->",temp->data);
		temp=temp->next;
	}
}

void pass_to_file(char *strng){
	FILE *f=fopen("./ARGV_CONTENT.txt", "a+");
	fputs(strng, f);
	fputs("\n", f);
	fclose(f);
}

int main(int argc, char *argv[]){

	for(int i=1; i<argc; i++){
		pass_to_file(argv[i]);
	}

	from_file_to_list("./ARGV_CONTENT.txt");

	return 0;
}
