template<class T>
struct DSU{
    vector<T>par,sz;
    DSU(int n_):par(n_,0),sz(n_,1){}
    void make(int u){par[u]=u;sz[u]=1;}
    int parent(int u){if(par[u]==u){return u;} return par[u]=parent(par[u]);}
    void join(int u,int v){
        u=parent(u);
        v=parent(v);
        if(u!=v){
            if(sz[u]<sz[v]){
                swap(u,v);
            }
            par[v]=u;
            sz[u]+=sz[v];
        }
    }
};
