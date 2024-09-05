template<class T> 
class RK {
private:
    T s;
    int n;
    vector<long long> p_pow;
    vector<long long> inv_pow;
    vector<long long> h;
    int P;
    long long MOD;

public:
    RK(int p, long long mod): P(p), MOD(mod){
        h.clear();
        h.push_back(0);
        n=0;
    }
    RK(T ss,int p, long long mod): s(ss), n(size(ss)), P(p), MOD(mod){
        p_pow.resize(n);
        h.resize(n+1);
        inv_pow.resize(n);
    }
    long long binpow(long long base,long long exp){
        base %= MOD;
        long long res=1;
        while(exp>0){
            if(exp&1) res=res*base%MOD;
            base=base*base%MOD;
            exp>>=1;
        }
        return res;
    }

    int getV(char c){
        if(isupper(c)) {
            return c-'A'+27;
        }
        else if(islower(c)) {
            return c-'a'+1;
        }
        return c-'0'+53;
    }

    void add(char c){
        if(n==0) {
            p_pow.push_back(1);
            n++;
        }
        else {
            p_pow.push_back(p_pow.back()*P%MOD);
        }
        inv_pow.push_back(binpow(p_pow.back(),MOD-2));
        long long v=(h.back()+(getV(c))*p_pow.back())%MOD ;
        h.push_back(v);

    }

    void HASH(){
        p_pow[0]=1;
        for(int i=1;i<n;i++){
            p_pow[i]=(p_pow[i-1]*P)%MOD;
        }
        for(int i=0;i<n;i++){
            inv_pow[i]=binpow(p_pow[i],MOD-2);
        }
        h[0]=0;
        for(int i=0;i<n;i++){
            h[i+1]=(h[i]+(getV(s[i]))*p_pow[i])%MOD; 
        }
    }

    long long lr_hash(int l,int r){
        long long cur_h=(h[r+1] + MOD - h[l]) % MOD;
        cur_h=(cur_h%MOD*inv_pow[l]%MOD)%MOD;
        return cur_h;
    }   
};

// calculate p_pow and inv_pow outside of the class if needed or in case of timelimit
