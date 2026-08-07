class Solution {
public:
    string getPermutation(int n, int k) {

        // generating arr with all the numbers 
        
        // we need no of nos in arr for that we hv fact 

        vector<int> arr ;
        int fact = 1 ;

        for( int i = 1 ; i < n ; i++){
            fact *= i;
            arr.push_back(i);
        } 

        arr.push_back(n);

        string ans = "";

        k -= 1 ; // 0 based indexing

        while(true){
             ans += to_string(arr[k/fact]); 

             arr.erase(arr.begin() + k/fact);

             if(arr.size() == 0) break ;

             k = k% fact ;

             fact = fact / arr.size();
        }
        
        return ans ;
    }
};