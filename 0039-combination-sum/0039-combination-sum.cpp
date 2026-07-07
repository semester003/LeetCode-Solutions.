class Solution {
public:
    void combiantionsum1(int ind , int target , vector<int> &ds , vector<vector<int>> & ans , vector<int> &candidates ){
        // base case
        // doing so will make sure that after reaching target == 0 our recursion doesn't go further stop immediatly 
        if(target == 0){
                ans.push_back(ds);
                return ;
        }
        // 
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return ;
        }
        if(candidates[ind] <= target){
        ds.push_back(candidates[ind]) ;
        combiantionsum1(ind,target - candidates[ind] , ds , ans , candidates);
        ds.pop_back() ;
        }
        combiantionsum1(ind + 1 , target ,ds , ans, candidates) ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int>> ans ;
        vector<int> ds ;
        combiantionsum1(0,target ,ds,ans,candidates);
        return ans ;
        
    }
};