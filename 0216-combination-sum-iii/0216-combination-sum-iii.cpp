class Solution {
public:
    void find_combinations(int idx, int k, int n,
                           vector<vector<int>>& ans,
                           vector<int>& ds) {

        if (k == 0) {
            if (n == 0) {
                ans.push_back(ds);
            }
            return;
        }

        for (int i = idx; i <= 9; i++) {

            if (i > n)
                break;

            ds.push_back(i);

            find_combinations(i + 1 , k - 1 , n - i , ans , ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        find_combinations(1 , k , n , ans, ds);

        return ans;
    }
};