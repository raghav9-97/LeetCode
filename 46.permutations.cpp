/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:

void swap(vector<int> &arr, int i, int j){
    int a = arr[i];
    arr[i] = arr[j];
    arr[j] = a;
}

void permute(int ptrpos, vector<int> &arr, vector<vector<int> > &list, int n){
    if(ptrpos >= n){
        list.push_back(arr);
        return;
    }

    for(int i=ptrpos; i<n; i++){
        swap(arr, ptrpos, i);
        permute(ptrpos+1, arr, list, n);
        swap(arr, ptrpos, i);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        permute(0, nums, list, nums.size());
        return list;
    }
};
// @lc code=end

