class Solution {
    public int strStr(String haystack, String needle) {

        int m = haystack.length();
        int n = needle.length();

        // Create LPS array
        int[] lps = new int[n];

        int prefix = 0;
        int suffix = 1;

        lps[0] = 0;

        while (suffix < n) {

            if (needle.charAt(prefix) == needle.charAt(suffix)) {

                prefix++;
                lps[suffix] = prefix;
                suffix++;

            } else {

                if (prefix == 0) {

                    lps[suffix] = 0;
                    suffix++;

                } else {

                    prefix = lps[prefix - 1];
                }
            }
        }

        // KMP search
        int i = 0;
        int j = 0;

        while (i < m) {

            if (haystack.charAt(i) == needle.charAt(j)) {

                i++;
                j++;

                if (j == n) {
                    return i - j;
                }

            } else {

                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        return -1;
    }
}