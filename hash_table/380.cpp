#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.count(val)) return false;
    m[val] = v.size();
    v.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!m.count(val)) return false;
    int index = m[val];
    m[v.back()] = index;
    m.erase(val);
    swap(v[index], v.back());
    v.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int index = rand() % v.size();
    return v[index];
  }

 private:
  unordered_map<int, int> m;
  vector<int> v;
};