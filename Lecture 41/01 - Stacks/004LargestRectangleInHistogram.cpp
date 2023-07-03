#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// time : O(n) space : O(n)

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	stack<pair<int, int>> s; // {value, index}
	vector<int> r; // to store the indices of the nearest smaller element to the right

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of h[i]

		while (!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if (s.empty()) {
			// h[i] doesn't have nearest smaller element to its right
			r.push_back(n);
		} else {
			// value at the s.top() represents the nearest smaller element to the right of h[i]
			r.push_back(s.top().second);
		}

		s.push({h[i], i});

	}

	reverse(r.begin(), r.end());

	for (int i = 0; i < n; i++) {
		cout << r[i] << " ";
	}

	cout << endl;

	while (!s.empty()) {
		s.pop();
	}

	vector<int> l; // to store the indices of the nearest smaller element to the left

	for (int i = 0; i < n; i++) {

		// find the index of the nearest smaller element to the left of h[i]

		while (!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if (s.empty()) {
			// h[i] doesn't have nearest smaller element to its left
			l.push_back(-1);
		} else {
			// value at the s.top() represents the nearest smaller element to the left of h[i]
			l.push_back(s.top().second);
		}

		s.push({h[i], i});

	}

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	cout << endl;

	int maxArea = 0;

	for (int i = 0; i < n; i++) {

		// compute area of the largest rectangle under the histogram that uses the ith bar

		int a_i = h[i] * (r[i] - l[i] - 1);
		maxArea = max(maxArea, a_i);

	}

	cout << maxArea << endl;

	return 0;
}