/******************************************************************************

Given an array A of positive integers. Your task is to find the leaders in the
array. An element of array is a leader if it is greater than or equal to all
the elements to its right side. The rightmost element is always a leader. 

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

void display(int arr[], int size);

int main()
{
    int N = 0;
    int i, j = 0;
    int flag = 0;
    int element = 0;
    int array[MAXSIZE];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(i=0; i<N; i++)
        scanf("%d", &array[i]);
        
    printf("Original Array: ");
    display(array, N);
    
    printf("\n");
    printf("Leaders of array: %d ", array[N-1]);
    
    // finding the leaders of the array
    for(i=0; i<N-1; i++)
    {
        element = array[i];
        flag = 1;
        
        for(j=i+1; j<N; j++)
        {
            if(element < array[j])
            {
                flag = 0;
                break;
            }
            else
                continue;
        }
        
        if(flag == 1)
            printf("%d ", element);
    }
    
    printf("\n");

    return 0;
}


// function definition to display an array
void display(int arr[], int size)
{
    int index = 0;
    
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
}

