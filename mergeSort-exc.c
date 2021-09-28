/*Given an array A on size N, you need to find the number of ordered pairs such that i<j  and a[i]>a[j].

Input:
First line contains one integer, N, size of array.
Second line contains N space separated integers denoting the elements of the array A.

Output:
Print the number of ordered pairs  such that i<j  and a[i]>a[j].*/


#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
long long int merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	long long int counter=0;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L= malloc(sizeof(int)*n1);
    int *R= malloc(sizeof(int)*n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
           
		}
		else {
			arr[k] = R[j];
			j++;
            counter += n1-i;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
        
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
    return counter;
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
long long int mergeSort(int arr[], int l, int r)
{
    long long int counter=0;
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		counter += mergeSort(arr, l, m);
		counter += mergeSort(arr, m + 1, r);

		counter += merge(arr, l, m, r);
	}
    return counter;
}


int main(void){

    int n;
	long long int counter;
    scanf("%d", &n);

    int *arr;
    arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    counter = mergeSort(arr, 0, n-1);

    printf("%lld", counter);


    return 0;
}
