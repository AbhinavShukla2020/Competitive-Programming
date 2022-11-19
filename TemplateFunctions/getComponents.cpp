vector<vector<int>> getComponents(vector<vector<int>> adj){
    //ASSUMING ONE-INDEXED
    //CHANGE TO N=adj.size() IF NOT
    //int N=adj.size()-1;
    bool vis[N];
    vector<vector<int>> components;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int i=1;i<=N;i++){
        vis[i]=false;
    }

    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int a=1;a<=N;a++){
        if(vis[a]==false){
            vector<int> cur;
            stack<int> dfs;
            dfs.push(a);
            vis[a]=true;
            while(!dfs.empty()){
                int k=dfs.top();
                cur.push_back(k);
                dfs.pop();
                for(int i : adj[k]){
                    if(vis[i]==false){
                        dfs.push(i);
                        vis[i]=true;
                    }
                }

            }
            components.push_back(cur);
        }

    }
    return components;
}
