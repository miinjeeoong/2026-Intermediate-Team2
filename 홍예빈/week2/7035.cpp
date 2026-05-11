// 정올 7035번 등수 조작 - 세그먼트 트리
#include <iostream>
using namespace std;

const int MAX = 100000;

int N, Q;
int score[100001]; // 학생 점수 저장
int tree[100001]; // i번째 점수까지의 누적 학생 수 저장

void update(int idx, int diff){ 

    while (idx <= MAX){
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

int sum(int idx){

    int result = 0;

    while (idx > 0){
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++){ // 초기 점수 입력 
        cin >> score[i];
        update(score[i], 1);
    }

    while (Q--){
        int cmd;
        cin >> cmd;

        if (cmd == 1){ // 1 x : 학생 x의 등수 출력
            int x;
            cin >> x;

            int s = score[x];
            int higher = N - sum(s); // 전체 학생 수 - s점수 이하 학생 수 = s점수보다 높은 학생 수
            cout << higher + 1 << '\n';
        }

        else { // 2 x y : 학생 x의 점수를 y로 수정
            int x, y;
            cin >> x >> y;

            update(score[x], -1); // 기존 점수 제거
            score[x] = y;
            update(score[x], 1); // 새로운 점수 추가
        }
    }
    return 0;
}