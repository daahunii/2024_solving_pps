/*
Leet Code
<258. Add Digits>

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
=================================================================================================
Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0
=================================================================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int calculate(int &number){
        vector<int> n;
        int sum = 0;
        do{
            n.push_back(number%10);
            number /= 10;
        }while(number);
        return accumulate(n.begin(), n.end(), 0);
    }

    int addDigits(int num) {
        int result = num;
        while(result > 9) result = calculate(result);
        return result;
    }
};

int main(){
    cout << Solution().addDigits(38);
    return 0;
}