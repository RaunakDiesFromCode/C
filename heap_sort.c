#include <stdio.h>

void heapify(int arr[], int n, int i)
{
  int temp, maximum, left_index, right_index;
  maximum = i;
  right_index = 2 * i + 2;
  left_index = 2 * i + 1;

  if (left_index < n && arr[left_index] > arr[maximum])
    maximum = left_index;

  if (right_index < n && arr[right_index] > arr[maximum])
    maximum = right_index;

  if (maximum != i)
  {
    temp = arr[i];
    arr[i] = arr[maximum];
    arr[maximum] = temp;
    heapify(arr, n, maximum);
  }
}

void heapsort(int arr[], int n)
{
  int i, temp;

  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (i = n - 1; i > 0; i--)
  {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
  heapsort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n__________________________\n");
  printf("Time complexity: O(n log n)\n");
  printf("Space complexity: O(1)\n");

  return 0;
}
