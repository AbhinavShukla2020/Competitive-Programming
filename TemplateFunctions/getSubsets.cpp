vector<vector<int>> getSubsets(const vector<int>& in){
    vector<vector<int>> ans={{}};
    for(const int &i : in){
        ans.resize(2*ans.size());
        for(int j=0;j<ans.size()/2;j++){
            ans[ans.size()/2+j]=ans[j];
            ans[ans.size()/2+j].push_back(i);
        }
    }
    return ans;
}
