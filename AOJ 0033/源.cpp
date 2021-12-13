/*
* AOJ 0033: Ball
* ���⣺���Ϊ1 - 10��10���򣬰�һ������˳�����2������֮һ������ÿ����������Ŷ�Ϊ����ķ����Ƿ���ڡ�
* ���ͣ�̰��
* �㷨������ÿ���������ڶ��ж���Ԫ�أ�����Լ�¼������������ݹ顣ÿ�����ȼ�����ߣ��ɱ�֤��֤��ߵĶ���Ԫ�ش����ұߡ�
*/

# include <cstdio>
# include <iostream>

using namespace std;

int a[10];
bool ans = true;

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 10; ++i) {
            cin >> a[i];
        }
        int l, r;
        l = r = 0;
        for (int i = 0; i < 10; ++i) {
            if (a[i] > l) {
                l = a[i];
            }
            else if (a[i] > r) {
                r = a[i];
            }
            else {
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
	return 0;
}