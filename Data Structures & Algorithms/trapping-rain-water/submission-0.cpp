class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefixmax(n);
        vector<int> suffixmax(n);

        // Prefix maximum
        prefixmax[0] = height[0];

        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], height[i]);
        }

        // Suffix maximum
        suffixmax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixmax[i] = max(suffixmax[i + 1], height[i]);
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            int leftmax = prefixmax[i];
            int rightmax = suffixmax[i];

            if (height[i] < leftmax && height[i] < rightmax) {
                total += min(leftmax, rightmax) - height[i];
            }
        }

        return total;
    }
};