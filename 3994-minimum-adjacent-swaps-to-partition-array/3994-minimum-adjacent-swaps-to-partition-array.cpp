class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size() ;

        const long long MOD = 1e9 + 7;

        // group0 is the gr ;p that contains element < a
        long long group1 = 0 ;   // grp that contains  a <= element <= b
        long long group2 = 0 ;   // grp that contains element >b 
        long long swaps = 0 ;

        for( int i = 0 ; i < n ; i++ ){

            if( nums[i] > b ){
                group2++ ;
            }
            else if(  nums[i] >= a ){   // it's a grp1 element and it should cross every grp2 element 
                swaps = (swaps + group2) % MOD ;
                group1++ ;
            }
            // nums[i] < a  , it must cross the element of the grp1 and grp2 
            else{   
                swaps =  (swaps + group1 + group2) % MOD ;

            }
        }

        return (int)swaps ;
        
    }
};