class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int L = 0 ;
        int R = n-1 ;
        vector<int> ans ;
        while( L < R ){
            if( numbers[L] + numbers[R] == target ){
                return { L+1 , R+1 } ;
            }
            if( numbers[L] + numbers[R] < target) L++ ;
            else R-- ;
        }
        return ans ;      
    }
};