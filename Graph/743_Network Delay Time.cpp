/*
743. Network Delay Time
Medium

2310

243

Add to List

Share
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <vector>
#incldue <pair>
#include <queue>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
        for(auto &time : times)
            graph[time[0]].push_back(std::pair<int, int>(time[1], time[2]));
        
        std::vector<long> dist(n, INT_MAX);
        auto comp = [](const std::pair<int, int> &p1, const std::pair<int, int> &p2){
            return p1.first > p2.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> minHeap(comp);
        minHeap.push(std::make_pair(k, 0));
        dist[k - 1] = 0;
        
        while(!minHeap.empty())
        {
            auto cur = minHeap.top();
            minHeap.pop();
            
            auto &node = graph[cur.first];
            for(auto &edge : node)
            {
                if(cur.second + edge.second >= dist[edge.first - 1])
                    continue;
                
                dist[edge.first - 1] = cur.second + edge.second;
                minHeap.push(std::make_pair(edge.first, dist[edge.first - 1]));
            }
        }
        
        long ret = dist[0];
        for(int i = 1; i < dist.size(); ++i)
            ret = std::max(ret, dist[i]);      
        
        return INT_MAX == ret ? -1 : ret;
    }
};
