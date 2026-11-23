class ProductOfNumbers {
public:
    vector<long long> v;
    vector<int> z;
    ProductOfNumbers() {
        v.push_back(1);
        z.push_back(0);
    }
    
    void add(int num) {
        if(num == 0)
            v.push_back(1);
        if(num != 0){
            v.push_back((1LL) * num * v.back());
        }
        z.push_back(z.back() + ((num == 0) ? 1 : 0));
    }
    
    int getProduct(int k) {
        int zsum = z.back() - z[z.size() - k - 1];
        if(zsum == 0)
            return v.back() / v[v.size() - k - 1];
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */