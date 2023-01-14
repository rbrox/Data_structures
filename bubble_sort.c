  #include<stdio.h>

int* bubble_sort(int* arr, int size)
{
  for(int i = 0; i < size - 1; ++i)
  {
    for(int j = i; j < size - 1; ++j)
    {
      if (arr[j] >= arr[j + 1])
      {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp; 
      }
    }
  }

  return arr;
}


int* bubble_better(int* arr, int n)
{
  int flag = 10;

  while (flag != 0)
  {
    flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        ++flag;
      }
    }
  }
  return arr;
}  


void main()
{
  //printf("\nPrevious\n");
  int arr[] = {23,4556,1234,45,23,67,764};
  /*for (int i = 0; i < 7; ++i)
  {
    printf("%d\n", arr[i]);
  }
  */
  
  int* ptr = arr;
  ptr = bubble_better(arr, 7);
  printf("\n\n\nAfter\n");
  for (int i = 0; i < 7; ++i)
  {
    printf("%d\n", arr[i]);
  }

}