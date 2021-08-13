#define vll             vector<int>
#define mll             map<int,int>
#define pll             pair<int,int>
#define vpll            vector<pair<int,int>>
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
#define to_low(s)       transform(s.begin(), s.end(), s.begin(), ::tolower);//convert string to lowercase
#define to_up(s)        transform(s.begin(), s.end(), s.begin(), ::toupper);//convert string to uppercase
#define popcount        __builtin_popcount     //used to count number of set bits in a integer
#define llpopcount      __builtin_popcountll
#define f(i,n)          for(int i=0;i<n;i++)
#define fin(i,c,n)      for(int i=c;i<n;i++)
#define fer(i,c,n)      for(int i=c;i>=n;i--)
#define fill(a, x)      memset(a, x, sizeof(a))
#define mod             1000000007
#define no              cout<<"NO\n"
#define yes             cout<<"YES\n"
#define ln              cout<<"\n";
class Solution {
public:
    int orangesRotting(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int vis[n][m];
        memset(vis,-1,sizeof(vis));
        queue <pair<pair<int,int>, int> >q;
        int ctr=0;
        f(i,n){
            f(j,m){
                if(ar[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 0;
                }
                if(ar[i][j]==1) ctr=1;
            }
        }
        if(q.empty() and ctr==0) return 0;
        if(q.empty() and ctr==1) return -1;
        while(!q.empty()){
            pair<pll,int> p = q.front();
            q.pop();
            f(i,4){
                int nx = p.F.F + dx[i];
                int ny = p.F.S + dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and ar[nx][ny]==1 and vis[nx][ny]==-1){
                    q.push({{nx,ny},p.S + 1});
                    vis[nx][ny] = p.S + 1;
                }
            }
        }
        int maxt = INT_MIN;
        f(i,n){
            f(j,m){
                if(ar[i][j]==1 and vis[i][j]==-1){
                    cout<<-1<<endl;
                    return -1;
                }else{
                    maxt = max(maxt,vis[i][j]);
                }
            }
        }
        cout<<maxt<<endl;    
        return maxt;
    }
};