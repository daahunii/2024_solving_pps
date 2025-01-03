/*
Leet Code
<118. Pascal's Triangle>

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
=================================================================================================
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

DP 점화식 : C[i][j] = C[i-1][j-1] + C[i-1][j] (Combination)
=================================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // 리턴해줄 2차원 벡터 선언
        for(int i=0; i<numRows; i++){
            vector<int> cRows;
            if(i==0) cRows.push_back(1);
            else{
                cRows.push_back(1);
                for(int j=0; j<result[i-1].size()-1; j++){
                    cRows.push_back(result[i-1][j] + result[i-1][j+1]);
                }
                cRows.push_back(1);
            }
            result.push_back(cRows);
        }
        return result;
    }
};

int main(){
    int num;
    cout << "input number : ";
    cin >> num;

    Solution().generate(num);

	for (int i = 0; i < Solution().generate(num).size(); i++) {
		for (int j = 0; j < Solution().generate(num)[i].size(); j++) {
			cout << Solution().generate(num)[i][j] << " ";
		}
        cout << endl;
    }
    return 0;
}