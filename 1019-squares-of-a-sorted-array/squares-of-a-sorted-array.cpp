class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int mid=0;
        while (mid < n && nums[mid] < 0) {
            mid++;
        }
        int i=mid-1;
        int j=mid;

        vector<int> ans;

        int k=0;
        while(i>=0 && j<n){
            int leftsquare=nums[i]*nums[i];
            int rightsquare=nums[j]*nums[j];
            if(leftsquare<rightsquare){
                ans.push_back(leftsquare);
                k++;
                i--;
            }
            else{
                ans.push_back(rightsquare);
                k++;
                j++;
            }
        }
         while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            k++;
            i--;
        }

        while (j < n) {
            ans.push_back(nums[j] * nums[j]);
            j++;
            k++;
        }

        return ans;
        
    }
};