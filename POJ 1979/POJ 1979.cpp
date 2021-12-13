/*
 * POJ 1979: Red and Black
 * ���⣺m��n�����У�������ʼλ�ú�ÿ�����Ƿ�����ȵ�״̬������������4�������ƶ�������ٵ��ܵ��
 * ���ͣ�DFS�����仯��������BFS�����鼯��
 * �㷨����ĳ����������õ�ɲ���δ��ǣ������1�����õ��ǣ����仯����������4������ĵ�����ݹ�������
 */

#include <cstdio>
#include <iostream>

using namespace std;

char mat[100][100];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int m, n, ans;

void dfs(int x,int y) {
	if(mat[x][y] != '.') return;
	++ans;
	mat[x][y] = 'x';
	int xx, yy;
	for(int i = 0; i < 4; ++i) {
		xx = x + dx[i];
		yy = y + dy[i];
		if(xx >= 0 && xx < m && yy >= 0 && yy < n){
			dfs(xx, yy);
		}
	}
}

void solve() {
	ans = 0;
	for(int i = 0; i < m; ++i) {
		cin >> mat[i];
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j< n; ++j) {
			if(mat[i][j] == '@') {
				mat[i][j] = '.';
				dfs(i, j);
				return;
			}
		}
	}
}

int main() {
	while(cin >> n >> m && m > 0 && n > 0) {
		solve();
		cout << ans << endl;
	}
	return 0;
}
