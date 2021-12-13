/*
������W��ʼ��һ��DFS���ڽӵ�
*/

#include <cstdio>
#include <iostream>

using namespace std;

//����
int m, n, ans;
char mat[100][100];
int dx[8] = { -1,0,1,-1,1,-1,0,1};
int dy[8] = { 1,1,1,0,0,-1,-1,-1};


//��ǰλ�ã�x,y��
void dfs(int x, int y) {
	//����ǰλ���滻Ϊ
	mat[x][y] = '.';

	//ѭ�������ƶ���8������
	int xx, yy;
	for (int i = 0; i < 8; ++i) {
		//��x�����ƶ�dx����y�����ƶ�dy,�ƶ��Ľ��Ϊ��xx,yy��
		xx = x + dx[i];
		yy = y + dy[i];
		//�ж�(xx,yy)�Ƿ���԰���ڣ��Լ��Ƿ��л�ˮ
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
			//����W�ĵط���ʼdfs
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