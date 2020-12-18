#include <bits/stdc++.h>

using namespace std;

struct obj {
	int elem;
	int freq;
};

struct comp {
	bool operator() (obj o1, obj o2) {
		if ( o1.freq == o2.freq)
			return o1.elem < o2.elem;
		return o1.freq < o2.freq;
	}
};

void printKfreq(int arr[], int n, int k)
{
	unordered_map<int , int> mp;
	priority_queue<obj, vector<obj>, comp> pq;
	for(int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	for (auto it = mp.begin(); it!= mp.end(); it++) {
		obj o;
		o.elem = it->first;
		o.freq = it->second;
		pq.push(o);
	}

	for(int i = 0; i < k; i++) {
		if(pq.empty())
			break;
		obj o = pq.top();
		cout << o.elem << " " << o.freq << endl;
		pq.pop();
	}
}
struct compare {
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second < p2.second;
	}
};

void print_N_mostFrequentNumber(int arr[], int n, int k)
{
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++)
		um[arr[i]]++;

	vector<pair<int, int> > freq_arr(um.begin(), um.end());

	priority_queue<pair<int, int>, vector<pair<int, int> >,
				compare>
		pq(um.begin(), um.end());

	cout << k << " numbers with most occurrences are:\n";
	for (int i = 1; i <= k; i++) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}
}

int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	print_N_mostFrequentNumber(arr, n, k);

	cout << "Nihar " << endl;
	printKfreq(arr, n, k);;
	return 0;
}

