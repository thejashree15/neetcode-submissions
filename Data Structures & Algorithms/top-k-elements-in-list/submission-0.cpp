class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        // bucket[i] stores all elements with frequency i
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Put elements into their frequency bucket
        for (auto it : freq) {
            int element = it.first;
            int count = it.second;

            bucket[count].push_back(element);
        }

        // Step 4: Collect the top k frequent elements
        vector<int> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = nums.size(); i >= 1; i--) {

            for (int element : bucket[i]) {
                ans.push_back(element);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};