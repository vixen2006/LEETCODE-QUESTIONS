class Solution {
public:

    const long long mod = 1e9+7;

    long long pow( long a , long b){
        if( b == 0) return 1 ;

        a = a% mod;

        long long B = b ;
        if( B < 0){
            B = -B ;
            a = 1/a;
        }
        return ( ( B % 2 == 0 ? pow(a*a , B/2) : a*pow(a*a , B/2))) % mod;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2 ;
        long long odd = n/2 ;

        long long ans = ( pow( 5 , even) * pow(4 , odd) ) % mod ;

        return ans ;
        
    }
};