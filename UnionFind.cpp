#include <iostream>
#include <vector>
using namespace std;

/* Offset of vertex number is 0. */
class UnionFind{
private:
    // The parents of vertex number i is kept in parents[i].
    vector<int> parents;
    int NumberofVertex;
public:
    UnionFind(int N);
    int root(int x);
    void unite(int x, int y);
    bool isSameGroup(int x, int y);
    void clear();
};

// In the beginning, every vertex makes itself a parents.
UnionFind::UnionFind(int N) : NumberofVertex(N){
    parents.resize(N);
    for (int i = 0; i < N; i++) parents[i] = i;
}

// This is Function that returns the root of x.
int UnionFind::root(int x){
    if(parents[x] == x) return x;
    return parents[x] = root(parents[x]);
    /* If you choose not to make the process high speed,
    then use the statement below.*/
    //return root(parents[x]);
}

// Put x and y in the same group.
void UnionFind::unite(int x, int y){
    if (root(x) == root(y)) return;
    parents[root(x)] = root(y);
}

bool UnionFind::isSameGroup(int x, int y){
    return root(x) == root(y);
}

void UnionFind::clear(){
    for (int i = 0; i < NumberofVertex; i++)parents[i] = i;
}

int main(){
  int N; cin >> N;
  int Q; cin >> Q;
  
  UnionFind UF = UnionFind(N);
  for (int i = 1; i <= Q; i++){
    bool Pi; cin >> Pi;
    int Ai, Bi; cin >> Ai >> Bi;
    // Judgement query
    if (Pi){
      if (UF.isSameGroup(Ai, Bi)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    // Concatenation query
    else{
      UF.unite(Ai, Bi);
    }
  }
  
  return 0;
}
