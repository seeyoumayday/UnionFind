#include <iostream>
#include <vector>
using namespace std;

/* Offset of vertex number is 0. */
class UnionFind{
private:
    // The parents of vertex number i is kept in parents[i].
    vector<int> parents;
public:
    UnionFind(int N);
    int root(int x);
    void unite(int x, int y);
    bool isSameGroup(int x, int y);
};

// In the beginning, every vertex makes itself a parents.
UnionFind::UnionFind(int N){
    parents.resize(N);
    for (int i = 0; i < N; i++) parents[i] = i;
}

// This is Function that returns the root of x.
int UnionFind::root(int x){
    if(parents[x] == x) return x;
    return parents[x] = root(parents[x]);
}

// Put x and y in the same group.
void UnionFind::unite(int x, int y){
    if (root(x) == root(y)) return;
    parents[root(x)] = root(y);
}

bool UnionFind::isSameGroup(int x, int y){
    return root(x) == root(y);
}