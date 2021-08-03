#define f(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    int n,m;
    int c,newc;
    void dfs(int i, int j,vector<vector<int> > &ar){
        cout<<i<<" "<<j<<endl;
        if(i<0 or i>=n or j<0 or j>=m) return;
        if(ar[i][j]!=c) return;
        
        ar[i][j] = newc;
        dfs(i-1,j,ar);
        dfs(i+1,j,ar);
        dfs(i,j-1,ar);
        dfs(i,j+1,ar);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        cout<<n<<" "<<m<<endl;
        c = image[sr][sc];
        newc = newColor;
        if(c==newc) return image;
        dfs(sr,sc,image);
        return image;
    }
};