// BOJ 1654번 랜선 자르기
#include <iostream>
using namespace std;

int K, N, ans;
int arr[10001];
int maxi = 0;
long long mid, high, low;

int main() {
    cin >> K >> N;

    for (int i=0; i<K; i++){
        cin >> arr[i];
        if (maxi < arr[i]){
            maxi = arr[i];
        }
    }

    low = 1;
    high = maxi;
    ans = 0;

    while (low <= high){
        mid = (low + high) / 2;
        int cnt = 0;
        for (int i=0; i<K; i++){
            cnt += arr[i] / mid;
        }

        if (cnt >= N){
            low = mid + 1;
            if (ans < mid){
                ans = mid;
            }
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
}