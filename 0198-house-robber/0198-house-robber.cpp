class Solution {
private:
    int f( int index , vector<int>& nums , vector<int>& dp ){
        if( index < 0 ) return 0 ;

        if( dp[index] != -1) return dp[index] ;

        // if we are robbing the ith house , then take it's money and rob the next house but not the adjacent(i-1) house
        int left = nums[index] + f(index-2 , nums , dp) ;

        // if we aint robbing the ith house then we can rob (i-1)
        int right = f(index - 1 , nums , dp ) ;

        return  dp[index] = max(left,right) ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> dp(n , -1) ;

        int ans = f(n-1 , nums , dp ) ;
        return ans ;
        
    }
};