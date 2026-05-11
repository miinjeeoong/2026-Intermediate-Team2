// BOJ 2110번 공유기 설치
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N, C;
    cin >> N >> C;
 
    int house[200005];
    for (int i=0; i<N; i++) {
        cin >> house[i];
    }
    sort(house, house + N); 
 
    int low = 1;
    int high = house[N - 1] - house[0]; // 가장 큰 거리는 N번째 집과 첫번째 집 사이의 거리
    int ans = 0;

    while (low < high) { 
        int mid = (low + high) / 2;

        int cnt = 1; 
        int prev = house[0];

        for (int i=1; i<N; i++) {
            if (house[i] - prev >= mid) { // 두 집 사이 거리가 mid 이상이면 공유기 설치
                cnt++; 
                prev = house[i]; // 마지막으로 공유기를 설치한 위치 갱신
            }
        }
        if (cnt >= C) { 
            ans = mid;
            low = mid + 1; 
        } else { 
            high = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}