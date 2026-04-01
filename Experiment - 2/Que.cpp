#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicates = 1;
            int maxLine = 0;
            
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                
                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                string slope = to_string(dx) + "/" + to_string(dy);
                mp[slope]++;
                
                maxLine = max(maxLine, mp[slope]);
            }
            
            result = max(result, maxLine + duplicates);
        }
        
        return result;
    }
};
