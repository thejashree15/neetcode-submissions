class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;

        // Merge two sorted arrays
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i++]);
            } else {
                nums3.push_back(nums2[j++]);
            }
        }
        while (i < n1) {
            nums3.push_back(nums1[i++]);
        }
        while (j < n2) {
            nums3.push_back(nums2[j++]);
        }

        int n = n1 + n2;
        if (n % 2 == 1) {
            return nums3[n / 2];  // odd length
        } else {
            return (nums3[n / 2] + nums3[n / 2 - 1]) / 2.0;  // even length
        }
    }
};
