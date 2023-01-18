/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:

bool checkColumn(int j, vector<vector<char> > &sudoku, int num){
    for(int i=0; i<9; i++){
        if(sudoku[i][j] == '.')
        continue;

        else if(sudoku[i][j] == (char)(num + 48)){
            return false;
        }
    }
    return true;
}

bool checkRow(int i, vector<vector<char> > &sudoku, int num){
    for(int j=0; j<9; j++){
        if(sudoku[i][j] == '.')
        continue;

        else if(sudoku[i][j] == (char)(num + 48)){
            return false;
        }
    }
    return true;
}

bool checkSubgrid(int i, int j, vector<vector<char> > &sudoku, int num){
    int starti = (i/3)*3, endi = starti + 3, startj = (j/3)*3, endj = startj + 3;
    for(int k = starti; k<endi; k++){
        for(int l=startj; l<endj; l++){
            if(sudoku[k][l] == '.')
            continue;

            else if(sudoku[k][l] == (char)(num + 48))
            return false;
        }
    }
    return true;
}

bool sudokuSolver(int i, int j, vector<vector<char> > &sudoku){
    if(i == 9)
    return true;

    if(j == 9)
    return sudokuSolver(i+1, 0, sudoku);

    if(sudoku[i][j] != '.')
    return sudokuSolver(i, j+1, sudoku);

    for(int num=1; num <=9; num++){
        bool colFlag = checkColumn(j, sudoku, num);
        bool rowFlag = checkRow(i, sudoku, num);
        bool subgridFlag = checkSubgrid(i, j, sudoku, num);

        if(colFlag && rowFlag && subgridFlag){
            sudoku[i][j] = (char)(num + 48);
            bool solvable = sudokuSolver(i, j+1, sudoku);
            if(solvable)
            return true;
        }
    }
    sudoku[i][j] = '.';
    return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(0, 0, board);
    }
};
// @lc code=end

