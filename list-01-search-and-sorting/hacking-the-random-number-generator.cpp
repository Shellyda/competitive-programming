/*HACKRNDM - Hacking the random number generator

Algorithms used:
- Binary Search and MergeSort

You recently wrote a random number generator code for a web application and now you notice that some cracker has cracked it. It now gives numbers at a difference of some given value k more predominantly. You being a hacker decide to write a code that will take in n numbers as input and a value k and find the total number of pairs of numbers whose absolute difference is equal to k, in order to assist you in your random number generator testing.

NOTE: All values fit in the range of a signed integer, n, k>=1
Input

1st line contains n & k.
2nd line contains n numbers of the set. All the n numbers are assured to be distinct.

(Edited: n <= 10^5)
Output

One integer saying the no of pairs of numbers that have a diff k.
Example

Input:
5 2
1 5 3 4 2

Output:
3
*/

#include <iostream>
using namespace std;

void merge(int *array, int beginIndex, int middleIndex, int endIndex)
{
  int leftSize, rightSize, *leftArray, *rightArray;

  leftSize = middleIndex - beginIndex + 1;
  rightSize = endIndex - middleIndex;

  leftArray = new int[leftSize];
  rightArray = new int[rightSize];

  for (int i = 0; i < leftSize; i++)
  {
    leftArray[i] = array[beginIndex + i];
  }

  for (int j = 0; j < rightSize; j++)
  {
    rightArray[j] = array[middleIndex + j + 1];
  }

  int leftIndex = 0, rightIndex = 0, mergedArrayIndex = beginIndex;

  while (leftIndex < leftSize && rightIndex < rightSize)
  {
    if (leftArray[leftIndex] <= rightArray[rightIndex])
    {
      array[mergedArrayIndex] = leftArray[leftIndex];

      leftIndex++;
    }
    else
    {
      array[mergedArrayIndex] = rightArray[rightIndex];

      rightIndex++;
    }

    mergedArrayIndex++;
  }

  while (leftIndex < leftSize)
  {
    array[mergedArrayIndex] = leftArray[leftIndex];

    leftIndex++;
    mergedArrayIndex++;
  }

  while (rightIndex < rightSize)
  {
    array[mergedArrayIndex] = rightArray[rightIndex];

    rightIndex++;
    mergedArrayIndex++;
  }

  delete[] leftArray;
  delete[] rightArray;
}

void mergeSort(int *array, int beginIndex, int endIndex)
{
  if (beginIndex < endIndex)
  {
    int middleIndex = beginIndex + (endIndex - beginIndex) / 2;

    mergeSort(array, beginIndex, middleIndex);
    mergeSort(array, middleIndex + 1, endIndex);
    merge(array, beginIndex, middleIndex, endIndex);
  }
}

int binarySearch(int *sortedArray, int arraySize, int searchKey)
{
  int beginIndex = 0;
  int endIndex = arraySize - 1;

  while (beginIndex <= endIndex)
  {
    int middleIndex = (beginIndex + endIndex) / 2;

    if (searchKey == sortedArray[middleIndex])
    {
      return middleIndex;
    }
    else if (searchKey < sortedArray[middleIndex])
    {
      endIndex = middleIndex - 1;
    }
    else
    {
      beginIndex = middleIndex + 1;
    }
  }

  return -1;
}

int *setNumberArray(int arraySize)
{
  int *array = (int *)malloc(arraySize * sizeof(int));

  for (int i = 0; i < arraySize; i++)
  {
    cin >> array[i];
  }

  return array;
}

int main(void)
{
  int arraySize, differenceToSearch, searchKey, result = 0, *array;

  cin >> arraySize >> differenceToSearch;

  array = setNumberArray(arraySize);

  mergeSort(array, 0, arraySize - 1);

  for (int i = 0; i < arraySize; i++)
  {
    searchKey = array[i] + differenceToSearch;

    int index = binarySearch(array, arraySize, searchKey);

    if (index != -1)
    {
      result++;
    }
  }

  cout << result;

  delete[] array;

  return 0;
}