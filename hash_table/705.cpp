#include <vector>

using namespace std;

class MyHashSet {
 public:
  MyHashSet() { v.resize(1000000, false); }

  void add(int key) { v[key] = true; }

  void remove(int key) { v[key] = false; }

  bool contains(int key) { return v[key]; }

 private:
  vector<bool> v;
};