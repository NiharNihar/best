#include <bits/stdc++.h> 
using namespace std; 

bool areBracketsBalanced(string expr) 
{
	stack<char> ss;
	char        c;
	for(int i = 0; i < expr.length(); i++) {
		if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[')
			ss.push(expr[i]);
		if(ss.empty())
			return false;
		switch(expr[i]) {
			case '}':
				c = ss.top();
				if (c == '(' || c == '[')
					return false;
				ss.pop();
				break;
			case ')':
				c = ss.top();
				if(c == '{' || c == '[')
					return false;
				ss.pop();
				break;
			case ']':
				c = ss.top();
				if(c == '{' || c == '(')
					return false;
				ss.pop();
				break;
		}
	}
	return (ss.empty()); 
} 

// Driver code 
int main() 
{ 
	string expr = "{()}[]"; 

	// Function call 
	if (areBracketsBalanced(expr)) 
		cout << "Balanced" << endl; 
	else
		cout << "Not Balanced" << endl; 
	return 0; 
} 

