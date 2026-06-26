class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0 ;
        int high = nums.size() - 1 ;

        while( low < high ){
            int mid = low + ( high - low )/2 ;
            // keeping mid always at even index 
            if( mid % 2 == 1 ) mid-- ;
            
            if( nums[mid] == nums[mid+1]){
                low = mid + 2 ;
            }

            else{  // nums[mid] != nums[mid+1] 
                high = mid ;

            }
        }
        return nums[low] ;

        
    }
};