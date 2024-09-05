class Trie{
private:
    vector<vector<int>> t;
    const int max_size = 1e5+7;
    int cnt;
    int root;
    int newC(){
        return ++cnt;
    }

public:
    Trie(int mx,int k): cnt(0), root(newC()){
        t.resize(mx+100,vector<int>(26));
    }
    Trie(int k):cnt(0), root(newC()){
        t.resize(max_size+100,vector<int>(26));
    }

    void add(string &s){
        int n=s.length();
        int v = root;
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(t[v][c] == 0) t[v][c]=newC();
            v=t[v][c];
        }
    }

    int Root(){
        return root;
    }

    friend void dfs(int v,Trie&);
};
