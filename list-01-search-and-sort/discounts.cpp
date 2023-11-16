/*
https://codeforces.com/problemset/problem/1132/B
Discounts

Algorithms used:
- MergeSort

You came to a local shop and want to buy some chocolate bars. There are 𝑛 bars in the shop,
𝑖-th of them costs 𝑎𝑖 coins (and you want to buy all of them).

You have 𝑚 different coupons that allow you to buy chocolate bars. 𝑖-th coupon allows you to buy 𝑞𝑖 chocolate bars
while you have to pay only for the 𝑞𝑖−1 most expensive ones (so, the cheapest bar of those 𝑞𝑖 bars is for free).

You can use only one coupon; if you use coupon 𝑖, you have to choose 𝑞𝑖 bars and buy them using the coupon,
and buy all the remaining 𝑛−𝑞𝑖 bars without any discounts.

To decide which coupon to choose, you want to know what will be the minimum total amount of money
you have to pay if you use one of the coupons optimally.

Input
The first line contains one integer 𝑛(2 ≤ 𝑛≤ 3⋅10ˆ5) — the number of chocolate bars in the shop.

The second line contains 𝑛 integers 𝑎1, 𝑎2, ..., 𝑎𝑛 (1 ≤ 𝑎𝑖 ≤ 10ˆ9), where 𝑎𝑖 is the cost of 𝑖-th chocolate bar.

The third line contains one integer 𝑚 (1 ≤ 𝑚 ≤ 𝑛−1) — the number of coupons you have.

The fourth line contains 𝑚 integers 𝑞1, 𝑞2, ..., 𝑞𝑚 (2 ≤ 𝑞𝑖 ≤ 𝑛), where 𝑞𝑖 is the number of chocolate bars
you have to buy using 𝑖-th coupon so that the least expensive of them will be for free.
All values of 𝑞𝑖 are pairwise distinct.

Output
Print 𝑚 integers, 𝑖-th of them should be the minimum amount of money you have to pay if you buy 𝑞𝑖 bars
with 𝑖-th coupon, and all the remaining bars one by one for their full price.

Sample 1
Input
7
7 1 3 1 4 10 8
2
3 4

Output
27
30

Note
Consider the first example.

If we use the first coupon, we may choose chocolate bars having indices 1, 6 and 7, and we pay 18 coins
for them and 9 coins for all other bars.

If we use the second coupon, we may choose chocolate bars having indices 1, 5, 6 and 7, and we pay 25 coins
for them and 5 coins for all other bars.
*/

#include <iostream>
using namespace std;

void merge(long long *array, long long beginIndex, long long middleIndex, long long endIndex)
{
  long long leftSize, rightSize, *leftArray, *rightArray;

  leftSize = middleIndex - beginIndex + 1;
  rightSize = endIndex - middleIndex;

  leftArray = new long long[leftSize];
  rightArray = new long long[rightSize];

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

void mergeSort(long long *array, long long beginIndex, long long endIndex)
{
  if (beginIndex < endIndex)
  {
    long long middleIndex = beginIndex + (endIndex - beginIndex) / 2;

    mergeSort(array, beginIndex, middleIndex);
    mergeSort(array, middleIndex + 1, endIndex);
    merge(array, beginIndex, middleIndex, endIndex);
  }
}

void populateArray(long long *array, long long arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cin >> array[i];
  }
}

long long setTotalCost(long long *costsNumbersArray, long long arraySize)
{
  long long total = 0;

  for (int i = 0; i < arraySize; i++)
  {
    total += costsNumbersArray[i];
  }

  return total;
}

int main(void)
{
  long long numberOfBars,
      *costsOfBarsArray,
      *barsNeedToBuyArray,
      numberOfCoupons,
      totalCost;

  cin >> numberOfBars;
  costsOfBarsArray = new long long[numberOfBars];
  populateArray(costsOfBarsArray, numberOfBars);

  mergeSort(costsOfBarsArray, 0, numberOfBars - 1);

  totalCost = setTotalCost(costsOfBarsArray, numberOfBars);

  cin >> numberOfCoupons;
  barsNeedToBuyArray = new long long[numberOfCoupons];
  populateArray(barsNeedToBuyArray, numberOfCoupons);

  for (int i = 0; i < numberOfCoupons; i++)
  {
    long long currentBarToBuyIndex = numberOfBars - barsNeedToBuyArray[i];

    cout << totalCost - costsOfBarsArray[currentBarToBuyIndex] << endl;
  }

  delete[] costsOfBarsArray;
  delete[] barsNeedToBuyArray;

  return 0;
}