class Solution {
private:
    bool check(int divisor , vector<int>& nums , int threshold){
        // sum of the division's result.
        long long th = 0 ;
        for( int number : nums ){
            th += (number + divisor - 1) / divisor ;  //th += ceil( (double)number / divisor)
            if( th > threshold){
                return false ;  // no need to go further 
            }
        }
        return th <= threshold ;

    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ;
        int high = *max_element( nums.begin() , nums.end()) ;
        // smallestDivisor
        int ans = *max_element( nums.begin() , nums.end()) ;
        
        while( low <= high ){
            int mid = low + (high - low)/2 ;

            if(check(mid , nums , threshold)){
                ans = mid ;
                high = mid - 1 ;

            }
            else{
                low = mid + 1 ;
            }
        }
        return ans ;
    }
};