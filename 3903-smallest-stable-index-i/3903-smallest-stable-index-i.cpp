class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stb(n); // stb =  stability score arr
        stb[0] = nums[0];

        for( int i = 1; i < n ; i++){
            stb[i] = max(nums[i] , stb[i-1]); 
        }  

        int mn = INT_MAX;
        for(int i = n-1 ; i >= 0 ;i--){
            mn = min(mn , nums[i]);
            stb[i] -= mn ;
        }  
        for(int i = 0; i<n;i++){
            if(stb[i]<=k) return i;
        }  return -1;   
    }
}; //tc = O(n)


// // tc = O(N2)

// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int mn , mx , mini = INT_MAX;
//         for( int i = 0 ; i < nums.size() ;i++){
//             mx = *max_element(nums.begin() , nums.begin()+i);
//             mn = *min_element(nums.begin()+i , nums.end());
//             if(mx-mn > k) continue;
//             else{
//                 mini = min(mini , i);
//             }
//             return mini;

//         }
        
//         return -1 ;
        
//     }
// };