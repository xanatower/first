#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
int main(int argc, char** argv){
	int size;
	//char *set;
	//set = argv[2];
	//printf("set = %s\n",set );
	//printf("set = %c\n",set[0]);
	//printf("set = %c\n",set[1]);
	//printf("set = %c\n",set[2]);
	size = atoi(argv[1]);
	printf("size = %d\n", size);
	int** twodmatrix;
	int matrixsize = (int)pow(2,size);
	twodmatrix = (int**)malloc(matrixsize*sizeof(int*));

	if(twodmatrix == NULL){
		printf("something wrong\n");

	}
	assert(twodmatrix != NULL);
	int i,j;
	for(i = 0; i < matrixsize;i++){
		twodmatrix[i] = (int*)malloc(size* sizeof(int));
		assert(twodmatrix[i] != NULL);
		for(j = 0;j< size;j++){
			if(i & (1<<j)){
				printf("%d", 1);
			} else {
				printf("%d", 0);
			}

		}
		printf("\n");
	}

	free(twodmatrix);
	return 0;
}