template<class T>
struct sparse_table {
private:
    int n;
    int mxB=20;
    vector<T> a;
    vector<int> lg;
    vector<vector<T>> t;

public:
    sparse_table(int sz,vector<T> &A): n(sz), a(A), lg(sz+1) { // pass by refernece
        t.resize(mxB, vector<T> (n));
    }

    T merge(T x,T y){
        return min(x, y);
    }

    void create(){
        for(int i=0;i<n;i++){
            t[0][i]=a[i];
        }
        for(int i=1;i<mxB;i++){
            for(int j=0;j<n;j++){
                if(j+(1<<(i-1))>=n) continue;
                t[i][j]=merge(t[i-1][j],t[i-1][j+(1<<(i-1))]);
            }
        }
    }
    void fill_lg(){
        for(int i=2;i<=n;i++){
            lg[i]=lg[i/2]+1;
        }
    }

    T query(int l,int r){ // both 0 based indexing;
        T ans=0;
        for(int i=mxB-1; i>=0; i--){
            if((1<<i)<=r-l+1){
                ans = merge(ans,t[i][l]);
                l+=(1<<i);
            }
        }
        return ans;
    }

    T query_idem(int l,int r){ //both 0 based indexing
        int p=lg[r-l+1];
        T ans = merge(t[p][l],t[p][r-(1<<p)+1]);
        return ans;
    }

};

// the array is passed by reference
// l and r should be in 0 based indexing
