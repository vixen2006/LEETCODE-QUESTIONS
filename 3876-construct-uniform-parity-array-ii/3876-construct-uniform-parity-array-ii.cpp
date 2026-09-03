class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mini = *min_element( nums1.begin() , nums1.end());

        bool check = true ;

        for( int i = 0 ; i < nums1.size() - 1 ;i++){
            if( nums1[i] % 2 != nums1[i+1] % 2) {
                check = false ;
                break ;
            }

        }

        if( check) return true ;

        if( mini % 2 == 1) return true ;

        return false ;
        
    }
};