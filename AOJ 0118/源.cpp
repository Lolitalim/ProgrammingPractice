/*
题意：
在H * W的矩形果园里有苹果、梨、蜜柑三种果树， 相邻（上下左右）的同种果树属于同一个区域，
给出果园的果树分布，求总共有多少个区域。 （原题的样图中苹果为リ，梨为カ，蜜柑为ミ， 图中共10个区域）
输入：
多组数据，每组数据第一行为两个整数H，W（H <= 100, W <= 100）， H =0 且 W = 0代表输入结束。
以下H行W列表示果园的果树分布， 苹果是@，梨是#， 蜜柑是*。
输出：
对于每组数据，输出其区域的个数。
*/

/*
 * AOJ 0118: Property Distribution
 * 题意：m＊n矩阵中，共3种植物。相邻的同种植物块可合并，问合并后共多少块区域。
 * 类型：DFS＋记忆化搜索（／BFS／并查集）
 * 算法：从某点出发，向上下左右4个方向查询，若为同种植物则继续递归，经过的点需要记忆化。
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
