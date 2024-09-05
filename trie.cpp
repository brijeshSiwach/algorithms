struct node {
    vector<node*>a;
    int x;
    node():x(0){
        a.resize(2,nullptr);
    }
};

struct Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    void add(string s) {
        int n=size(s);
        node* r=root;
        fr(i,0,n) {
            int x=s[i]-'0';
            if(r->a[x] == nullptr) {
                node * z=new node();
                r->a[x]=z;
                z->x++;
            }
            else {
                r->a[x]->x++;
            }
            r=r->a[x];
        }
    }
    void rem(string s){
        int n=size(s);
        node*r=root;
        fr(i,0,n){
            int x=s[i]-'0';
            if(r->a[x]->x==1){
                r->a[x]=nullptr;
                break;
            }
            r=r->a[x];
            r->x--;

        }
    }
    ll mx_xr(string s){
        int n=size(s);
        node*r=root;
        ll mx=0;
        fr(i,0,n){
            int x=s[i]-'0';
            int nx=x^1;
            if(r->a[nx] != nullptr && r->a[nx]->x > 0){
                mx |= (1<<(30-i));
                r=r->a[nx];
            }
            else if(r->a[x]!=nullptr){
                r=r->a[x];
            }
            else {
                break;
            }
        }
        return mx;
    }
};  
