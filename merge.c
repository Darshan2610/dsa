#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[high+1]; // Increase buffer size if needed
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int n;
    srand(time(NULL));
    int it = 5;

    printf("size    time\n");
    for (int i = 1; i <= it; i++)
    {
        n = (2000*(i-1)) + 5000; // Ensure n is at least 1

        int a[n];
        int sz = n - 1;
        for (int j = 0; j < n; j++)
        {
            a[j] = rand() % 100;
        }
        clock_t start = clock();
        mergesort(a, 0, sz);
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d    %f\n", n, time); // Added newline character
    }

    return 0;
}
