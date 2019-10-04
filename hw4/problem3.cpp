//Mir Hossain
//CS477 Problem 3

#include <iostream>
#include <cmath>
using namespace std;

bool isHeap(int arr[], int i, int size)
{
	if (i > ( (size - 2) / 2) )
	{
		return true;
	}

	if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2])
	{
		if (isHeap(arr, 2 * i + 1, size) && isHeap(arr, 2 * i + 2, size))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	bool resultOfA, resultOfB;

  int A[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
	int B[] = { 10, 3, 9,  2, 11, 5, 1, 6 };

	int sizeOfArrA = ( sizeof(A) / sizeof(A[0]) );
	int sizeOfArrB = ( sizeof(B) / sizeof(B[0]) );

	resultOfA = isHeap(A, 0, sizeOfArrA);
	resultOfB = isHeap(B, 0, sizeOfArrB);

	// Print the results.
	resultOfA ? cout << "Array A is a heap." : cout << "Array A is not a heap.";
	cout << endl;
	resultOfB ? cout << "Array B is a heap." : cout << "Array B is not a heap.";

	return 0;
}
