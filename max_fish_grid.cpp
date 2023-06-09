// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

// for 4 directional dfs
vector<pair<int,int>> v={
    {1,0},{0,1},{-1,0},{0,-1}
};

// validate function
bool vd(int i,int j,int n,int m){
    return i>=0 && j>=0 && i<n && j<m;
}
//dfs function
int dfs(int i,int j,int n,int m,vector<vector<int>>&g){
     int x=g[i][j];
     cout<<x<<endl;
     g[i][j]=0;
     int ans=0;
     for(auto&it : v){
         int X=i+it.first;
         int Y=j+it.second;
         if(!vd(X,Y,n,m) || g[X][Y]==0) continue;
         ans+=dfs(X,Y,n,m,g);
     }
     return ans+x;
}


    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]) ans = max(ans,dfs(i,j,n,m,grid));
            }
        }
        return ans;
    }
};
