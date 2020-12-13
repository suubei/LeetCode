// Design HashMap
#include <vector>

using namespace std;

class MyHashMap {
 public:
  MyHashMap() { v.resize(1000000, -1); }

  void put(int key, int value) { v[key] = value; }

  int get(int key) { return v[key]; }

  void remove(int key) { v[key] = -1; }

 private:
  vector<int> v;
};