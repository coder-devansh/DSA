#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Adjacency list for the graph
    unordered_map<string, vector<pair<string, double>>> adj;

    double divide(const string& dividend, const string& divisor, set<string>& vis) {
        if (dividend == divisor) {
            return 1.0; // Return 1 if both variables are the same
        }
        
        vis.insert(dividend); // Mark the current dividend as visited

        for (const auto& it : adj[dividend]) {
            if (vis.find(it.first) == vis.end()) { // Check if not visited
                double ans = divide(it.first, divisor, vis);
                
                if (ans > 0) { // If a valid answer was found
                    return ans * it.second; // Return the computed value
                }
            }
        }

        vis.erase(dividend); // Unmark the dividend
        return -1.0; // Return -1 if no path found
    }

    vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
        // Populate the adjacency list
        for (int i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0]; // Left variable
            const string& v = equations[i][1]; // Right variable
            
            adj[u].emplace_back(v, values[i]); // u -> v with weight values[i]
            adj[v].emplace_back(u, 1.0 / values[i]); // v -> u with weight 1/values[i]
        }

        vector<double> res; // Result vector
        for (const auto& query : queries) {
            const string& start = query[0]; // Get the first variable
            const string& end = query[1]; // Get the second variable
            
            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                res.push_back(-1.0); // No relation exists
            } else {
                set<string> vis; // Set to track visited nodes
                double result = divide(start, end, vis);
                res.push_back(result); // Add the result of the division
            }
        }
        
        return res; // Return the results
    }
};
