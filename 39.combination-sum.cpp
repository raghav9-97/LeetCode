/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:

    void combSum(int idx, vector<int> &arr, vector<int> &sub, 
                        int target, vector<vector<int> > &list, int n){
        if(idx >= n){
            if(target == 0)
            list.push_back(sub);
            return;
        }

        if(target >= arr[idx]){
            target -= arr[idx];
            sub.push_back(arr[idx]);
            combSum(idx, arr, sub, target, list, n);
            target += arr[idx];
            sub.pop_back();
        }
        combSum(idx+1, arr, sub, target, list, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> list;
        combSum(0, candidates, sub, target, list, candidates.size());
        return list;
    }
};
// @lc code=end

