#include<bits/stdc++.h>
using namespace std;

//const
const int MAX_V = 1e4 + 5;
//input
int V, E;
vector<int> G[MAX_V];

int indegree[MAX_V];
vector<int> out;
queue<int> que;
bool color[MAX_V];

void bfs(int first){
    que.push(first);
    color[first] = true;
    int q, r;
    while (!que.empty()){
        q = que.front();que.pop();
        out.push_back(q);
        for (int i=0;i<G[q].size();i++){
            r = G[q][i];
            indegree[r]--;
            if (!color[r] && indegree[r] == 0){
                color[r] = true;
                que.push(r);
            }
        }
    }
}

int main(){
    cin >> V >> E;
    int s, t;
    for (int i=0;i<E;i++){
        cin >> s >> t;
        G[s].push_back(t);
        indegree[t] += 1;
    }

    int first;
    for (int i=0;i<V;i++){
        if (indegree[i] == 0){
            first = i;
            break;
        }
    }

    //color 初期化
    for (int i=0;i<V;i++){
        color[i] = false;
    }

    for (int i=0;i<V;i++){
        if (!color[i] && indegree[i] == 0){
            bfs(i);
        }
    }


    for (int i=0;i<out.size();i++){
        cout << out[i] << endl;
    }


    return 0;
}
