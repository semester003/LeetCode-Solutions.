class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0 ;
        int high = nums.size() - 1 ;

        /* while( low < high ){  //Why "while(low < high)" Because we're shrinking the search space to one element.
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
        return nums[low] ; */

        while( low < high ){
            int mid = low + ( high - low )/2 ;

            if( mid % 2 == 0){  // mid is even

                if( nums[mid] == nums[mid + 1]) low = mid + 2 ;
                else{
                    high = mid ;
                }
            }
            else{ // mid is odd
                if( nums[mid] == nums[mid-1]) low = mid + 1 ;
                else{
                    high = mid - 1;
                }
            }
        }
        return nums[low] ;
        
    }
};