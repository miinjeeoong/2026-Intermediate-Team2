// BOJ 3079번 입국심사
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long times[100001];

int main() {

	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> times[i];
	}
	sort(times, times + N);

    long long low = 1;
	long long high = (long long)M * times[0]; // 심사 시간이 제일 적은 심사대에서 모든 친구들이 검사받음 
	long long res = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long cnt = 0;
		for (int i=0; i<N; i++) {
			cnt += mid / times[i]; // 시간을 각 심사대의 초로 나눈 몫의 합이 친구들의 수 
            if (cnt >= M) { // overflow 방지
                break;
            }
		}
		if (cnt >= M) {
            res = mid; 
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << res;
	return 0;
}