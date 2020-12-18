#include<bits/stdc++.h> 
using namespace std; 

struct Interval 
{ 
	int s, e; 
}; 

bool mycomp(Interval a, Interval b) 
{ 
	return a.s < b.s;
}; 

void printStack(stack<Interval> in)
{
	if(in.empty())
		return;
	Interval t = in.top();
	in.pop();
	printStack(in);
	cout << "[" << t.s << " " << t.e << "]" << endl;
	return;
}
void mergeIntervals(Interval arr[], int n, Interval New) 
{
	stack<Interval> ms;
	bool merge_req = false;
	ms.push(arr[0]);
	for(int i = 1; i < n; i++) {
		Interval t  = ms.top();
		if(t.s < New.s) {
			ms.push(arr[i]);
			continue;
		} else if(t.s == New.s) {
			t.e = max(t.e, New.e);
			ms.pop();
			ms.push(t);
		} else {
			merge_req = true;
			if(t.e < New.s) {
				ms.push(New);
			}
			else {
				t.s = max(t.s, New.s);
				t.e = max(t.e, New.e);
				ms.pop();
				ms.push(t);
			}
		}
		if(merge_req) {
			if (t.e > arr[i].s) {
				t.s = max(t.s, arr[i].s);
				t.e = max(t.e, arr[i].e);
				ms.pop();
				ms.push(t);
			}
			else {
				ms.push(arr[i]);
			}
		}
	} 	
	printStack(ms); 
}

int main() 
{ 
	Interval arr[] = { {1,2}, {3,5}, {6,7}, {8,10}, {12, 16} }; 
	int n = sizeof(arr)/sizeof(arr[0]);
	Interval New = {4, 9}; 
	mergeIntervals(arr, n, New);
	return 0; 
} 

