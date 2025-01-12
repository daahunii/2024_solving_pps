/*
Baekjoon
<10757. 큰 수 A+B>

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
==========================================================================================
입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

출력
첫째 줄에 A+B를 출력한다.
==========================================================================================
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string a1, string a2) {
    string r = "";
    int c = 0;
    int i = a1.size() - 1, j = a2.size() - 1;
    int s = 0;

    while (i >= 0 || j >= 0 || c > 0) {
        s = c; 

        if (i >= 0) {
            s += a1[i] - '0';
            i--;
        }
        if (j >= 0) {
            s += a2[j] - '0';
            j--;
        }
        c = s / 10;
        r = char((s % 10) + '0') + r;
    }
    return r;
}

int main() {
    string a1, a2;
    cin >> a1 >> a2;
    cout << solution(a1, a2) << endl;
    return 0;
}