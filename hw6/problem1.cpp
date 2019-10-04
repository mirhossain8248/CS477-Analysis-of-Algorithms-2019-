/* Mir Hossain
CS477
Problem 1
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRevB(vector<int> board, vector<int> revenue, int distance, int minMiles);
void maxRevD(vector<int> board, vector<int> revenue, int distance, int minMiles);

int main()
{
	vector<int> x {6, 7, 12, 14}; //Ad locations
	vector<int> r {5, 6, 5, 1}; //Potential revenue
	unsigned int d = 20; //Freeway distance
	unsigned int minDistance = 5; //Min distance for boards
	int maxRev;

	maxRev = maxRevB(x, r, d, minDistance); //Part B

	cout << "Max Revenue: " << maxRev << endl << endl;

	maxRevD(x, r, d, minDistance); //Part B

	cout << endl;

	return 0;
}

// maxRevB computes the placeAdsimal value to this problem, showing all subproblems.
int maxRevB(vector<int> board, vector<int> revenue, int distance, int minMiles)
{
	int * placeAds = new int[distance + 1];
	int next = 0;
	minMiles += 1;
	placeAds[0] = 0;

	cout << "Part A/B" << endl;
	cout << "--------" << endl;
	cout << "Subproblems: [";

	for (int i = 1; i <= distance; i++) //iterate through miles
	{
		if (next < board.size())
		{
			if (board[next] != i) //Try to get ith+1
			{
				placeAds[i] = placeAds[i - 1];
			}
			else //Place ad if placeAdsimal solution doesn't exist
			{
				if (minMiles <= i)
				{
					//placeAds = max( placeAds(i - 6) + revenue(i), placeAds[i - 1]
					placeAds[i] = max(placeAds[i - minMiles] + revenue[next], placeAds[i - 1]);
				}
				else
				{
					placeAds[i] = revenue[next];
				}
				next++;
			}
		}
		else
		{
			placeAds[i] = placeAds[i - 1];
		}

		cout << placeAds[i]; //Display

		if (i != 20)
			cout <<", ";
	}
		cout << "]" << endl;
		cout << endl;

	// Return the max revenue which is contained where D = 20.
	return placeAds[distance];
}

void maxRevD(vector<int> board, vector<int> revenue, int distance, int minMiles)
{
	int * placeAds = new int[distance + 1];
	int next = 0;
	int previousMile = 0;
	int currentMile;
	int count;

	bool location = false;

	minMiles += 1;
	placeAds[0] = 0;


	cout << "Part C/D" << endl;
	cout << "--------" << endl;
	cout << "F means 'False Location'" << endl << endl;
	cout << "Subproblems: [";

	for (int i = 1; i <= distance; i++)
	{
		if (next < board.size())
		{

			if (board[next] != i)
			{
				placeAds[i] = placeAds[i - 1];
			}
			else
			{
				if (minMiles <= i)
				{
					placeAds[i] = max(placeAds[i - minMiles] + revenue[next], placeAds[i - 1]);
					currentMile = placeAds[i];

					if (currentMile != previousMile && count >= 6)
					{
						location = true;
						count = 0;
					}

					if (location == true)
					{
						cout << endl << "Current Mile = " << i << endl;
						cout << endl << "New Revenue = " << placeAds[i];
					}
					previousMile = currentMile;
				}
				else
				{
					placeAds[i] = revenue[next];
				}
				next++;
			}
		}
		else
		{
			placeAds[i] = placeAds[i - 1];
		}

		//If current location is not used, display F
		if (location == false)
			cout << "F";
		if (i != 20)
			cout << ", ";

		location = false;
		count++;
	}
	cout << "]" << endl;
	cout << endl;
}
