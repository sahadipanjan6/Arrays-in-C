/******************************************************************************

Given an array A of N elements. Find the majority element in the array.
A majority element in an array A of size N is an element that appears strictly
more than N/2 times in the array.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

void display(int arr[], int size);
int findMax(int arr[], int size);

int main()
{
    int N = 0;
    int f_size = 0;
    int i, j = 0;
    int flag = 0;
    int array[MAXSIZE];
    int frequencies[100];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(i=0; i<N; i++)
        scanf("%d", &array[i]);
    
    // setting the size of the frequencies array
    f_size = findMax(array, N) + 1;
    
    // initialising each element of frequenies array to zero
    for(i=0; i<f_size; i++)
        frequencies[i] = 0;
    
    printf("Original Array: ");
    display(array, N);
    
    // finding the frequencies of each element
    for(i=0; i<N; i++)
        frequencies[array[i]]++;
        
    // displaying the Majority element
    printf("\nMajority Element = ");
    for(i=0; i<f_size; i++)
    {
        if(frequencies[i] > (N/2))
            printf("%d ", i);
    }
    
    return 0;
}


// function definition to display an array
void display(int arr[], int size)
{
    int index = 0;
    
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
}

// function definition to find the maximum element in an array
int findMax(int arr[], int size)
{
    int index = 0;
    int max_element = -65536;
    
    for(index=0; index<size; index++)
    {
        if(arr[index] >= max_element)
            max_element = arr[index];
    }
    
    return max_element;
}
