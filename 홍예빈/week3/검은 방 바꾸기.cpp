// 검은 방 바꾸기 - 0-1 BFS
#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int map[51][51];
int dist[51][51];
int n;

struct Info {
	int y, x, w;
};

struct Cmp {
	bool operator()(Info a, Info b) {
		return a.w > b.w;
	}
};

bool isValid(int y, int x) {
	return y >= 1 && x >= 1 && y <= n && x <= n;
}

void dijkstra(int y, int x) {
	priority_queue<Info, vector<Info>, Cmp>pq;
	pq.push({ y,x,map[y][x] });
	dist[y][x] = map[y][x];
	while (!pq.empty()) {
		Info now = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = now.y + dy[i];
			int next_x = now.x + dx[i];
			
			if (!isValid(next_y, next_x)) continue;
			
			int next_w = now.w + map[next_y][next_x];
			
			if (next_w >= dist[next_y][next_x]) continue;

			pq.push({ next_y,next_x,next_w });
			dist[next_y][next_x] = next_w;

		}
	}
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			if (s[j-1] == '0') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
			dist[i][j] = 987654321;
		}
	}

	dijkstra(1, 1);
	cout << dist[n][n];
	return 0;
}