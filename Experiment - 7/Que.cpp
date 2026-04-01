#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        // Build graph
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        // Queue: {node, cost}
        queue<pair<int,int>> q;
        q.push({src, 0});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        int stops = 0;
        
        while (!q.empty() && stops <= k) {
            int size = q.size();
            vector<int> temp = dist; // avoid overwriting in same level
            
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (auto &[next, price] : adj[node]) {
                    if (cost + price < temp[next]) {
                        temp[next] = cost + price;
                        q.push({next, temp[next]});
                    }
                }
            }
            
            dist = temp;
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
