
class Solution {
public:
    int findmax(vector<int> v) {
        int maxi = INT_MIN;

        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int maxlength = 0;

        vector<int> v(2, 0);

        for (int high = 0; high < n; high++) {
            if (nums[high] == 0) {
                v[0]++;
            }
            else {
                v[1]++;
            }

            int length = high - low + 1;
            int maxfreq = findmax(v);
            int diff = length - v[1];

            while (diff > k) {
                if (nums[low] == 0) {
                    v[0]--;
                }
                else {
                    v[1]--;
                }

                low++;

                length = high - low + 1;
                maxfreq = findmax(v);
                diff = length - maxfreq;
            }

            maxlength = max(maxlength, length);
        }

        return maxlength;
    }
};
