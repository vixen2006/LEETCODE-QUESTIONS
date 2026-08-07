class Solution {
public:

    void generate( int idx ,vector<int>& arr , vector<vector<int>>& ans , vector<int>& ds){
        if(ds.size() == arr.size()){ // permutations will contain all the nos
            ans.push_back(ds);
            return ;
        }
        
        for( int i = 0 ; i < arr.size() ; i++){

            // to avoid ,multiple values 

            if(find(ds.begin(), ds.end(), arr[i]) != ds.end()) continue ;

            ds.push_back(arr[i]);

            generate(i + 1 , arr , ans , ds);

            ds.pop_back();
        }


        // ds.push_back(nums[idx]);
        // generate(idx + 1, nums, ans, ds);
        // ds.pop_back();

    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans ;
        vector<int> ds ;

        generate( 0 , nums , ans , ds);

        return ans ;
        
    }
};