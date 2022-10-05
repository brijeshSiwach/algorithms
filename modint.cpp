namespace modint{
	long long add(long long a, long long b){
		return (a+b)%mod;
	}

	long long sub(long long a, long long b){
		return ((a-b)%mod + mod)%mod;
	}

	long long mul(long long a, long long b){
		return ((a%mod)*(b%mod))%mod;
	}

	long long binpow(long long base, long long power){
		base%=mod;
		long long res=1;
		while(power>0){
			if(power&1){
				res=(res*base)%mod;
			}
			base=(base*base)%mod;
			power>>=1;
		}
		return res;
	}

	long long inverse(long long a){
		return binpow(a,mod-2)%mod;    // Fermat's Little Theorem
	}

	long long divide(long long a, long long b) { // a/b
		return mul(a,inverse(b));
	}

	static const int SIZE = 1.1e6;
	long long fact[SIZE], ifact[SIZE];

	bool is_generated=0;
	void generate_factorial(long long n){
		is_generated=1;

		fact[0]=fact[1]=1; 
		for(int i=2; i<=n; i++){
			fact[i]=(fact[i-1]*i)%mod;
		}

		ifact[0]=ifact[1]=1;
		ifact[n]=inverse(n);
		for(int i = n - 1; i >= 2; i--){
			ifact[i]=((i+1)*ifact[i+1])%mod;
		}
	}

	long long ncr(long long n, long long r){
		if(is_generated==0){
			cerr << "Call generate_factorial function" << endl;
			exit(1);
		}
		if(r<0||n<r) return 0;
		long long den = (ifact[r]*ifact[n-r])%mod;
		return (fact[n]*den)%mod;
	}

}

using namespace modint;


