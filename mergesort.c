/* Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void merge(int arr[], long l, long m, long r)
{
	long i, j, k;
	long n1 = m - l + 1;
	long n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], long l, long r)
{
	if (l < r) {
		
		long m = l + (r - l) / 2;


		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	long i;
	for (i = 0; i < size; i++)
		printf("%d  ", A[i]);
	printf("\n");
}

int main()
{
	struct timeval t0;
    struct timeval t1;
    float elapsed;
	long arr_size,j,num;
	printf("Enter desired size of array: ");
	scanf("%ld",&arr_size);
	int arr[arr_size];
  	srand( (unsigned) time(NULL) * getpid());
	if(arr != NULL)
    {
         for(j = 0; j < num; j++)
         {
             arr[j] = rand()%100;
         }
    }
	printf("Given array is \n");
	printArray(arr, arr_size);
	gettimeofday(&t0, NULL);
	mergeSort(arr, 0, arr_size - 1);
	gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	printf("\nselection sort executed in %f milliseconds.\n", elapsed);
	return 0;
}
