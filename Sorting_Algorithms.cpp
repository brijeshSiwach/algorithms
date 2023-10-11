#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
 
#define all(x) x.begin(), x.end()
#define nl cout<<"\n"
#define ar  array
#define PRECISION 9
#define fast_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define clock() cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

#ifdef LOCAL
#include "../Library/debug.h"
#else 
#define dbg(...) "OM BHOLE"
#endif

template <typename T>
class Priority_queue{
private:
	T * arr;
	int p, n;

public:
	Priority_queue(int n_): p(0), n(n_){
		arr = new T[n+1];
	}

	void push(int e){
		p++;
		arr[p] = e;
		int l = p;
		for(int i = p/2; i >= 1; i /= 2){
			if(arr[l] < arr[i]){
				swap(arr[l], arr[i]);
				l = i;
			}
			else break;
		}
	}

	void pop(){
		swap(arr[p], arr[1]);
		p--;
		for(int i=1; i <= p;){
			int j = 2*i;
			int k = 2*i + 1;
			if(k <= p){
				if(arr[j] < arr[i] && arr[k] < arr[i]){
					if(arr[j] < arr[k]){
						swap(arr[j], arr[i]);
						i = j;
					}
					else {
						swap(arr[k], arr[i]);
						i = k;
					}
				}
				else if(arr[j] < arr[i]){
					swap(arr[j], arr[i]);
					i = j;
				}
				else if(arr[k] < arr[i]) {
					swap(arr[k], arr[i]);
					i = k;
				}
				else break;
			}
			else if(j <= p){
				if(arr[j] < arr[i]){
					swap(arr[j], arr[i]);
					i = j;
				}
				else break;
			}
			else break;
		}
	}

	T top(){
		return arr[1];
	}
};

template <typename T> 
class Sorting_Algorithms{
public:
	vector<T> Merge_sort(int L, int R, vector<T> &a){
		if(L > R){
			return {};
		}
		if(L == R){
			return {a[L]};
		}
		int MID = (L + R) >> 1;
		vector<T> left = Merge_sort(L, MID, a);
		vector<T> right = Merge_sort(MID+1, R, a);

		vector<T> sorted;
		int N = left.size(), i = 0;
		int M = right.size(), j = 0;

		while(i < N && j < M){
			if(left[i] > right[j]){
				sorted.push_back(right[j]);
				j++;
			}
			else {
				sorted.push_back(left[i]);
				i++;
			}
		}
		while(i < N){
			sorted.push_back(left[i]);
			i++;
		}
		while(j < M){
			sorted.push_back(right[j]);
			j++;
		}
		return sorted;
	}

	vector<T> Count_sort(vector<T> &a){
		int mx = 0;
		for(auto x : a){
			mx = max(mx, x);
		}
		vector<int> f(mx + 1);
		for(auto x: a){
			f[x]++;
		}
		vector<T> sorted;
		for(int i = 0; i <= mx; i++){
			for(int j = 0; j < f[i]; j++){
				sorted.push_back(i);
			}
		}
		return sorted;
	}

	vector<T> Radix_sort(vector<T> &a){
		vector<T> sorted = a;
		for(int i = 0; i < 18; i++){
			vector<vector<T>> digits(10, vector<T> ());
			long long d = 1;
			for(int j = 0; j < i; j++){
				d *= 10;
			}
			for(int j = 0; j<(int)sorted.size(); j++){
				int digit = (sorted[j] / d) % 10;
				digits[digit].push_back(j);
			}
			vector<T> c;
			for(int j=0; j<10; j++){
				for(int k=0; k<(int)digits[j].size(); k++){
					c.push_back(sorted[digits[j][k]]);
				}
			}
			sorted = c;
		}
		return sorted;
	}

	void Quick_sort(int L, int R, vector<T> &a,int cnt=1){
		if(L >= R){
			return;
		}
		int pivot = L;
		int RHP = pivot+1, LHP = R;
		while(true){
			while(RHP <= R && a[RHP] <= a[pivot]){
				RHP++;
			}
			while(LHP > pivot && a[LHP] >= a[pivot]){
				LHP--;
			}
			if(RHP > LHP){
				if(LHP > pivot){
					swap(a[pivot], a[LHP]);
					pivot = LHP;
				}
				break;
			}
			else {
				swap(a[RHP], a[LHP]);
				RHP = pivot+1;
				LHP = R;
			}
		}
		Quick_sort(L, pivot-1, a,cnt++);
		Quick_sort(pivot+1,R, a,cnt++);
	}

	vector<T> Insertion_sort(vector<T> &a){
		vector<T> b;
		for(auto x: a){
			b.push_back(x);
			int i = (int)b.size()-1;
			while(i > 0 && b[i] < b[i-1]){
				swap(b[i], b[i-1]);
				i--;
			}
		}
		return b;
	}

	void Selection_sort(vector<T> &a){
		for(int i = 0; i < (int)a.size(); i++){
			T mn = a[i];
			int mni = i;
			for(int j = i+1; j < (int)a.size(); j++){
				if(a[j] < mn){
					mn = a[j];
					mni = j;
				}
			}
			a[mni] = a[i];
			a[i] = mn;
		}
	}

	void Heap_sort(vector<T> &a){
		int n = a.size();
		Priority_queue<T> pq{n};
		for(auto x : a){
			pq.push(x);
		}
		for(int i = 0; i < n; i++){
			a[i] = pq.top();
			pq.pop();
		}
	}

	void Bubble_sort(vector<T> &a){
		int n = a.size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - 1; j++){
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
				}
			}
		}
	}

	void Shell_sort(vector<T> &a){
		int n = a.size();
		for(int i = n/2; i > 0; i /= 2){
			for(int j = 0; j < n; j++){
				for(int k = j; k >= i && a[k - i] > a[k]; k -= i){
					swap(a[k - i], a[k]);
				}
			}
		}
	}

	void Cocktail_shaker_sort(vector<T> &a){
		for(int i = 0; i < (int)a.size(); i++){
			for(int j = i; j < (int)a.size()-1-i; j++){
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
				}
			}
			for(int j=(int)a.size()-1-i; j > i; j--){
				if(a[j] < a[j-1]){
					swap(a[j], a[j-1]);
				}
			}
		}
	}

	void Gnome_sort(vector<T> &a){
		int i = 0;
		while(i < (int)a.size()){
			if(i == 0) i++;
			if(a[i] > a[i-1]){
				i++;
			}
			else{
				swap(a[i], a[i-1]);
				i--;
			}
		}
	}

	void Bitonic_sort(vector<T> &a){
		
	}
};

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		// cin >> a[i];
		a[i] = rand() % 100000000 + 1;
	}
	dbg(a);
	vector<int> b=a;
	sort(all(b));
	// dbg(b);
	Sorting_Algorithms<int> Sort;
	Sort.Gnome_sort(a);
	for(int i = 0; i < n; i++){
		cout<<a[i]<< " ";
	}
	cout<<"\n";
	dbg(b);
	dbg(a);
}