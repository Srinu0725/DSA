class Solution {
public:
int m,n;
int dp[105][105][205];
bool solve(int i,int j,int balance,vector<vector<char>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    if(i>=m || j >= n)return false;
    if(grid[i][j] == '('){
        balance++;
    }else{
        balance--;
    }
    if(balance < 0) return false;
    
    if(i == m-1 && j==n-1)
        return balance == 0;
    if(dp[i][j][balance] != -1) return dp[i][j][balance];

    return dp[i][j][balance] = (solve(i+1,j,balance,grid) ||
    solve(i,j+1,balance,grid));

}
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        if(grid[0][0] != '(' || grid[m-1][n-1] != ')') return false;

        if((m+n-1)%2 == 1) return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};