
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int maxfreq = 0;
        int maxlength = 0;

        vector<int> freq(26, 0);

        for (int high = 0; high < n; high++) {

            freq[s[high] - 'A']++;

            maxfreq = max(maxfreq, freq[s[high] - 'A']);

            while ((high - low + 1) - maxfreq > k) {
                freq[s[low] - 'A']--;
                low++;
            }

            maxlength = max(maxlength, high - low + 1);
        }

        return maxlength;
    }
};
