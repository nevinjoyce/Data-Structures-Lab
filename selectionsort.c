/*Selection Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(void)
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    long min,num,i,j;
    printf("\nEnter desired size of array: ");
    scanf("%ld",&num);
    int data[num];
    srand( (unsigned) time(NULL) * getpid());
    
    int temp;

    if(data != NULL)
    {
         for(j = 0; j < num; j++)
         {
             data[j] = rand()%100;
         }
    }
    printf("\nprinting unsorted random data...\n");
    for(i=0;i<num;i++)
    	printf("%d  ",data[i]);
    gettimeofday(&t0, NULL);
	for(i=0;i<num-1;i++)
	{
		min=i;
		for(j=i+1;j<num;j++)
		{
    		if(data[j]<data[min])
    			min=j;
    	}
    	if(min!=i)
    	{
    		temp=data[i];
    		data[i]=data[min];
    		data[min]=temp;
    	}
    }
    gettimeofday(&t1, NULL);
     printf("\nprinting sorted random data...\n");
    for(i=0;i<num;i++)
    	printf("%d  ",data[i]);

    elapsed = timedifference_msec(t0, t1);

   printf("\nselection sort executed in %f milliseconds.\n", elapsed);
 
   return 0;
}
