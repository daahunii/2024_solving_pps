/*
Baekjoon
<3059. 등장하지 않는 문자의 합>

문제
알파벳 대문자로 구성되어있는 문자열 S가 주어졌을 때, 
S에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 구하는 프로그램을 작성하시오.

문자열 S가 “ABCDEFGHIJKLMNOPQRSTUVW” 일 때, S에 등장하지 않는 알파벳 대문자는 X, Y, Z이다. 
X의 아스키 코드 값은 88, Y는 89, Z는 90이므로 이 아스키 코드 값의 합은 267이다.

알파벳 대문자의 아스키 코드 값은 다음과 같다.(생략)
===================================================================================
입력
입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
각 테스트 데이터는 한 줄로 구성되어 있고, 문자열 S가 주어진다. S는 알파벳 대문자로만 구성되어 있고, 최대 1000글자이다.

출력
각 테스트 데이터에 대해, 입력으로 주어진 문자열 S에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 한 줄에 하나씩 출력한다.
===================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> arr;
    vector<int> result;
    pair<string, int> alphabet;
    for(int i=65; i<=90; i++){
        char a = i;
        alphabet.first = a;
        alphabet.second = i;
        arr.push_back(alphabet);
    }
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int sum = 0;
        string alpha;
        cin >> alpha;
        for(int j=0; j<arr.size(); j++){
            if(alpha.find(arr[j].first) == string::npos){
                sum += arr[j].second;
            }
        }
        result.push_back(sum);
    }
    for(int r : result) cout << r << "\n";
    // for(int i = 0; i < arr.size(); i++)
    //     cout << arr[i].first << ' ' << arr[i].second << '\n';
    return 0;
}