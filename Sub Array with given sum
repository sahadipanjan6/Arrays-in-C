/******************************************************************************

Given an unsorted array A of size N that contains only non negative integers,
find a continuous sub-array that adds to a given number S.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 50

int main()
{
    int N = 0;
    int S = 0;
    int i, j, k = 0;
    int flag = 0;
    int index = 0;
    int sum = 0;
    int array[MAXSIZE];
    
    printf("Enter value of N: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(index=0; index<N; index++)
        scanf("%d", &array[index]);
    
    printf("Enter value of S: ");
    scanf("%d", &S);
    
    // finding contiguous sub-array
    // starting point
    for(i=0; i<N; i++)
    {
        // ending point
        for(j=i; j<N; j++)
        {
            sum = 0;
            
            // taking the integers between starting and ending points
            for(k=i; k<=j; k++)
                sum += array[k];
            
            if(sum == S)
            {
                flag = 1;
                printf("Sub-array found with Sum = %d: [Start = %d, End = %d]\n", S, i, j);
            }
        }
    }
    
    if(flag == 0)
        printf("Sub-array with Sum = %d does not exist\n", S);
        
    return 0;
}
