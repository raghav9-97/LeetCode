/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:

bool isSafe(int i, int j, vector<string> &queen, int n){
    for(int r=0; r<i; r++){
        if(queen[r][j] == 'Q')
        return false;
    }
    int row = i, col = j;
    //Left Diagonal
    while(row >= 0 && col >= 0){
        if(queen[row][col] == 'Q')
        return false;
        row--;
        col--;
    }
    
    //Right diagonal
    row = i, col = j;
    while(row >= 0 && col < n){
        if(queen[row][col] == 'Q')
        return false;
        row--;
        col++;
    }
    return true;
}

void nQueens(int i, vector<string> &queen, int n, vector<vector<string> > &solns){
    if(i == n){
        solns.push_back(queen);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(i, j, queen, n)){
            queen[i].replace(j, 1, "Q");
            nQueens(i+1, queen, n, solns);
            queen[i].replace(j, 1, ".");
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queens;
        vector<string> nqueens;
        string str;
        for(int j=0; j<n; j++){
            str.append(".");
        }
        for(int i=0; i<n; i++){
            nqueens.push_back(str);
        }
        nQueens(0, nqueens, n, queens);
        return queens;
    }
};
// @lc code=end

