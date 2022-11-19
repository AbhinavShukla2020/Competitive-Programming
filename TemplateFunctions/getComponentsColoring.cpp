//RETURNS MAP OF NODE TO COMPONENT NUMBER VALUES

map<int,int> componentsColoring(vector<vector<int>> adj){
    //ASSUMING ONE-INDEXED
    //CHANGE TO N=adj.size() IF NOT
    //int N=adj.size()-1;
    bool vis[N+1];
    map<int,int> coloring;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int i=1;i<=N;i++){
        vis[i]=false;
    }
    int curColor=1;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int a=1;a<=N;a++){
        if(vis[a]==false){
            stack<int> dfs;
            dfs.push(a);
            vis[a]=true;
            while(!dfs.empty()){
                int k=dfs.top();
                coloring[k]=curColor;
                dfs.pop();
                for(int i : adj[k]){
                    if(vis[i]==false){
                        dfs.push(i);
                        vis[i]=true;
                    }
                }
            }
            curColor++;
        }

    }
    return coloring;
}
