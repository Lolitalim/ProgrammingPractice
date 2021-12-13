/*
���⣺
��H * W�ľ��ι�԰����ƻ�����桢�۸����ֹ����� ���ڣ��������ң���ͬ�ֹ�������ͬһ������
������԰�Ĺ����ֲ������ܹ��ж��ٸ����� ��ԭ�����ͼ��ƻ��Ϊ�꣬��Ϊ�����۸�Ϊ�ߣ� ͼ�й�10������
���룺
�������ݣ�ÿ�����ݵ�һ��Ϊ��������H��W��H <= 100, W <= 100���� H =0 �� W = 0�������������
����H��W�б�ʾ��԰�Ĺ����ֲ��� ƻ����@������#�� �۸���*��
�����
����ÿ�����ݣ����������ĸ�����
*/

/*
 * AOJ 0118: Property Distribution
 * ���⣺m��n�����У���3��ֲ����ڵ�ͬ��ֲ���ɺϲ����ʺϲ��󹲶��ٿ�����
 * ���ͣ�DFS�����仯��������BFS�����鼯��
 * �㷨����ĳ�����������������4�������ѯ����Ϊͬ��ֲ��������ݹ飬�����ĵ���Ҫ���仯��
 */

#include <iostream>
#include <cstdio>

using namespace std;
int ans;
int m, n;
char mat[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x,int y) {
	char t = mat[x][y];
	mat[x][y] = '.';
	for (int i = 0; i < 4; ++i) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < m && yy >= 0 && yy < n && mat[xx][yy] == t) {
			dfs(xx, yy);
		}
	}
}

void solve() {
	ans = 0;
	for (int i = 0;i < m;++i) {
		cin >> mat[i];
	}
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			if (mat[i][j] != '.') {
				++ans;
				dfs(i, j);
			}
		}
	}
}


int main() {
	while(cin >> m >> n && m > 0 && n > 0){
		solve();
	    cout << ans << endl;
	}
}
