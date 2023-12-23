/******************************************************************************

Given an array arr[] and an integer K where K is smaller than size of array,
the task is to find the Kth smallest element in the given array. It is given
that all array elements are distinct.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

void display(int arr[], int size);
int findMin(int arr[], int size);

int main()
{
    int N, K, copy = 0;
    int i, j = 0;
    int smallest = 0;
    int array[MAXSIZE];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(i=0; i<N; i++)
        scanf("%d", &array[i]);
    
    printf("Enter value of K: ");
    scanf("%d", &K);
    copy = K;
    
    // finding the K'th smallest element
    for(i=0; i<N; i++)
    {
        if(K != 0)
        {
            smallest = findMin(array, N);
            K--;
        }
        else
            break;
    }
    
    printf("%d'th Smallest Element = %d\n", copy, smallest);
    
    return 0;
}


// function definition to display an array
void display(int arr[], int size)
{
    int index = 0;
    
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
}

// function definition to find the minimum element in an array
int findMin(int arr[], int size)
{
    int index = 0;
    int min_index = 0;
    int min_element = 65535;
    
    for(index=0; index<size; index++)
    {
        if((arr[index] >= 0) && (arr[index] <= min_element))
        {
            min_index = index;
            min_element = arr[index];
        }
    }
    
    // changing the min_indexed element to -1
    arr[min_index] = -1;
    
    return min_element;
}
