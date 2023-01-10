/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:

    void combSum(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int> > &list, int n){
    if(target == 0){
        list.push_back(ds);
        return;
    }

    if(idx >= n)
    return;

    for(int i=idx; i<n; i++){
        if(arr[i] > target)
        break;
        if(i > idx && arr[i] == arr[i-1])
        continue;
        ds.push_back(arr[i]);
        combSum(i+1, target-arr[i], arr, ds, list, n);
        ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> ds;
        combSum(0, target, candidates, ds, list, candidates.size());
    }
};
// @lc code=end

