class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalH = 0;

            for (int p : piles) {
                totalH += (p + mid - 1) / mid;  // ceil(p/mid) without floating point
            }

            if (totalH <= h) {
                ans = mid;
                right = mid - 1;  // try smaller speed
            } else {
                left = mid + 1;   // need faster speed
            }
        }
        return ans;
    }
};
