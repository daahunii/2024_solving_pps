/*
Baekjoon
<11656. 접미사 배열>

문제
N개의 정수가 주어진다. 이때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다.
===================================================================================
입력
첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 
둘째에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이때, 같은 수는 한 번만 출력한다.
===================================================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> arr;
    string word;
    cin >> word;
    
    for (int i = 0; i < word.size(); i++) {
        string tmp;
        for(int j=i; j<word.size(); j++){
            tmp += word[j];
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    for (string w : arr) cout << w << '\n';
    return 0;
}