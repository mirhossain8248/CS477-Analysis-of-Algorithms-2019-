/*
Mir Hossain
CS477
HW3, Problem 3
Not Recursive Implementation of Merge Sort
*/
#include <iostream>



//Display function
void displayCharArray(char *array, int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
    std::cout << std::endl;
}

//Auxillar function to find the min
char getMin(char firstLetter, char nextLetter)
{
	if (firstLetter < nextLetter)
	{
		return firstLetter;
	}
	else
	{
		return nextLetter;
	}
}

//Helper function for mergesort
void mergeSubArrays(int arr[], int temp[], int p, int q, int r)
{
	// p = start, q = mid, r = end.
	int i = p, j = (q + 1), k = p;

	while (i <= q && j <= r) //while in bounds
	{
		if (arr[i] < arr[j]) //store into array one
		{
			temp[k++] = arr[i++]; //store into array two
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= q)
	{
		temp[k++] = arr[i++]; //store after midpoint
	}

	for (int index = p; index <= r; index++)
	{
		arr[index] = temp[index]; //store phrase in array
	}

	std::cout << "Merged Array: ";
	displayCharArray(arr, r);
}

void mergeSort(char arr[], char temp[], int min, int max)
{
	// Divide array into equal partitions
	for (int i = 1; i <= max - min; i = (i * 2))
	{
		for (int j = min; j < max; j += (i * 2))
		{
			int p = j, q = (j + i - 1), r = getMin(j + (i * 2) - 1, max);
			mergeSubArrays(arr, temp, p, q, r);
		}
	}
}

int main()
{
	char phrase[] = { "ASORTINGEXAMPLE" };
	char temp[] = { "ASORTINGEXAMPLE" };



	std::cout << "Array before merge sort:";
	displayCharArray(phrase, 15);
	mergeSort(phrase, temp, 0, 14);

	return (0);
}
