class Solution {
private:
    int f(int start , int last , vector<int>& nums){
        int prev2 = nums[start] ;
        int prev = max( nums[start] , nums[start + 1] ) ;
        
        for(int i = start+2 ; i <= last ; i++){
            int left = nums[i] + prev2 ;
            int right = prev ;

            int curri = max( left , right ) ;

            prev2 = prev ;
            prev = curri ;

        }

        return prev ;
    }


public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ; // edge case nums = [0]
        if(n == 2) return max( nums[0] , nums[1]) ;  // if there are only two houses

        int ans1 = f( 0 , n-2 , nums ) ;   // removing last element 
        int ans2 = f( 1 , n-1 , nums ) ;  
        return max(ans1 , ans2) ;
        
    }
};