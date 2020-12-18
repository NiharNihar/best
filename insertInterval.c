// CPP program for above approach 
#include <iostream> 
#include <stack> 
using namespace std; 

// Program to merge interval 
void mergeInterval2(pair<int, int> arr[], int n, 
		    pair<int,int> newPair) 
{ 
	
	// Create stack of type 
	// pair<int, int> 
	stack< pair<int, int> > stk; 
	
	// Pushing first pair 
	stk.push(arr[0]); 
	
	// Storing the top element 
	pair<int, int> top = stk.top(); 
	
	// Checking is newPair.first 
	// is less than top.second 
	if (newPair.first < top.second) 
	{ 
		
		// Pop the top element 
		// as it will merge with the 
		// previous range 
		stk.pop(); 
		
		// Re-assigning top.first 
		top.first = min(top.first, 
						newPair.first); 
		
		// Re-assigning top.second 
		top.second = max(top.second, 
						newPair.second); 
		
		// Push the current interval 
		stk.push(top); 
	} 
	else
	{ 
		
	// Push the new pair as it does 
	// not intersect to first pair 
	stk.push(newPair); 
	} 

	// Iterate i from 1 to n - 1 
	for (int i = 1; i < n; i++) 
	{ 
		
		// Store the top element of 
		// the stack stk 
		pair<int, int> top = stk.top(); 
		
		// Checking is arr[i].first 
		// is less than top.second 
		if (arr[i].first < top.second) 
		{ 
			
			
			// Pop the top element 
			// as it will merge with the 
			// previous range 
			stk.pop(); 
			
			// Re-assigning top.first 
			top.first = min(top.first, 
							arr[i].first); 
			
			// Re-assigning top.second 
			top.second = max(top.second, 
							arr[i].second); 
			
			// Push the current interval 
			stk.push(top); 
		} 
		
		else
		{ 
			
			// Push the new pair as it does 
			// not intersect to first pair 
			stk.push(arr[i]); 
		} 
	} 
	
	// Storing the final intervals 
	stack< pair<int,int> > finalIntervals; 
	
	// Poping the stack elements 
	while (stk.empty() != true) 
	{ 
		pair<int, int> ele = 
					stk.top(); 
		stk.pop(); 
		
		// Push ele in finalIntervals 
		finalIntervals.push(ele); 
	} 
	
	
	// Displaying the final result 
	while (finalIntervals.empty() != true) 
	{ 
		pair<int, int> ele = 
					finalIntervals.top(); 
		finalIntervals.pop(); 
		
		cout << ele.first << ", "
			<< ele.second << endl; 
	} 
} 

// Driver Code 
int main() 
{ 

	pair<int, int> arr2[] = { 
		{ 1, 2 }, { 3, 5 }, { 6, 7 }, 
				{ 8, 10 }, { 12, 16 } 
	}; 
	pair<int, int> newPair{ 4, 9 }; 
	int n2 = sizeof(arr2) / sizeof(arr2[0]); 

	// Function Call 
	mergeInterval2(arr2, n2, newPair); 

	return 0; 
}

