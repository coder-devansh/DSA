#include <vector>
#include <string>
#include <utility>

using namespace std;

// Define 'pii' as an alias for 'pair<int, int>'.
using pii = pair<int, int>;

class Solution {
public:

    bool canChange(string start, string target) {
       
        auto startPositions = extractPositions(start);
        auto targetPositions = extractPositions(target);
      
        
        if (startPositions.size() != targetPositions.size()) return false;
      
       
        for (int i = 0; i < startPositions.size(); ++i) {
            auto startPosition = startPositions[i], targetPosition = targetPositions[i];
           
            if (startPosition.first != targetPosition.first) return false;
            
            if (startPosition.first == 1 && startPosition.second < targetPosition.second) return false;
           
            if (startPosition.first == 2 && startPosition.second > targetPosition.second) return false;
        }
      
       
        return true;
    }
    vector<pii> extractPositions(string s) {
        vector<pii> positions;
        for (int i = 0; i < s.size(); ++i) {
           
            if (s[i] == 'L')
                positions.push_back({1, i});
          
            else if (s[i] == 'R')
                positions.push_back({2, i});
        }
        return positions;
    }
};