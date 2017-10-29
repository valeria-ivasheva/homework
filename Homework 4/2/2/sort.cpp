#include "sort.h"

void quickSort(int x[], int left, int right)
{
	int const numberMiddle = (right + left + 1) / 2;
	int const middle = x[numberMiddle];
	int leftNow = left;
	int rightNow = right;
	while (leftNow <= rightNow)
	{
		while (x[leftNow] < middle)
		{
			leftNow++;
		}
		while (x[rightNow] > middle)
		{
			rightNow--;
		}
		if (leftNow <= rightNow)
		{
			int temp = x[rightNow];
			x[rightNow] = x[leftNow];
			x[leftNow] = temp;
			rightNow--;
			leftNow++;
		}
	}
	if (left < rightNow)
	{
		quickSort(x, left, rightNow);
	}
	if (leftNow < right)
	{
		quickSort(x, leftNow, right);
	}
}
