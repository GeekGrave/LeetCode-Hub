#define F first
#define S second
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>> q;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]==1){
                    ar[i][j] = 0;
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = p.F + dx[i];
                int ny = p.S + dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m and vis[nx][ny]==0){
                    ar[nx][ny] = ar[p.F][p.S] + 1;
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ar;
    }
};