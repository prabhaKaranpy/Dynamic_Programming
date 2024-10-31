class Solution {       // MY OWN SOLUTION GOT ACCEPTED :) (SPENT TWO DAYS TO DO IT IN MY OWN)
public:
    int f(int i, int j, int &n, int &m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        // base case
        // if(j >= m) return 0; 
        // if(i >= n || i < 0) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        int straight = 0; 
        if(j+1 < m && grid[i][j] < grid[i][j+1]) straight = 1 + f(i, j+1, n, m, grid, dp); 
        int up = 0; 
        if(i-1 >= 0 && j+1 < m && grid[i][j] < grid[i-1][j+1]) up = 1 + f(i-1, j+1, n, m, grid, dp); 
        int down = 0; 
        if(i+1 < n && j+1 < m && grid[i][j] < grid[i+1][j+1]) down = 1 + f(i+1, j+1, n, m, grid, dp); 
        int temp = max(max(up, down), straight);
        // cout<<"Temp : "<<temp<<" "<<i<<" "<<j<<"   "; 
        return dp[i][j] = temp;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        // cout<<n<<"   "<<m<<endl; 
        int maxi = 0; 
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        for(int i = 0; i < n; i++){
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++) cout<<dp[i][j]<<"  ";
            //     cout<<endl;  
            // }
            maxi = max(maxi, f(i, 0, n, m, grid, dp)); 
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++){
            //         dp[i][j] = -1;      // NO NEED TO RESET THE DP TO -1, BOTH WILL WORK AS FINE
            //     }
            // }
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++) cout<<dp[i][j]<<"  ";
            //     cout<<endl;  
            // }
        }
        return maxi <= 0 ? 0 : maxi; 
    }
};
