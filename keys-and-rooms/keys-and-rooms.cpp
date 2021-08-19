class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int ar[1001] = {0};
        vector<int> adj[1001];
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
                // adj[rooms[i][j]].push_back(i);
            }
        }
        queue<int> q;
        q.push(0);
        ar[0] = 1;
        for(int i=0;i<n;i++){
            cout<<i<<" -> ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        while(!q.empty()){
            int x = q.front();
            // cout<<x<<" ";
            q.pop();
            for(auto i:adj[x]){
                if(!ar[i]){
                    q.push(i);
                    ar[i] = 1;
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if(!ar[i])
                return false;
        }
        return true;   
    }
};