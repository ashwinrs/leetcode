/*
The Longest Increasing Subsequence problem is to find the longest increasing subsequence of a given sequence

Link - https://www.codechef.com/wiki/tutorial-dynamic-programming
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if(nums.size() < 2){
          return nums.size();
      }
      int max = 0;
      vector<int> LS(nums.size(), 1);

      for(int i = 1; i < nums.size(); i++){
          for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && LS[j] >= LS[i]){
              LS[i] = LS[j] + 1;
            }
          }
          if(LS[i] > max){
            max = LS[i];
          }
      }
      return max;
    }
};

int main() {
   int arr[] = { 10,22,9,33,21,50,41,60,80 };
   vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));
   Solution s;

   cout << s.lengthOfLIS(v) << endl;
}
