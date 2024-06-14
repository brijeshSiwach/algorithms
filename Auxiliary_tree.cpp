vector<int>aux[n+1];
auto aux_tree=[&](int c){

    //vertex in the query
    vector<ar<int,2>> val;
    for(auto v: col[c]){
        val.push_back({st[v],v});
    }
    if(val.empty()) {
        return 0ll;
    }
    sort(all(val));
    int sz=size(val);
    for(int i=1;i<sz;i++){
        int l=get_lca(val[i][1],val[i-1][1]);
        val.push_back({st[l],l});
    }
    sort(all(val));
    val.resize(unique(all(val))-val.begin());
    //create AUX Tree
    vector<int> s;
    sz=size(val);
    s.pb(val[0][1]);
    vector<int> taken;
    taken.push_back(val[0][1]);
    fr(i,1,sz){ 
        while(size(s)>0&&(en[s.back()]<st[val[i][1]])) {
            s.pop_back();
        }
        aux[s.back()].pb(val[i][1]);
        aux[val[i][1]].pb(s.back());
        taken.push_back(val[i][1]);
        taken.push_back(s.back());
        s.pb(val[i][1]);
    }

    long long ans=solve_color(c);

    for(auto x: taken){
        dp1[x]=0;
        dp2[x]=0;
        aux[x].clear();
    }
    return ans;
};
