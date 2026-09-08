class Solution {
public:
    int countCommas(int n) {
        int tot = 0;
        int a =n-999;
        if(a>0){
            tot+=a;
        }
        return tot;
        
    }
};