// BOJ 2805번 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M, ans;
    vector<long long> arr(1000001);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.begin() + N); 
    
    long long low = 0;
    long long high = arr[N-1];

    while (low <= high){
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (int i=0; i<N; i++){
            if (arr[i] - mid > 0){
                sum += arr[i] - mid; // 자르고 남은게 있다면 가져감
            }
        }

        if (sum >= M){ // M미터보다 가져간 나무가 같거나 많으면
            low = mid + 1; // 조건을 만족하는 경우, 더 높은 절단 높이를 시도
            ans = mid; // 현재 절단 높이가 조건을 만족하므로 저장
        }
        else { // 조건을 만족하지 않는 경우, 절단 높이를 낮춤
            high = mid - 1;
        }
    }
    cout << ans << "\n"; // 최대 절단 높이 출력
}