class Solution {
private:
    bool check( int speed , int h , vector<int>& piles ){
        long long hours = 0 ;

        for(int bananas : piles ){
            hours += ( bananas + speed - 1 ) / speed ;   //hoursTaken += ceil(piles[i] / k) ;
        }

        return hours <= h ;
        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = *max_element(piles.begin(), piles.end());
        int k = high ;
        
        while( low <= high ){
            int mid = low + ( high - low )/2 ;

            // if the speed mid pointing to is valid then store it and go for the more less
            if(check(mid , h , piles )) {  
                k = mid ;
                high = mid -1 ;
            }
            // if not then go to right and search the valid speed 
            else{
                low = mid + 1 ;
            }

        }
        return k ;
        
    }
};