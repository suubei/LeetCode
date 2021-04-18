#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;
    dfs(rooms, 0, visited);
    return visited.size() == rooms.size();
  }

 private:
  void dfs(vector<vector<int>>& rooms, int cur, unordered_set<int>& visited) {
    if (visited.count(cur)) return;
    visited.insert(cur);
    for (int nxt : rooms[cur]) {
      dfs(rooms, nxt, visited);
    }
  }
};