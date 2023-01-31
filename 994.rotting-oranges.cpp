/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
int orangesRotting(vector<vector<int> >& grid) {
    queue<pair<pair<int,int>, int> > bfsq;
    bool unrotten = false;
    int m = grid.size(), n = grid[0].size();
    int visited[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2){
            visited[i][j] = 2;
            bfsq.push(make_pair(make_pair(i,j), 0));
            }
            else if(grid[i][j] == 1)
            unrotten = true;

            visited[i][j] = 0;
        }
    }
    int time = -1;
    int rowdel[] = {-1, 0, 1, 0};
    int coldel[] = {0, 1, 0, -1};
    while(!bfsq.empty()){
        int r = bfsq.front().first.first;
        int c = bfsq.front().first.second;
        int t = bfsq.front().second;
        time = max(time, t);
        bfsq.pop();
        for(int i=0; i<4; i++){
            int nrow = r + rowdel[i];
            int ncol = c + coldel[i];
            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n
            && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                bfsq.push(make_pair(make_pair(nrow, ncol), t+1));
                visited[nrow][ncol] = 2;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] != 2 && grid[i][j] == 1)
            return -1;
        }
    }
    
    if(!unrotten)
    return 0;

    return time;
}

};
// @lc code=end

