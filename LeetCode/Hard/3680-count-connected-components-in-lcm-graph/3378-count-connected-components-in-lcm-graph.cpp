class Solution {
public:

    vector<int> parent;

    int getParent(int u){
        if(parent[u] > 0){
            return parent[u] = getParent(parent[u]);
        }
        return u;
    }
    
    void unionP(int u, int v)
    {
        int p1 = getParent(u);
        int p2 = getParent(v);

        if(p1 == p2)
            return;
        parent[p2] = p1;
    }

    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        parent.resize(threshold + 1, -1);

        for(int i = 0; i < n; i++)
        {
            int j = 1;
            while(nums[i] * j <= threshold)
            {
                unionP(nums[i], nums[i] * j);
                j ++;
            }
        }

        set<int> s;
        for(int i = 0; i < n; i++){
            if(nums[i] > threshold)
                s.insert(nums[i]);
            else
                s.insert(getParent(nums[i]));
        }

        return s.size();
    }
};