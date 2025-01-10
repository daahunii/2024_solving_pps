#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    int N, power = 0;
    vector<int> plug;
    cin >> N;
    for(int i=0; i<N; i++){
        int p;
        cin >> p;
        if(i != N-1) plug.push_back(p-1);
        else plug.push_back(p);
    }
    cout << accumulate(plug.begin(), plug.end(), 0);
}