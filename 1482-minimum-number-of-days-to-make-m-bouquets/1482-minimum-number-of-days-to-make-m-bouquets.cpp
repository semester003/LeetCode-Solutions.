class Solution {
private:
    bool check( int mid , vector<int>& bloomDay , int m , int k ){
        int cnt = 0 ;
        int bouque = 0 ;

        for( int days : bloomDay ){
            // if flower is bloomed , then collect it
            if( mid >= days ){
                cnt++ ;
            }
            // if not , then make the bouque of collected flower 
            else{
                bouque += cnt/k ;
                // check if we have enough bouque
                if( bouque >= m ){
                    return true ;
                }
                cnt =  0 ;
            }
        }
        // if we have very last flower bloomed then it will make the bouque out of previously collected flower # testcase 1
        bouque += cnt/k ;
        if( bouque >= m ){
            return true ;
        }
        else return false ;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long x = m * 1LL * k * 1LL ;
        if( x > bloomDay.size()) return -1 ;
        // my search space{7,8,9,10,11,12,13}
        int low = *min_element(bloomDay.begin() , bloomDay.end()) ;
        int high = *max_element(bloomDay.begin() , bloomDay.end()) ;
        int minDays = *max_element(bloomDay.begin() , bloomDay.end()) ;

        while( low <= high ){
            int mid = low + (high - low)/2 ;

            if(check(mid , bloomDay , m , k)){
                minDays = min( minDays , mid ) ;
                high = mid - 1 ;

            }
            else{
                low = mid + 1 ;
            }
        }
        return minDays ;
        
    }
};