class Solution {
    bool isSafe(vector<string> & board, int row,int col,int n)
    {
        //horizontal
        for(int j=0;j<n;j++)
        {
            if(board[row][j]=='Q')
                return false;
        }
        //vertical
        for(int j=0;j<n;j++)
        {
            if(board[j][col]=='Q')
                return false;
        }
        //left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
         for(int i=row,j=col;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;

    }

    void nQueen(vector<string> &board, int row,int n, vector<vector<string>> &ans)
    {
        if(row==n)
        {
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isSafe(board,row, j,n))
            {
                board[row][j]='Q';
                nQueen(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
       
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueen(board,0,n,ans);
        return ans;
    }
};