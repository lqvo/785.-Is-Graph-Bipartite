#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {       
        unordered_map<int, bool>A, B;
        vector<bool>visited(graph.size(), false);        
        bool ans = true;        
        for (int p = 0; p < graph.size(); p++) {
            if (graph[p].empty()||visited[p])continue;
            A[p] = true;
            dfs(p, graph, visited, A, B, ans);
        }      
        return ans;
    }
    void dfs(int p,vector<vector<int>>& graph, vector<bool>& visited, unordered_map<int, bool>&A, unordered_map<int, bool>&B,bool &ans) {
        if (check(visited))return;
        if (visited[p])return;
        visited[p] = true;
        if(A[p])
            for (int i = 0; i < graph[p].size(); i++) {
                if (A[graph[p][i]]) {
                    ans = false; return;
                }
                else { B[graph[p][i]] = true;
                dfs(graph[p][i], graph, visited, A, B, ans);
                }
            }
        else if (B[p])
                for (int i = 0; i < graph[p].size(); i++) {
                    if (B[graph[p][i]]) {
                        ans = false; return;
                    }
                    else { A[graph[p][i]] = true; 
                    dfs(graph[p][i], graph, visited, A, B, ans);
                    }
                }
    }
    bool check(vector<bool>& visited) {
        for (int i = 0; i < visited.size(); i++)
            if (visited[i] == false)return false;
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<int>>graph = { {2,4},{2,3,4},{0,1},{1},{0,1},{7},{9},{5},{},{6},{12,14},{},{10},{},{10},{19},{18},{},{16},{15},{23},{23},{},{20,21},{},{},{27},{26},{},{},{34},{33,34},{},{31},{30,31},{38,39},{37,38,39},{36},{35,36},{35,36},{43},{},{},{40},{},{49},{47,48,49},{46,48,49},{46,47,49},{45,46,47,48} };
    cout << sol.isBipartite(graph);
    return 0;
}