// Program - Bubble Sort
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
   
   long *data;
   long num=1000,i,j;
   data = (long *)malloc(sizeof(long)*num);
   
    srand( (unsigned) time(NULL) * getpid());
    
    int x,y,temp;

    if(data != NULL)
    {
        for(j = 0; j < num; j++)
        {
            data[j] = rand()%100;
        }
    }
    printf("\nprinting unsorted random data...\n");
    for(i=0;i<num;i++)
    	printf("%ld  ",data[i]);
   gettimeofday(&t0, NULL);

    for(x = 0; x < num - 1; x++)
    {       
        for(y = 0; y < num - x - 1; y++)
        {          
            if(data[y] > data[y + 1])
            {               
                temp = data[y];
                data[y] = data[y + 1];
                data[y + 1] = temp;
            }
        }
    }
    
   gettimeofday(&t1, NULL);
	printf("\nprinting sorted data...\n");
    for(i=0;i<num;i++)
    	printf("%ld  ",data[i]);
   elapsed = timedifference_msec(t0, t1);

   printf("\nBubble sort executed in %f milliseconds.\n", elapsed);

   return 0;
}
