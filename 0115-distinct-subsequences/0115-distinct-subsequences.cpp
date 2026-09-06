class Solution {
public:
    int func(int idx , int j , string& s , string& t, vector<vector<int>>& dp){

        if( j == t.length() ){
            return 1;
        }

        if( idx == s.length()) return 0;

        if(dp[idx][j] != -1) return dp[idx][j];

        if(s[idx] == t[j]){
            int take = func( idx+1 , j+1, s , t , dp);

            int not_take = func( idx+1 , j , s,t,dp);

            return dp[idx][j] = take + not_take;
        }

        else{
            return dp[idx][j] = func( idx +1 , j , s , t , dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length(); int m = t.length();

        vector<vector<int>> dp(n , vector<int>(m , -1));

        return func( 0 , 0 , s , t , dp);
        
    }
};


// recurssive approach 
//tle 

// class Solution {
// public:
//     void func(int idx , string &s , string &t , string &temp, int &cnt){
//         if(idx == s.length()){
//             if(temp == t){
//                 cnt++;
//             }
//             return ;
//         }

//         temp.push_back(s[idx]);
//         func(idx+1 , s , t , temp , cnt);

//         temp.pop_back();

//         func(idx+1 , s , t , temp , cnt);
//     }
//     int numDistinct(string s, string t) {
//         int cnt = 0;
//         string temp ="";
//         func(0, s, t, temp, cnt);

//         return cnt;
        
//     }
// };