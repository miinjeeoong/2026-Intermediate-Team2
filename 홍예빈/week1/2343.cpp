// BOJ 2343번 기타 레슨
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
	long long low, high = 0;
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		cin >> arr[i];
		high += arr[i];	// high는 모든 배열의 합
	}
	low = *max_element(arr, arr + N);	// low는 배열의 max값

	while (low <= high) {	
		long long mid = (low + high) / 2;	

		long long sum = 0, cnt = 0;	
		for (int i=0; i<N; i++) {
			if (sum + arr[i] > mid) { // 블루레이 용량을 넘김
				sum = 0; // 새 블루레이이므로 초기화
				cnt++; // 용량을 넘겼으니까 1개 씀
			}
			sum += arr[i]; // 현재 블루레이에 영상 저장
		}
		if (sum > 0) cnt++; // 용량이 넘치지 않은 마지막 블루레이도 카운트

		if (cnt > M) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << low << "\n";
	return 0;
}