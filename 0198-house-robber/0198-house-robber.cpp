class Solution {
public:
    int func( int idx , vector<int>& arr ,vector<int>& dp){

        if(idx == 0) return arr[idx];

        if( idx < 0) return 0 ;

        if(dp[idx] != -1) return dp[idx];

        int pick = arr[idx] + func(idx - 2 , arr , dp);
        int not_pick = 0 + func(idx - 1 , arr , dp);

        return dp[idx] = max(pick , not_pick);

    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n+1 , -1);

        return func(n-1,nums,dp);

    }
};


// // recurssive will give tle

// class Solution {
// public:
//     int func( int idx , vector<int>& arr){

//         if(idx == 0) return arr[idx];

//         if( idx < 0) return 0 ;

//         int pick = arr[idx] + func(idx - 2 , arr);
//         int not_pick = 0 + func(idx - 1 , arr);

//         return max(pick , not_pick);

//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return func(n-1,nums);

//     }
// };