#include "iostream"

using namespace std;

template<typename T> 

class priority_queue{
private:
    const int max_size = 1e6;
    T *arr;
    int p;

    bool compare(const T &a, const T &b){
        return a[0] < b[0];
    }

public:
    priority_queue (){
        p = 0;
        arr = new int [max_size];
    }

    void push(const T &e){
        if(p == max_size){
            throw "overflow";
        }
        p++;
        arr[p] = e;
        int l = p;
        for(int i = p / 2; i >= 1; i /= 2){
            if(arr[i] > e){
                swap(arr[i], arr[l]);
                l = i;
            }
            else break;
        }
    }

    void pop(){
        if(p == 0){
            throw "underflow";
        }

        swap(arr[p], arr[1]);
        int l = 1;
        p--;
        for(int i = 1; i <= p; ){
            int j = 2 * i; 
            int k = 2 * i + 1;
            if(k <= p){
                if(arr[j] < arr[l] && arr[k] < arr[l]){
                    if(arr[j] < arr[k]){
                        swap(arr[j], arr[l]);
                        l = j;
                    }
                    else {
                        swap(arr[k], arr[l]);
                        l = k;
                    }
                }
                else if(arr[j] < arr[l]){
                    swap(arr[j], arr[l]);
                    l = j;
                }
                else if(arr[k] < arr[l]){
                    swap(arr[k], arr[l]);
                    l = k;
                }
                else break;
            }
            else if(j <= p){
                if(arr[j] < arr[l]){
                    swap(arr[j], arr[l]);
                    l = j;
                }
                else break;
            }
            else break;
        }

    }

    T top(){
        if (p == 0){
            throw "underflow";
        }

        return arr[1];
    }

};


int main(){
    priority_queue<int> pq;

    
    
    return 0;
}