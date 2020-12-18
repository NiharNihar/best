#include <bits/stdc++.h> 
using namespace std; 

// Returns count of possible paths to reach cell at row 
// number m and column number n from the topmost leftmost 
// cell (cell at 1, 1) 
// 1  2  3  4
// 5  6  7  8
// 8  10  11 12
int numberOfPaths(int m, int n)   
{
	if (m == 1 || n == 1)
		return 1;
	return (numberOfPaths(m -1, n) + numberOfPaths(m, n - 1));
} 

int numberOfPaths1(int m, int n) 
{ 
    int count[m][n]; 
    for (int i = 0; i < m; i++) 
        count[i][0] = 1; 
    for (int j = 0; j < n; j++) 
        count[0][j] = 1; 
  
    for (int i = 1; i < m; i++) { 
        for (int j = 1; j < n; j++) 
            count[i][j] = count[i - 1][j] + count[i][j - 1]; //+ count[i-1][j-1]; 
    } 
    return count[m - 1][n - 1]; 
} 
int numberOfPaths2(int m, int n) 
{
	int pp[m][n];
	for (int i = 0; i < m; i++)
		pp[i][0] = 1;
	for (int i = 0; i < n; i++)
		pp[0][i] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			pp[i][j] = pp[i - 1][j] + pp[i][j -1];
		}
	}
	return pp[m - 1][n - 1];
}

int numberOfPaths3(int m, int n)
{
	int pp[n];
	for (int o = 0; o < n; o++)
		pp[o] = 0;
	pp[0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++)
			pp[j] += pp[j - 1];
	}
	 return pp[n -1]; 
}

int numberOfPaths4(int m, int n) 
{ 
    int dp[n]; 
    for (int o = 0; o < n; o++)
		dp[o] = 0;
    dp[0] = 1; 
  
    for (int i = 0; i < m; i++) { 
        for (int j = 1; j < n; j++) { 
            dp[j] += dp[j - 1]; 
        } 
    } 
  
    return dp[n - 1]; 
} 
int main() 
{ 
	cout << numberOfPaths(3, 3) << endl; 
	cout << numberOfPaths1(3, 3) << endl; 
	cout << numberOfPaths2(3, 3) << endl; 
	cout << numberOfPaths3(3, 3) << endl; 
	cout << numberOfPaths4(3, 3) << endl; 
	return 0; 
} 

