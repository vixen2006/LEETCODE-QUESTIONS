class Solution {
public:
    
    void find_subsets(int idx , vector<int>& arr , vector<vector<int>>& ans , vector<int>& ds){
        // if(idx == arr.size()){
        //     ans.push_back(ds);
        //     return ;
        // }

        ans.push_back(ds);

        for( int i =  idx ; i < arr.size() ; i++){

            if(i > idx && arr[i] == arr[i-1]) continue;

            // //dont take nums[idx]
            // find_subsets(i+1 , arr , ans , ds);
            
            // all unique
            ds.push_back(arr[i]);
            find_subsets(i+1 , arr , ans , ds);
            ds.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin() , nums.end());

        vector<vector<int>> ans ;
        vector<int> ds ;

        find_subsets(0 , nums , ans , ds);

        return ans ;
        
    }
};