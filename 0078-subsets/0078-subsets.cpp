class Solution {
public:

    void create_subsets(int idx , vector<int>& nums , vector<vector<int>>& ans , vector<int>& ds){
       class Solution {
public:

    void create_subsets(int idx , vector<int>& nums , vector<vector<int>>& ans , vector<int>& ds){
        // ans.push_back(ds);

        if( idx == nums.size()){
            ans.push_back(ds);
            return ;
        }

        //dont take nums[idx]
        create_subsets(idx + 1 , nums , ans , ds);
        
        //take nums[idx]
        ds.push_back(nums[idx]);

        create_subsets(idx + 1 , nums , ans , ds);

        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> ds ;

        create_subsets(0 , nums , ans , ds);

        return ans ;
        
    }
};

        if( idx == nums.size()){
            ans.push_back(ds);
            return ;
        }

        //dont take nums[idx]
        create_subsets(idx + 1 , nums , ans , ds);
        
        //take nums[idx]
        ds.push_back(nums[idx]);

        create_subsets(idx + 1 , nums , ans , ds);

        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> ds ;

        create_subsets(0 , nums , ans , ds);

        return ans ;
        
    }
};