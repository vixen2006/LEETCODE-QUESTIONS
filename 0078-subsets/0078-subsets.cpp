class Solution {
public:
    void create_subsets(int idx, vector<int>& nums,
                        vector<vector<int>>& ans,
                        vector<int>& ds) {

        if (idx == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Don't take nums[idx]
        create_subsets(idx + 1, nums, ans, ds);

        // Take nums[idx]
        ds.push_back(nums[idx]);
        create_subsets(idx + 1, nums, ans, ds);
        ds.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        create_subsets(0, nums, ans, ds);

        return ans;
    }
};