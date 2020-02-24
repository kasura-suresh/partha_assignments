#include<stdio.h>
#include<malloc.h>
//---Create Matrix Function---
int **create_matrix(int row,int col){
	int i,**m;
	m = (int **)malloc(sizeof(int)*row);
	for(i=0;i<row;i++){
		m[i] = malloc(sizeof(int)*col);
	}
	return m;
}
//---Read Matrix Function---
int **read_matrix(int row ,int col){
	int i,j;
	int **m1 = create_matrix(row,col);
	printf("Now enter the elements one by one:\n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&m1[i][j]);
		}
	}
	return m1;
}
//---Add Matrix Function---
int **add_matrix(int **a1,int **a2,int row,int col){
	int **res,i,j;
	res = create_matrix(row,col);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			res[i][j] = a1[i][j] + a2[i][j];
		}
	}
	return res;
}
//---Print Matrix Function---
void print_array(int row,int col,int **a){
	int i ,j;
	for(i=0;i<row;i++){
		for(j = 0; j<col;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
//---Main Function---
int main()
{
	int row,col,**arr1,**arr2,**result;
	printf("Enter the row and col:\n");
	scanf("%d%d",&row,&col);
	if(row!=col){
		printf("Addition is not possible\n");
	}
	else{
		printf("Enter the first matrix:\n");
		arr1 = read_matrix(row,col);
		printf("Enter the second matrix:\n");
		arr2 = read_matrix(row,col);
		printf("First Martix:\n");
		print_array(row,col,arr1);
		printf("Second Martix:\n");
		print_array(row,col,arr2);
		result = add_matrix(arr1,arr2,row,col);
		printf("Result Matrix is:\n");
		print_array(row,col,result);
	}
return 0;
}
