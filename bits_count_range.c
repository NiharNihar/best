// C++ program for the above approach
#include <iostream>
using namespace std;

// Function to count set bit in range
int countSetBits(int L, int R)
{
	// Count variable
	int count = 0;

	for (int i = L; i <= R; i++) {

		// Find the set bit in Nth number
		int n = i;
		while (n > 0) {

			// If last bit is set
			count += (n & 1);

			// Left sift by one bit
			n = n >> 1;
		}
	}

	// Return count
	return count;
}

int countSetBits2(int L, int R)
{
	int count = 0;
	for (int i = L; i <= R; i++) {
		int n = i;
		while (n > 0) {
			count += (n & 1);
			n >>= 1;
		}
	}
	return count;
}

// Driver Code
int main()
{
	// Given Range L and R
	int L = 3, R = 5;

	// Function Call
	cout << "Total set Bit count is "
		<< countSetBits(L, R) << endl;

	cout << "Total set Bit count is "
		<< countSetBits2(L, R) << endl;
	return 0;
}

