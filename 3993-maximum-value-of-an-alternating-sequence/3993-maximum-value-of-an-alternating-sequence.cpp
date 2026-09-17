class Solution {
public:
    long long maximumValue(int n, int s, int m) {
    
        // vector<long long > seq( n , 0) ;
        // seq[0] = s ;
        // long long last = s ;
        // long long curr = 0 ;

    //     for( long long i = 1 ; i < n ; i++ ){
    //         if( i % 2 == 0 ){
    //             curr = last - 1;
    //         }
    //         else{
    //             curr = last + m ;
    //         }
    //         last = curr ;
    //     }

        if( n == 1 ) return s ;
    //     if( n % 2 == 0) return last ;
    //     return last+1 ;
    // }

        long long  k = n/2 ;

        return s + k*m - (k-1) ;
    }
     
};