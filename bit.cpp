template <class T> class BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;

  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    /** Sets the value at index ind to val. */
    void set(int ind, T val) { add(ind, val - arr[ind]); }

    /** Adds val to the element at index ind. */
    void add(T val,int ind) {
        // ind++;
        for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
    }

    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind) {
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
        return total;
    }
    T get_ind(int k){
        T x=0;
        for(int i=19;i>=0;i--){
            if((x|(1<<i)) <= size && bit[x+(1<<i)] < k){
                k-=bit[x+(1<<i)];
                x|=(1<<i);
            }
        }
        return x+1;
    }
};
