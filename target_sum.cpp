/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
    Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int result;

    void findTargetSumWays(vector<int>& nums, int S, int runningSum, int index){
        if(index == nums.size()){
            if(runningSum == S){
                result++;
            }
        }
        else{
            findTargetSumWays(nums, S, runningSum + nums[index], index+1);
            findTargetSumWays(nums, S, runningSum - nums[index], index+1);
        }
    }
public:
    Solution():result(0){}
    int findTargetSumWays(vector<int>& nums, int S) {
        findTargetSumWays(nums, S, 0, 0);
        return result;
    }
};

int main(){
    int arr[] = {1,1,1,1,1};
    vector<int> input(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    Solution s;

    cout << s.findTargetSumWays(input, 3) << endl;
}
