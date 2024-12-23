#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // Pivot element
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {      // If the current element is smaller than the pivot
      i++; // Increment the index of the smaller element
      // Swap arr[i] and arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // Swap arr[i + 1] and arr[high] (or pivot)
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return (i + 1);
}

// Function to perform Quick Sort
void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);  // Sort elements before partition
    quick_sort(arr, pi + 1, high); // Sort elements after partition
  }
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = 7;

  printf("Original array: \n");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }

  // Perform Quick Sort
  quick_sort(arr, 0, len - 1);

  printf("\nSorted array: \n");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n__________________________\n");
  printf("Time complexity: O(n log n)\n");
  printf("Space complexity: O(log n)\n");

  return 0;
}
