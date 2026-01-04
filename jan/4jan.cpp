/*
1390. Four Divisors
Given an integer array nums, return the sum of divisors of the integers in that array that have 
exactly four divisors. If there is no such integer in the array, return 0.
*/
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> divisors;
            for (int j = 1; j <= nums[i]; j++) {
                if (nums[i] % j == 0)
                    divisors.push_back(j);
                if (divisors.size() > 4)
                    break;
            }
            if (divisors.size() == 4) {
                for (int i = 0; i < divisors.size(); i++) {
                    sum += divisors[i];
                }
            }
        }
        return sum;
    }
};
