// A Naive recursive C++ program to find minimum of coins 
// to make a given change V 
#include<bits/stdc++.h> 
using namespace std; 

// m is size of coins array (number of different coins) 
int minCoins(int coins[], int m, int V) 
{
	int min = INT_MAX;
	if (V <= 0)
		return 0;
	for (int i = 0; i < m; i++) {
		if(coins[i] <= V) {
			int res = minCoins(coins, m, V - coins[i]);
			if (res != INT_MAX &&  min > res + 1)
				min = res + 1;
		}
	}
	return min; 
} 

int minCoins2(int coins[], int m, int V)
{
	int minp[V + 1];
	memset(minp, INT_MAX, sizeof(minp));
	minp[0] = 0;
	for(int i =1; i <= V; i++)
		minp[i] = INT_MAX;

	for(int i = 1; i <= V; i++) {
		for (int j = 0; j < m ; j++) {
			if ( coins[j] <= i) {
				int res = minp[i - coins[j]];
				if(res != INT_MAX && res + 1 < minp[i])
					minp[i] = res + 1;
			}
		}
	}
	return minp[V];

}
// Driver program to test above function 
int main() 
{ 
	int coins[] = {9, 6, 5, 1}; 
	int m = sizeof(coins)/sizeof(coins[0]); 
	int V = 11; 
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V) << endl; 
	cout << "Minimum coins required is "
		<< minCoins2(coins, m, V) << endl; 
	return 0; 
} 

