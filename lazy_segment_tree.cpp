
template<class T> 
class SegmentTree{
public:
    int N; // this should be (b.size()-1)
    vector<T> t;
    vector<T> lazy;
 
    SegmentTree(int n, vector<int> b):N(n),t(4*n+1){ 
        build(1, 1, N, b);
    }
     
    SegmentTree(int n):N(n), t(4*n+2), lazy(4*n+2){}
 
    T merge(T a, T b){
        return a+b;
    }
    
    void lazyUpdate(int i, int lb, int rb, T val){
        if(lb != rb) {
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
        lazy[i]=0;
        return;
    }
 
    void pushDown(int i){
    	if(lazy[i]==0) return;
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
        lazy[i]=0;
        return;
    }
    
    T apply(int i, int lb, int rb, T val){
        return t[i] + (rb - lb + 1) * val;
    }
 
    void build(int i, int l, int r, vector<int> &b){
        if(l > r) return;
        if(l == r){
            t[i] = b[l];
            return;
        }
        int mid = (l+r) >> 1;
        build(2*i, l, mid, b);
        build(2*i+1, mid+1, r, b);
        t[i] = merge(t[2*i],t[2*i + 1]);
    }
 
    void print(){
        for(int i = 0; i < 4*N; i++){
            cout << t[i] << " ";
        }
    }
 
 
    void update(int i, int l, int r, int pos, T val){
        if(l > pos || r < pos) return;
        if(l == pos && r == pos){
            t[i] += val;
            return;
        }
        int mid = (l+r)>>1;
        update(2*i, l, mid, pos, val);
        update(2*i+1, mid+1, r, pos, val);
        t[i] = merge(t[2*i], t[2*i+1]);
    }
 
    void updateRange(int i, int l, int r, int lb, int rb, T val){
        if(lazy[i] != 0){
            t[i]=apply(i,l,r,lazy[i]);
            if(l!=r) pushDown(i);
            else lazy[i]=0;
        }
        if(r < lb || l > rb) return;
 
        if(lb<=l && r <= rb){
            t[i] = apply(i,l,r,val);
            lazyUpdate(i, l, r, val);
            return;
        }
        int mid=(l+r)>>1;
        updateRange(2*i,l,mid,lb,rb,val);
        updateRange(2*i+1,mid+1,r,lb,rb,val);
        t[i]=merge(t[2*i],t[2*i+1]);
    }
 
    T queryLazy(int i,int l,int r,int ql,int qr){
        if(lazy[i] != 0){
            t[i]=apply(i,l,r,lazy[i]);
            if(l!=r) pushDown(i);
            else lazy[i]=0;
        }
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return t[i];
        pushDown(i);
        int mid=(l+r)>>1;
        return merge(queryLazy(2*i, l, mid, ql, qr), queryLazy(2*i+1, mid+1, r, ql, qr));
    }
 
    T query(int i, int l, int r, int ql, int qr){        
        if(l > qr || r < ql) return 0;
        if(l >=ql && r <= qr) return t[i];
        int mid = (l+r)>>1;
        return merge(query(2*i, l, mid, ql, qr), query(2*i+1, mid+1, r, ql, qr));
    }
 
    void update(int pos, T val){
        update(1, 1, N, pos, val); 
    }
 
    void updateRange(int lb,int rb,T val){
        updateRange(1, 1, N, lb, rb, val);
    }
 
    T queryLazy(int ql,int qr){
        return queryLazy(1, 1, N, ql, qr);
    }
 
    T query(int ql, int qr){
        return query(1, 1, N, ql, qr);
    }
 
};
