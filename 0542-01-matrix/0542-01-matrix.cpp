class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(); int m= mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j]==0){
                    vis[i][j]=0;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        int dx[]= {0,0,1,-1};
        int dy[]= {1,-1,0,0};
        while (!q.empty()){
            int x= q.front().first.first;
            int y= q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[x][y]=dis;
            for (int i=0; i<4; i++){
                int nr = x+dx[i];
                int nc = y+dy[i];
                if (nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] && mat[nr][nc]==1){
                    vis[nr][nc]=0;
                    ans[nr][nc]= dis;
                    q.push({{nr,nc},dis+1});
                }
            }
        }
        return ans;
    }
};