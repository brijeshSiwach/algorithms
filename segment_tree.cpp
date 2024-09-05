template<class T> 
class SegmentTree{
public:
    int N; // this should be (b.size()-1)
    vector<T> t;
 
    SegmentTree(int n, vector<int> b):N(n),t(4*n+1){ 
        build(1, 1, N, b);
    }
     
     SegmentTree(int n):N(n), t(4*n+2){}

    T merge(T a, T b){
        return a+b;
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
        update(2*i +1, mid+1, r, pos, val);
        t[i] = merge(t[2*i], t[2*i+1]);
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
 
    T query(int ql, int qr){
        return query(1, 1, N, ql, qr);
    }
 
};
// check for the update, do you want t[u] += val or t[u] = val;
// also note that the starting index of the segment tree is 1.
