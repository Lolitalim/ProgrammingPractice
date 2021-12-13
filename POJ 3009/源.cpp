/*
 * POJ 3009: Curling 2.0
 * 题意：m＊n矩阵中，给出起点、终点、空格、障碍，从每个点可向4方前进，
        直到遇到障碍，打碎并停在障碍格的前面。
        求到达终点的最少前进次数。
 * 类型：DFS＋记忆化搜索
 * 算法：从某点出发，向4个方向投掷，
         遇到障碍格，标记其为空格状态，
         继续递归障碍前一点，回退恢复障碍状态。
         每次递归直至到达终点或全部出界失败。
 */

#include <iostream>
#include <cstdio>

using namespace std;

/*Each line consists of w decimal numbers delimited by a space. 
  The number describes the status of the corresponding square.
    0 	vacant square
    1 	block
    2 	start position
    3 	goal position
 */

const int INF = 1000;
const int TYPE_VACANT = 0;
const int TYPE_BLOCK = 1;
const int TYPE_START = 2;
const int TYPE_GOAL = 3;
/*You cannot throw the stone more than 10 times in a game. 
If the stone does not reach the goal in 10 moves, the game ends in failure.*/
const int MAX_THROW = 10;

int m, n;
int mat[22][22];//The width and the height of the board satisfy: 2 <= w <= 20, 1 <= h <= 20.
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;

void dfs(int x, int y, int step) {
    if (step >= MAX_THROW) {
        return;
    }
    /*The movements of the stone are restricted to x and y directions. Diagonal moves are prohibited. */
    for (int i = 0; i < 4; ++i) {
        int xx = x;
        int yy = y;
        while (true) {
            xx += dx[i];
            yy += dy[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
                break;
            }
            if (mat[xx][yy] == TYPE_GOAL) {
                ans = min(ans, step + 1);
                break;
            }
            if (mat[xx][yy] == TYPE_BLOCK) {
                mat[xx][yy] = TYPE_VACANT;
                int prex = xx - dx[i];
                int prey = yy - dy[i];
                if (prex != x || prey != y) {
                    dfs(prex, prey, step + 1);
                }
                mat[xx][yy] = TYPE_BLOCK;
                break;
            }
        }
    }
}



void solve() {
    ans = INF;
    int sx = 0, sy = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
            /*At the beginning, the stone stands still at the start square.*/
            if (mat[i][j] == TYPE_START) {
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy, 0);

    // If there are no such routes, print -1 instead. 
    if (ans == INF) {
        ans = -1;
    }
}



int main() {
    // The end of the input is indicated by a line containing two zeros separated by a space.
    while (cin >> n >> m && n > 0 && m > 0) {
        solve();
        cout << ans << endl;
    }
    return 0;
}