class Solution {
private:
    int f( int index , vector<int>& nums , vector<int>& dp ){
        if( index < 0 ) return 0 ;

        if( dp[index] != -1) return dp[index] ;  // memoization 

        // if we are robbing the ith house , then take it's money and rob the next house but not the adjacent(i-1) house
        int left = nums[index] + f(index-2 , nums , dp) ;

        // if we aint robbing the ith house then we can rob (i-1)
        int right = f(index - 1 , nums , dp ) ;

        return  dp[index] = max(left,right) ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        if(n == 1) return nums[0] ; // edge case nums = [0]

        vector<int> dp(n , -1) ;
        // base cases
        // dp[0] = nums[0] ;
        // dp[1] = max( nums[1] , nums[0] ) ;


        // int ans = f(n-1 , nums , dp ) ;
        // return ans ;
        
        // tabulation
        // for( int i = 2 ; i < n ; i++){
        //     int left = nums[i] + dp[i - 2] ;
        //     int right = dp[i - 1] ;

        //     dp[i] = max( left , right ) ;

        // }
        // return dp[n-1] ;

        // space optimisation
        int prev2 = nums[0] ;
        int prev = max( nums[0] , nums[1] ) ;
        
        for(int i = 2 ; i < n ; i++){
            int left = nums[i] + prev2 ;
            int right = prev ;

            int curri = max( left , right ) ;

            prev2 = prev ;
            prev = curri ;

        }

        return prev ;
    }
};