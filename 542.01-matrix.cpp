/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
    vector<vector<int> > distance(mat.size(), vector<int> (mat[0].size(), 0));
    vector<vector<bool> > visited(mat.size(), vector<bool> (mat[0].size(), false));
    queue<pair<pair<int, int>, int> > bfsqueue;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j] == 0){
                visited[i][j] = true;
                bfsqueue.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    while(!bfsqueue.empty()){
        pair<pair<int, int>, int> elt = bfsqueue.front();
        bfsqueue.pop();
        distance[elt.first.first][elt.first.second] = elt.second;

        int rowdel[] = {-1, 0, 1, 0};
        int coldel[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = elt.first.first + rowdel[i];
            int ncol = elt.first.second + coldel[i];

            if(nrow >= 0 && nrow < mat.size() 
                && ncol >=0 && ncol < mat[0].size() && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    if(mat[nrow][ncol] == 1)
                    bfsqueue.push(make_pair(make_pair(nrow, ncol), elt.second + 1));
                    else if(mat[nrow][ncol] == 0)
                    bfsqueue.push(make_pair(make_pair(nrow, ncol), 0));
            }
        }
    }
    return distance;
}
};
// @lc code=end

