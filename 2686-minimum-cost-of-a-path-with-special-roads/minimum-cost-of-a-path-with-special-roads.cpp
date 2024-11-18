class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // Lambda function to calculate Manhattan distance between two points
        auto calculateDistance = [](int x1, int y1, int x2, int y2) {
            return std::abs(x1 - x2) + std::abs(y1 - y2);
        };

        // Initialize the answer to a large number
        int minimumCost = INT_MAX;
        // Define a very large value to be used as a hashing multiplier
        int hashMultiplier = 1e6;
        // Priority queue to maintain the frontier of the search
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<std::tuple<int, int, int>>> frontier;

        // Push the starting position with cost 0 into the priority queue
        frontier.push({0, start[0], start[1]});
       map<pair<long long ,long long>,int>mp;
        // Set to keep track of visited positions
        std::unordered_set<long long> visited;

        while (!frontier.empty()) {
            // Dequeue the closest (in terms of cost) position from the frontier
            auto [currentCost, currentX, currentY] = frontier.top();
            frontier.pop();

            // Calculate the hash value of the current position
            long long hashValue = static_cast<long long>(currentX) * hashMultiplier + currentY;
          
            if (mp.find({currentX,currentY})!=mp.end()) {
                // Skip if this position has already been visited
                continue;
            }
          
            // Mark the current position as visited
            mp[{currentX,currentY}]++;

            // Update minimum cost considering the current path and direct path to the target
            minimumCost = std::min(minimumCost, currentCost + calculateDistance(currentX, currentY, target[0], target[1]));

            // For each special road, calculate costs and push new positions to the queue
            for (auto& road : specialRoads) {
                int startRoadX = road[0], startRoadY = road[1];
                int endRoadX = road[2], endRoadY = road[3];
                int roadCost = road[4];

                // Calculate cost to the start of the special road plus the road's cost
                int newCost = currentCost + calculateDistance(currentX, currentY, startRoadX, startRoadY) + roadCost;

                // Push the special road's end position with the updated cost into the queue
                frontier.push({newCost, endRoadX, endRoadY});
            }
        }

        // Return the calculated minimum cost
        return minimumCost;
    }
};