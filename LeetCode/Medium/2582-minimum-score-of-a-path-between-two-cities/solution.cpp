class Solution {
public:

    int findParent(int ind, vector<int>& parent){
        if(parent[ind] < 0){
            return ind;
        }
        else{
            parent[ind] = findParent(parent[ind], parent);
            return parent[ind];
        }
    }

    void tryConnect(int a, int b, vector<int>& parent){
        int pa = findParent(a, parent);
        int pb = findParent(b, parent);

        if(pa == pb)
            return;
        if(pa <= pb){
            parent[pa] += parent[pb];
            parent[pb] = pa;
        }else{
            parent[pb] += parent[pa];
            parent[pa] = pb;
        }
    }
    bool isConnected(int a, int b, vector<int>& parent){
        int pa = findParent(a, parent);
        int pb = findParent(b, parent);

        if(pa == pb)
            return true;
        else
            return false;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n, -1);
        int minDis = INT_MAX;
        for(int i = 0; i < roads.size(); i++){
            tryConnect(roads[i][0] - 1, roads[i][1] - 1, parent);
        }
        for(int i = 0; i < roads.size(); i++){
            if(isConnected(0, roads[i][0] - 1, parent)){
                minDis = min(minDis, roads[i][2]);
            }
        }
        return minDis;
    }
};
