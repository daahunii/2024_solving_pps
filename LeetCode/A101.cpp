/*
Leet Code
<888. Fair Candy Swap>

Alice and Bob have a different total number of candies. 
You are given two integer arrays aliceSizes and bobSizes 
where aliceSizes[i] is the number of candies of the ith box of candy 
that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.

Since they are friends, they would like to exchange one candy box each so that after the exchange, 
they both have the same total amount of candy. 
The total amount of candy a person has is the sum of the number of candies in each box they have.

Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, 
and answer[1] is the number of candies in the box that Bob must exchange. 
If there are multiple answers, you may return any one of them. 
It is guaranteed that at least one answer exists.
===========================================================================================
Example 1:
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]

Example 2:
Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]

Example 3:
Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
===========================================================================================
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set> //unordered_set을 사용하기 위해 추가해주어야 한다.
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> Aset, Bset;
        int sumA = 0, sumB = 0;
        for(int a: A){
            Aset.insert(a);
            sumA += a;
        }

        for(int b: B){
            Bset.insert(b);
            sumB += b;
        }

        int sz = (sumA + sumB) / 2;

        for(int a: A)
            if(Bset.find(sz - (sumA - a)) != Bset.end())
                return {a, sz - (sumA - a)};

        return {};
    }
};

int main() {

    return 0;
}