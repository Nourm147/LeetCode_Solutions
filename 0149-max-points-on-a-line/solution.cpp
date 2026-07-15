class Solution {
public:


    double round(double val) {
        if (val == 0.0) return 0.0;

        double scale = std::pow(10.0, 8.0 - std::ceil(std::log10(std::abs(val))));
        return std::round(val * scale) / scale;
    }

    int maxPoints(vector<vector<int>>& points) {

        map<pair<double, double>, long long> mp;
        long long ans = 0;;

        for(int i = 0; i < points.size(); i++){
            mp.clear();
            for(int j = 0; j < points.size(); j++){

                if(j == i)
                    continue;

                pair<double, double> p = {points[i][0] - points[j][0], points[i][1] - points[j][1]};

                if(p.first < 0)
                {
                    p.first *= -1;
                    p.second *= -1;
                }
                
                double mag = sqrt(p.first * p.first + p.second * p.second);
                
                p.first = round(p.first / mag);
                p.second = round(p.second / mag);

                    mp[p]++;

                ans = max(ans, mp[p]);
            }
        }

        return ans + 1;
    }
};
