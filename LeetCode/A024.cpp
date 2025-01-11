/*
Leet Code
<860. Lemonade Change>

At a lemonade stand, each lemonade costs $5. 
Customers are standing in a queue to buy from you and order one at a time
(in the order specified by bills). Each customer will only buy one lemonade 
and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer 
so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false otherwise.
=================================================================================================
Example 1:
Input: bills = [5,5,5,10,20]
Output: true


Example 2:
Input: bills = [5,5,10,10,20]
Output: false
=================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coins = {0, 0, 0}; // 5달러, 10달러, 20달러

        for(int bill : bills){
            if(bill == 5) coins[0] += 1;
            else if(bill == 10){
                if(coins[0] >= 1){
                    coins[0] -= 1; // 5달러 주고
                    coins[1] += 1; // 10달러 받고
                }
                else return false;
            }
            else if(bill == 20){
                if(coins[1] >= 1 && coins[0] >= 1){
                    coins[1] -= 1; // 10달러 먼저 주고
                    coins[0] -= 1; // 5달러 나머지 계산
                    coins[2] += 1; // 20달러 받기
                }
                else if(coins[0] >= 3) coins[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> bills;
    bills.push_back(5);
    bills.push_back(5);
    bills.push_back(5);
    bills.push_back(10);
    bills.push_back(20);
    cout << Solution().lemonadeChange(bills);
    return 0;
}