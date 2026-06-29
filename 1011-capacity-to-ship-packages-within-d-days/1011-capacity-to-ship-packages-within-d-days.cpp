class Solution {
private:
    bool check( int mid , vector<int>& weights , int days ){
        
        int usedDays = 1 ;
        int currentLoad = 0 ;

        for( int weigh : weights ){

            if( currentLoad + weigh <= mid ){
                currentLoad += weigh ;
            }
            else{
                usedDays++ ;
                currentLoad = weigh ;
            }


        }
        return usedDays <= days ;

            
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element( weights.begin() , weights.end()) ;  //Capacity must at least carry the heaviest package.
        int high = accumulate(weights.begin(), weights.end(), 0LL) ;   //  Then we can ship everything in one day.
        int ans = high ;

        while( low <= high ){
            int mid = low + (high - low)/2 ;

            if(check(mid , weights , days)){
                ans = min(ans,mid) ;
                high = mid - 1 ;

            }
            else{
                low = mid + 1 ;
            }
        }
        return ans ;
        
    }
};