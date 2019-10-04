/*
Mir Hossain
CS477
HW3, Problem 2
BubbleSort Implementation with comparisons of left and right side
*/


#include <iostream>

//Display function
void displayIntArray(int *array, int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
    std::cout << std::endl;
}

//Could've easily done this with overloading but this was easier to read/keep track of
void displayCharArray(char *array, int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
    std::cout << std::endl;
}

//Implementation of BubbleSort for integers
void intBubbleSort(int *array, int n)
{
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped)
  {
    swapped = false;
    j++;

    for (int i = 0; i < n - j; ++i)
    {
      if (array[i] > array[i + 1])
      {
        temp = array[i];
        array[i] = array[i + 1]; //Right Side
        array[i + 1] = temp; //Left Side
        std::cout << "Element "<< array[i] << " was swapped with " << temp << std::endl; //Display swaps
        swapped = true;
      }
    }
  }
}

//Implementation of BubbleSort for integers
void charBubbleSort(char *array, int n)
{
  bool swapped = true;
  char j = 0;
  char temp;

  while (swapped)
  {
    swapped = false;
    j++;

    for (int i = 0; i < n - j; ++i)
    {
      if (array[i] > array[i + 1])
      {
        temp = array[i];
        array[i] = array[i + 1]; //Right Side
        array[i + 1] = temp; //Left Side
        std::cout << "Element "<< array[i] << " was swapped with " <<temp << std::endl; //Display swaps
        swapped = true;
      }
    }
  }
}

int main() {
  int array[] = {6,5,2,8,3,1};
  char phrase[] = {"EASYQUESTION"};
  int intSize = sizeof(array)/sizeof(array[0]);
  int charSize = (sizeof(phrase)/sizeof(phrase[0])) - 1;

  std::cout << "Testing BubbleSort on Integer Array" << std::endl;
  std::cout <<"---------------------------------------" << std::endl;

  std::cout << "Before Bubble Sort :" << std::endl;
  displayIntArray(array, intSize);
  std::cout << std::endl;

  intBubbleSort(array, intSize);

  std::cout << std::endl << "After Bubble Sort :" << std::endl;
  displayIntArray(array, intSize);
  std::cout << std::endl;

  std::cout << "Testing BubbleSort on Char Array" << std::endl;
  std::cout <<"---------------------------------------" << std::endl;

  std::cout << "Before Bubble Sort :" << std::endl;
  displayCharArray(phrase, charSize);
  std::cout << std::endl;

  charBubbleSort(phrase, charSize);

  std::cout << std::endl << "After Bubble Sort :" << std::endl;
  displayCharArray(phrase, charSize);
  std::cout << std::endl;

  /*Not sure why the space is accounted for in char sorting but it's still
  correct. I may or may not fix it.
  Fix: There was originally a random space in my sorting for the char array,
  I subtracted 1 from the expression and that fixed the issue.
  */


  return (0);
}
