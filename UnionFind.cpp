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

int main(){
  int N; cin >> N;
  int Q; cin >> Q;
  
  //頂点番号のオフセットは０にする
  UnionFind UF = UnionFind(N);
  for (int i = 1; i <= Q; i++){
    bool Pi; cin >> Pi;
    int Ai, Bi; cin >> Ai >> Bi;
    //判定クエリ
    if (Pi){
      if (UF.isSameGroup(Ai, Bi)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    //連結クエリ
    else{
      UF.unite(Ai, Bi);
    }
  }
  
  return 0;
}
