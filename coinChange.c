#include<bits/stdc++.h> 

using namespace std; 

int count1( int S[], int m, int n ) 
{
	int sc[n + 1];
	memset(sc, 0, sizeof(sc));
	sc[0] = 1;
	for(int i = 0; i < m; i++) {
		for(int j = S[i]; j <= n; j++){
			sc[j] += sc[j - S[i]];
		}
	}
	return sc[n];
}

int count2( int S[], int m, int n )
{
	int sc[n + 1];
	memset(sc, 0, sizeof(sc));
	sc[0] = 1;
	for (int i = 0; i < m; i++) {
		for(int j = S[i]; j <= n; j++) {
			sc[j] += sc[j - S[i]];
		}
	}
	return sc[n];
} 
int count( int S[], int m, int n ) 
{ 
	int i, j, x, y; 
	int table[n + 1][m]; 
	for (int i = 0; i < m; i++) 
		table[0][i] = 1; 

	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : 0; 
			table[i][j] = x + y; 
		} 
	} 
	return table[n][m - 1]; 
} 

int count3( int S[], int m, int n )
{
	int sc[n + 1][m];
	memset(sc, 0, sizeof(sc));
	for (int i = 0; i < m; i++)
		sc[0][i] = 1;
	for(int i = 0; i < m; i++) {
		for(int j = S[i]; j <= n; j++) {
			sc[j][i] = sc[j - S[i]][i] + sc[j][i -1];
		} 
	}
	return sc[n][m - 1];
}
int count4(int S[], int m, int n )
{
	if( n == 0)
		return 1;
	if ( n < 0)
		return 0;
	if(m <= 0 &&  n >= 1)
		return 0;
	return count4(S, m -1, n) + count4(S, m, n - S[m -1]);
}

int main() 
{ 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 4; 
	cout << count(arr, m, n) << endl; 
	cout << count1(arr, m, n) << endl; 
	cout << count2(arr, m, n) << endl; 
	cout << count3(arr, m, n) << endl; 
	cout << count4(arr, m, n) << endl; 
	return 0;
} 
