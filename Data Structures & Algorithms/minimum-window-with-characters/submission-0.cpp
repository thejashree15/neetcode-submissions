class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length())
            return "";

        int freq[128] = {0};

        // Store required frequency of each character
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int count = t.length();

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.length()) {

            // Add s[right] to the window
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;
            right++;

            // Window is valid
            while (count == 0) {

                // Update minimum window
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove s[left]
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};