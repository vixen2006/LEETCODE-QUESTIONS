class Solution {
public:
    long long countCommas(long long n) {
        long long tot = 0;
        int i = 1;
        while( n - pow(10,i*3) + 1> 0){
            tot += (n-pow(10, i*3) + 1);
            i++;
        }
        return tot;
        
    }
};