#include<stdio.h>
#include<stdlib.h>
int CountSplitInv(int *A, int *L, int leftCount, int *R, int rightCount){
	int i,j,k;

	i = 0; j = 0; k = 0;

	long long inver;

	inver = 0;

	while(i <leftCount && j < rightCount){
		if(L[i] < R[j]){
			A[k] = L[i];
			i = i + 1;
			k = k + 1;
		} else {
			inver = inver + leftCount - i ;
			A[k] = R[j];
			j = j + 1;
			k = k + 1;
			printf("number of inver: %lld\n", inver);
		}
	}
	while(i <leftCount){
		A[k] = L[i];
		k += 1;
		i += 1;
	}
	while(j <rightCount){
		A[k] = R[j];
		k += 1;
		j += 1;
	}
	return inver;
}

int sortncount (int *A, int length){
	int mid, i, *L, *R;
	long long x,y,z;
	if(length < 2){
		return 0;
	}
	mid = length/2;
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((length-mid)*sizeof(int));

	for(i = 0;i < mid; i++){
		L[i] = A[i];
	}
	for(i = mid;i < length; i++){
		R[i-mid] = A[i];
	}
	printf("\n\n");
	x = sortncount(L,mid);
	printf("number of inverx: %lld\n", x);
	y = sortncount(R,length-mid);
	printf("number of invery: %lld\n", y);
	z = CountSplitInv(A,L,mid,R,length-mid);
	free(L);
	free(R);
	return x + y + z;
	
}

int main(){
	FILE *myFile;
	int length = 100000;
	myFile = fopen("inputs.txt","r");//r: opens for reading
	// read file into array

	int A[length];
	int i;

	for(i = 0; i < length; i ++){
		fscanf(myFile,"%d",&A[i]);
	}
	/*for(i = 0; i < 100; i ++){
		printf("Number is %d\n\n", numberArray[i]);
	}*/
	fclose(myFile);

	long long numOfInver;
	numOfInver = sortncount(A,length);
	printf("number of inversions = %lld \n",numOfInver);
	return 0;
}





