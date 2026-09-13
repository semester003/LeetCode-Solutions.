class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size() ;
        int L=0 ;

        for( int R = 0 ; R < n ; R++ ){
            if( nums[R] != val ){
                nums[L] = nums[R] ;
                L++ ;
            } 
        }
        return L ;   
    }
};