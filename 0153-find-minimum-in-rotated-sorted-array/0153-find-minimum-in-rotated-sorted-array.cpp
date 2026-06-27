class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n-1 ;
        int ans = INT_MAX ;

        while( low <= high ){
            int mid = low + (high - low)/2 ;
            // if whole array is sorted
            if(nums[low] <= nums[high]){
                ans = min( ans , nums[low]) ;
                break ;
            }
            // left portin is sorted 
            if( nums[low] <= nums[mid] ){
                ans = min( ans , nums[low] ) ;
                low = mid + 1 ;

            }
            // right one is sorted 
            else{
                ans = min( ans , nums[mid] ) ;
                high = mid - 1 ;
            }
        }
        return ans ;
        
        
    }
};