class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mn , mx , mini = INT_MAX;
        for( int i = 0 ; i < nums.size() ;i++){
            mx = *max_element(nums.begin() , nums.begin()+i);
            mn = *min_element(nums.begin()+i , nums.end());
            if(mx-mn > k) continue;
            else{
                mini = min(mini , i);
            }
            return mini;

        }
        
        return -1 ;
        
    }
};