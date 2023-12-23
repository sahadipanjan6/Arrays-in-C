/******************************************************************************

Write a C program to accept an integer array containing 0, 1 and 2 only in 
any manner, and then segregate the same such that they are sorted in 
ascending order.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

void display(int arr[], int size);
void separate012(int arr[], int size);

int main()
{
    int N = 0;
    int index = 0;
    int array[MAXSIZE];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(index=0; index<N; index++)
        scanf("%d", &array[index]);
        
    printf("Original Array: ");
    display(array, N);
        
    // calling the function
    separate012(array, N);
    
    printf("Sorted Array: ");
    display(array, N);

    return 0;
}

// function definition to display the array
void display(int arr[], int size)
{
    int index = 0;
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
    
    printf("\n");
}

// function definition to separate 0s, 1s and 2s
// implemented using the Dutch National Flag algorithm
void separate012(int arr[], int size)
{
    int start = 0;
    int mid = 0; 
    int end = size - 1;
    
    while(mid < end)
    {
        switch(arr[mid])
        {
            case 0:
                    // swapping arr[start] and arr[mid]
                    arr[start] ^= arr[mid];
                    arr[mid] ^= arr[start];
                    arr[start] ^= arr[mid];
                    
                    // increasing the pointer values
                    start++;
                    mid++;
                    
                    break;
            
            case 1:
                    // moving mid pointer ahead by 1 only
                    mid++;
                    break;
                    
            case 2:
                    // swapping arr[mid] and arr[end]
                    arr[mid] ^= arr[end];
                    arr[end] ^= arr[mid];
                    arr[mid] ^= arr[end];
                    
                    // decreasing the end pointer by 1
                    end--;
                    break;
        }
    }
}
