class Solution {
public:
    void find_combination(int idx, int target, vector<int>& arr,
                          vector<vector<int>>& ans, vector<int>& ds) {

        // Base case
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {

            // Skip duplicates
            if (i > idx && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);

            find_combination(i + 1, target - arr[i], arr, ans, ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        find_combination(0, target, candidates, ans, ds);

        return ans;
    }
};