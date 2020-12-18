// C++ program to decode a string recursively 
// encoded as count followed substring 
#include<bits/stdc++.h> 
using namespace std; 

// Returns decoded string for 'str' 
string decode(string str) 
{ 
	stack<int> integerstack; 
	stack<char> stringstack; 
	string temp = "", result = ""; 

	// Traversing the string 
	for (int i = 0; i < str.length(); i++) 
	{ 
		int count = 0; 

		// If number, convert it into number 
		// and push it into integerstack. 
		if (str[i] >= '0' && str[i] <='9') 
		{ 
			while (str[i] >= '0' && str[i] <= '9') 
			{ 
				count = count * 10 + str[i] - '0'; 
				i++; 
			} 

			i--; 
			integerstack.push(count); 
		} 

		// If closing bracket ']', pop elemment until 
		// '[' opening bracket is not found in the 
		// character stack. 
		else if (str[i] == ']') 
		{ 
			temp = ""; 
			count = 0; 

			if (! integerstack.empty()) 
			{ 
				count = integerstack.top(); 
				integerstack.pop(); 
			} 

			while (! stringstack.empty() && stringstack.top()!='[' ) 
			{ 
				temp = stringstack.top() + temp; 
				stringstack.pop(); 
			} 

			if (! stringstack.empty() && stringstack.top() == '[') 
				stringstack.pop(); 

			// Repeating the popped string 'temo' count 
			// number of times. 
			for (int j = 0; j < count; j++) 
				result = result + temp; 

			// Push it in the character stack. 
			for (int j = 0; j < result.length(); j++) 
				stringstack.push(result[j]); 

			result = ""; 
		} 

		// If '[' opening bracket, push it into character stack. 
		else if (str[i] == '[') 
		{ 
			if (str[i-1] >= '0' && str[i-1] <= '9') 
				stringstack.push(str[i]); 

			else
			{ 
				stringstack.push(str[i]); 
				integerstack.push(1); 
			} 
		} 

		else
			stringstack.push(str[i]); 
	} 

	// Pop all the elmenet, make a string and return. 
	while (! stringstack.empty()) 
	{ 
		result = stringstack.top() + result; 
		stringstack.pop(); 
	} 

	return result; 
} 

bool isDisit(char ch)
{
	int val = ch - '0';
	return (val == 0 || val == 1  || val == 2  || val == 3  || val == 4 ||
		val == 5 || val == 6  || val == 7  || val == 8  || val == 9);
}
bool isMeta(char ch)
{
	return ( ch == '[' || ch == ']');
}
string decode2(string str)
{
	stack<int>    istack;
	stack<string> sstack;
	int len = str.length();

	int i = 0;
	int j = 0;
	string tmp1 = "";
	while(i < len) {

		char ic = str[i];
		switch(ic) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				int val, k;
				val = ic - '0';
				k = i + 1;
				while(str[k] != '\0' && isDisit(str[k])) {
					val = val * 10 + (str[k] - '0');
					++k;
				}
				istack.push(val);
				i = k;
				break;;
			case '[':
				i++;
				if (!isDisit(str[i]))
					istack.push(1);
				break;;
			case '\0':
			case '\n' :
			case ']' :
				j = istack.top();
				tmp1 = "";
				for(int p = 0; p < j; p++) {
					tmp1 += sstack.top();
				}
				istack.pop();
				sstack.pop();
				sstack.push(tmp1);
				i++;
				break;;
			 default:
				string ss = "";
				ss += ic;
				int l = i + 1;
				while(str[l] != '\0' && !isMeta(str[l]) && !isDisit(str[l])) {
					ss = ss + str[l];
 					++l;
				}
				sstack.push(ss);
				i = l;
				break;;

		}
	}
	
	string ret = "";
	string ts = "";
	while(!istack.empty()) {
		ret = sstack.top() + ret;
		for(int i = 0; i < istack.top(); i++) {
			ts += ret;
		}
		sstack.pop();
		istack.pop();
	}
	return ts;
	
}
// Driven Program 
int main() 
{ 
	string str = "3[b2[ca]]"; 
	cout << decode(str) << endl; 
	cout << decode2(str) << endl; 
	return 0; 
} 

