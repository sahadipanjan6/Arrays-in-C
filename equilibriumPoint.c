/******************************************************************************

Given an array A of n positive numbers. The task is to find the first
equilibrium point in an array. Equilibrium point in an array is an index
(or position) such that the sum of all elements before that index is same as
sum of elements after it.

*******************************************************************************/
#include <stdio.h>
#define MAXSIZE 20

void display(int arr[], int size);
int getSum(int arr[], int start, int stop);
int findEquilibrium(int arr[], int size);

int main()
{
    
    int N = 0;
    int index = 0;
    int eq = 0;
    int array[MAXSIZE];
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d elements of the array...\n", N);
    for(index=0; index<N; index++)
        scanf("%d", &array[index]);
        
    // getting the equilibrium point
    eq = findEquilibrium(array, N);
    if(eq == -1)
        printf("No Equilibrium Points found\n");
    else
        printf("Found Equilibrium Point = %d\n", eq);

    return 0;
}

// function definition to display an array
void display(int arr[], int size)
{
    int index = 0;
    
    for(index=0; index<size; index++)
        printf("%d ", arr[index]);
    
    printf("\n");
}

// function definition to find out summation of elements of a sub-array
int getSum(int arr[], int start, int stop)
{
    int sum = 0;
    int index = 0;
    
    for(index=start; index<=stop; index++)
        sum += arr[index];
        
    return sum;
}

// function definition to find out the equilibrium point(if exists) in an array
int findEquilibrium(int arr[], int size)
{
    int l_sum, r_sum = 0;
    int index = 0;
    
    for(index=0; index<size; index++)
    {
        // for first index position
        if(index == 0)
        {
            // setting the left sub-array sum = zero
            l_sum = 0;
            
            // finding summation of right sub-array
            r_sum = getSum(arr, index+1, size-1);
            
            // checking if both summations are same or not
            if(l_sum == r_sum)
                return index;
        }
        
        // for last index position
        else if(index == size-1)
        {
            // setting the right sub-array sum = zero
            r_sum = 0;
            
            // finding summation of left sub-array
            l_sum = getSum(arr, 0, index-1);
            
            // checking
            if(l_sum == r_sum)
                return index;
        }
        
        // for intermediate positions
        else
        {
            l_sum = getSum(arr, 0, index-1);
            r_sum = getSum(arr, index+1, size-1);
            
            if(l_sum == r_sum)
                return index;
        }
    }
    
    return -1;
}
