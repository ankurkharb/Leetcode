class Solution {
public:
bool isSafe(vector<vector<char>>& board, int row, int col, char dig)
{
    for(int j=0;j<9;j++)
    {
        if(board[j][col]==dig)return false; // check horizontally

    }
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==dig)return false ;// check vertically
        
    }
// grid me check , find startin row and starting col of grid , use formula r/3 * 3

int SRow = (row/3)*3;
int SCol = (col/3)*3;

for(int i=SRow;i<=SRow+2;i++)
{
    for(int j=SCol;j<=SCol+2;j++)
    {
        if(board[i][j]==dig)return false;
    }
}
return true;
}

bool helper(vector<vector<char>>& board, int row, int col)
{
    if(row==9)return true;
    int nextRow=row;
    int nextCol=col+1;
    if(col==9)
    {
        nextRow=row+1;
        nextCol=0;
    }

    if(board[row][col]!='.')
    {
        return helper(board,nextRow,nextCol);
    }
    for(char dig='1';dig<='9';dig++)
    {
        if(isSafe(board,row,col,dig))
        {
            board[row][col]=dig;
            if(helper(board,nextRow,nextCol))
            {
                return true;
            }
            board[row][col]='.';
        }  
    }
     return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};