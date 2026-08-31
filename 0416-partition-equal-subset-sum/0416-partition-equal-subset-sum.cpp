class Solution {
private:
    bool f( int ind , int target  , vector<int>& nums , vector<vector<int>>& dp ){
        // base cases 
        if( target == 0 ) return true ;
        if( ind == 0 ) return (nums[0] == target ) ;

        //memoization
        if( dp[ind][target] != -1 ) return dp[ind][target] ;

        bool not_take = f(ind - 1 , target , nums , dp );
        bool take = false ;
        if( target >= nums[ind]){
            take = f(ind - 1 , target - nums[ind] , nums , dp ) ; 
        }

        return dp[ind][target] = ( take || not_take ) ;
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size() ;

        int s = 0 ;
        for( auto it : nums ){
            s += it ;
        }
        if( s % 2 != 0) return false ;  // checking is total even or not 

        vector<vector<int>> dp( n , vector<int> (s/2 + 1 , -1) ) ;

        bool ans = f( n-1 , s/2 , nums , dp  ) ; 
        
        return ans ;
    }
};