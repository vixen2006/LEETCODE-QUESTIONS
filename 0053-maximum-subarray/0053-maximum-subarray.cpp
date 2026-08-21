class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size() ; int sum = 0 , maxi = INT_MIN;

        if( n == 0 ) return 0; // empty subarray

        for( int i = 0 ; i < n ; i++){
            sum += nums[i] ; 
            maxi = max(maxi , sum);

            if(sum < 0 ) sum = 0 ;

        }
         return maxi ;
    }
};