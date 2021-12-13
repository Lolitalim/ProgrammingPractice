/*
从任意W开始，一次DFS把邻接的
*/

#include <cstdio>
#include <iostream>

using namespace std;

//输入
int m, n, ans;
char mat[100][100];
int dx[8] = { -1,0,1,-1,1,-1,0,1};
int dy[8] = { 1,1,1,0,0,-1,-1,-1};


//当前位置（x,y）
void dfs(int x, int y) {
	//将当前位置替换为
	mat[x][y] = '.';

	//循环遍历移动的8个方向
	int xx, yy;
	for (int i = 0; i < 8; ++i) {
		//向x方向移动dx，向y方向移动dy,移动的结果为（xx,yy）
		xx = x + dx[i];
		yy = y + dy[i];
		//判断(xx,yy)是否在园子内，以及是否有积水
		if (xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] == 'W') 
			dfs(xx, yy);
	}
}

void solve() {
	ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//从有W的地方开始dfs
			if (mat[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
	}
}

int main() {
	while (cin >> n >> m && m > 0 && n > 0) {
		solve();
		cout << ans << endl;
	}
}