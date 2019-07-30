#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[12] = { 0 };
int N;
int s, su, m, d;
int max_v = -1000000000, min_v = 1000000000;

void cal(int cnt, int s1, int su1, int m1, int d1, int total) {
	if (cnt == N) {
		max_v = max(max_v, total);
		min_v = min(min_v, total);
	}
	if (s1 < s)
		cal(cnt+1, s1+1, su1, m1, d1, total + arr[cnt]);
	if (su1 < su)
		cal(cnt+1, s1, su1+1, m1, d1, total - arr[cnt]);
	if (m1 < m)
		cal(cnt+1, s1, su1, m1+1, d1, total * arr[cnt]);
	if (d1 < d)
		cal(cnt+1, s1, su1, m1, d1+1, total / arr[cnt]);
}

int main() {
	cin >> N;
	int A;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> s >> su >> m >> d;
	cal(1, 0, 0, 0, 0, arr[0]);
	cout << max_v << endl << min_v << endl;

	return 0;


}
