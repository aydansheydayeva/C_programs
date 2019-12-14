#include<stdio.h>
#include<stdlib.h>

void s_l(int *buff, int n, int c){
	for(int i=0; i<n; i++){
		int x=buff[0];
		for(int j=0; j<c-1; j++){
			buff[j]=buff[j+1];
		}
		buff[c-1]=x;
	}
}

int main(){
	int buff[]={1,2,3,4,5,6,7,8,9};

	s_l(buff, 3, 9);
	for(int i=0; i<9; i++){
		printf("%d ", buff[i]);
	}

	return 0;
}
