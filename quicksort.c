/* Quick Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}


void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  
  int i = (low - 1);


  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      
      i++;

      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) {
    

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}


void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
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
             arr[j] = rand()%1000;
         }
    }
	printf("Given array is \n");
	printArray(arr, arr_size);
	gettimeofday(&t0, NULL);
	quickSort(arr, 0, arr_size - 1);
	gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	printf("\nquick sort executed in %f milliseconds.\n", elapsed);
	return 0;
}
