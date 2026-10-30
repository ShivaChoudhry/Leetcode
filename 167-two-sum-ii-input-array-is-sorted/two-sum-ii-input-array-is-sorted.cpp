class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> finalans;
        int left=0, right=numbers.size()-1;

        while(left<right){
            int sum=numbers[left]+numbers[right];

            if(sum==target){
                
                return {left+1, right+1};
            }
            if(sum>target){
                right--;
            }
            if(sum<target){
                left++;
            }
        }
        return {};
    }
};