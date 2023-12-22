/******************************************************************************

Given an array of size N-1 such that it only contains distinct integers in the
range of 1 to N. Find the missing element.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

int get_min(int arr[], int size);
int get_max(int arr[], int size);
int array_sum(int arr[], int size);

int main()
{
    int N = 0;
    int index, number = 0;
    int normal_sum = 0;
    int array[MAXSIZE];
    
    printf("Enter value of N: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(index=0; index<N; index++)
        scanf("%d", &array[index]);
    
    // finding summation of all natural numbers in a given range
    for(number=get_min(array, N); number<=get_max(array, N); number++)
        normal_sum += number;
    
    // displaying the missing number
    printf("Missing Element = %d\n", (normal_sum - array_sum(array, N)));
    
    return 0;
}

// function definition to find out the Minimum element of an array 
int get_min(int arr[], int size)
{
    int min_value = 65535;
    int index = 0;
    
    for(index=0; index<size; index++)
    {
        if(arr[index] <= min_value)
            min_value = arr[index];
    }
    
    return min_value;
}

// function definition to find out the Maximum element of an array
int get_max(int arr[], int size)
{
    int max_value = -65536;
    int index = 0;
    
    for(index=0; index<size; index++)
    {
        if(arr[index] >= max_value)
            max_value = arr[index];
    }
    
    return max_value;
}

// function definition to find out summation of all elements of an array
int array_sum(int arr[], int size)
{
    int sum = 0;
    int index = 0;
    
    for(index=0; index<size; index++)
        sum += arr[index];
    
    return sum;
}
