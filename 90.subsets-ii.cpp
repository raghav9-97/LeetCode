/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:

void combSum(int idx, vector<int> &arr, vector<int> &ds, vector<vector<int> > &list, int n){
    if(idx >= n)
    return;

    if(idx == 0){
        vector<int> empty;
        list.push_back(empty);
    }
    for(int i=idx; i<n; i++){
        if(i > idx && arr[i] == arr[i-1])
        continue;
        ds.push_back(arr[i]);
        list.push_back(ds);
        combSum(i+1, arr, ds, list, n);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        combSum(0, nums, ds, list, nums.size());
        return list;
    }
};
// @lc code=end

