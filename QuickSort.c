#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{

    int A[] = {9, 4, 4, 8, 7, 5, 6};
    

    int n;     // Size of the array
    int a = 5; // Number of different sizes to test
    srand(time(NULL));

    printf("input size    time\n");
    for (int i = 0; i < a; i++)
    {
        n = 5000 + ((i+1) * 2000); // Generate random size between 1 and 50

        int A[n];
        for (int j = 0; j < n; j++)
        {
            A[j] = rand() % 100; // Generate random values between 0 and 99
        }

        // Record the start time
        clock_t start_time = clock();
        quickSort(A,0, n-1);
        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("%10d    %.4f sec\n", n, time_taken);
    }

    return 0;
}
