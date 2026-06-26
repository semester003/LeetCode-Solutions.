class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int n = nums.size() ;
        int high = n - 1 ;

        while( low <= high ){

            int mid = low + ( high - low )/2 ;
            if( nums[mid] == target ) return mid ;

            // left half is sorted
            if( nums[0] <= nums[mid] ){
                if(nums[0] <= target && target < nums[mid] ){
                    high = mid - 1 ;
                }
                else{
                    low = mid + 1 ;
                }
            }
            else{ // right half is sorted  
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1 ;
                }
                else{
                    high = mid - 1 ;
                }
            }
        }
        return -1 ;
        
    }
};