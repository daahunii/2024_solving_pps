/*
Leet Code
<66. Plus One>

You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
=================================================================================================
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
=================================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int size = digits.size()-1;
        while(size>=0 && digits[size]==9){
            digits[size] = 0;
            size--;
        }
        if(size == -1){ // 끝에서부터 앞까지 다 0으로 바뀌었다면...(ex 999같은 숫자)
            digits.push_back(1);
            reverse(digits.begin(), digits.end()); // 끝에 1을 추가하고 반전시킴
        }
        else digits[size]++;
        return digits;
    }
};

int main(){
    int a[]={1,2,3};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = Solution().plusOne(d);

    for(int i=0; i<v.size(); i++) cout << v[i] << " ";

    return 0;
}