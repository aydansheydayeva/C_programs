#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void quick_sort(int buff[64]/* int *buff  */, int low, int high){
	int i, j, pivot, temp;

	if(low<high){
		i=low;
		j=high;
		pivot=(high+low)/2;//low or high
		while(i<j){
			while(buff[i]<=buff[pivot]) //buff[i]<buff[pivot];
				i+=1;
			while(buff[j]>buff[pivot])
				j-=1;
			if(i<j){
				//temp=buff[i];
				//buff[i]=buff[j];
				//buff[j]=temp;
				swap(&buff[i],&buff[j]);
			}
		}
		
		//temp=buff[j];
		//buff[j]=buff[pivot];
		//buff[pivot]=temp;
		swap(&buff[j],&buff[pivot]);
		
	
		quick_sort(buff, low, j-1);//instead of j used pivot
		quick_sort(buff, j+1, high);
	}

}

void bubble_sort(int buff[64]/*  int *buff  */, int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(buff[j]>buff[j+1]){
				swap(&buff[j],&buff[j+1]);
			}
		}
	}
}

int main(){
	int buff[64]={2, 4, 8, 67, 89, 45, 43, 0, 99};	
	//quick_sort(buff, 0, 8);
	bubble_sort(buff, 9);
	for(int i=0; i<9; i++){
		printf("%d ", buff[i]);
	}
	printf("\n");
	return 0;
}
