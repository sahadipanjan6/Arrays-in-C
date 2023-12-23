/******************************************************************************

Given an array a of size N which contains elements from 0 to N-1, you need to
find all the elements occurring more than once in the given array.
Return the answer in ascending order.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

int findMax(int arr[], int size);
void display(int arr[], int size);

int main()
{
    int N = 0;
    int f_size = 0;
    int index = 0;
    int array[MAXSIZE];
    int frequencies[100];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(index=0; index<N; index++)
        scanf("%d", &array[index]);
        
    printf("Original Array: ");
    display(array, N);
    
    f_size = findMax(array, N) + 1;
    
    // initialising all elements of frequencies to 0
    for(index=0; index<100; index++)
        frequencies[index] = 0;
    
    // traversing the original array and finding the frequencies
    for(index=0; index<N; index++)
        frequencies[array[index]]++;
    
    printf("\n");
    for(index=0; index<f_size; index++)
        printf("Frequency of %d = %d\n", index, frequencies[index]);

    return 0;
}


// function definition to find the maximum element from an array
int findMax(int arr[], int size)
{
    int max_element = -65536;
    int index = 0;
    
    for(index=0; index<size; index++)
    {
        if(arr[index] >= max_element)
            max_element = arr[index];
    }
    
    return max_element;
}

// function definition to display an array
void display(int arr[], int size)
{
    int index = 0;
    
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
    
    printf("\n");
}
