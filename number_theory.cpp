namespace number_theory{
    long long gcd(long long x, long long y){
        if(x==0) return y;
        if(y==0) return x;
        return gcd(y,x%y);
    }
    
    bool isprime(long long n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        for(long long i = 5; i*i <= n; i+=6){
            if(n%i==0 || n%(i+2) == 0) return false;
        }
        return true;
    }
    
    long long prime[15000105];
    void sieve(long long n){
        for(int i=0; i<=n; i++)
            prime[i]=1;
        
        prime[0] = prime[1] = 0;
        for(long long i = 2; i*i<=n; i++){
            if(prime[i]==1){
                for(long long j=i*i; j<= n; j+=i){
                    prime[j]=i;
                }
            }
        }
        return;
    }
    
    vector<long long> primelist;
    bool is_generated=0;
    
    void generate_primes(int n){
        is_generated=1;
        sieve(n+1);
        for(int i=2; i<=n; i++)
            primelist.push_back(i);
        return;
    }
    
    vector<pair<long long,long long>> factors(long long n){
        if(is_generated==0){
            cerr<<"call function generate_primes\n";
        }
        vector<pair<long long,long long>> factors;
        
        for(int i=0; primelist[i]*primelist[i]<=n && i < (int)primelist.size(); i++){
            if(n%primelist[i]==0){
                int cnt=0;
                while(n%primelist[i]==0){
                    n /= primelist[i];
                    cnt++;
                }
                factors.push_back({primelist[i],cnt});
            }
        }
        if(n>1){
            factors.push_back({n,1});
        }
        // sort(factors.begin(),factors.end());
        return factors;
    }
    
    vector<long long> getdivisor(long long n){
        vector<long long> divisors;
        for(long long i=1; i*i<=n; i++){
            if(n%i==0){
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
        
        auto it = unique(divisors.begin(),divisors.end());
        divisors.resize(distance(divisors.begin(),it));
        sort(divisors.begin(),divisors.end());
        return divisors;
    }
}

using namespace number_theory;