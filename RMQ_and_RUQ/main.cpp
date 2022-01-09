#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 1 << 17;
const ll INF = pow(2, 31) - 1;
//input
int N, Q;

int n;
ll dat[MAX_N * 2 + 5];
ll lazy[MAX_N * 2 + 5];
void init(int n_){
    n = 1;
    while (n < n_) n *= 2;
    for (int i=0;i<2*n-1;i++){
        dat[i] = INF;
        lazy[i] = INF;
    }
}

//k番目のノードについて遅延評価を行う
void eval(int k, int l, int r){
    if (lazy[k] != INF){
        dat[k] = lazy[k];

        if (r - l > 1){
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }

        lazy[k] = INF;
    }
}

void update(int a, int b, ll x, int k, int l, int r){
    eval(k, l, r);

    if (b <= l || r <= a) return;

    if (a <= l && r <= b){
        lazy[k] = x;
        eval(k, l, r);
    }

    else{
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
        dat[k] = min(dat[2*k+1], dat[2*k+2]);
    }
}

ll query(int a, int b, int k, int l, int r){
    eval(k, l, r);
    if (b <= l || r <= a)return INF;
    if (a <= l && r <= b) return dat[k];
    ll v1 = query(a, b, 2*k+1, l, (l+r)/2);
    ll v2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(v1, v2);
}

int main(){
    cin >> N >> Q;
    init(N);
    for (int i=0;i<Q;i++){
        int com;cin >> com;
        int s, t;
        if (com == 0){
            ll x;cin >> s >> t >> x;
            update(s, t+1, x, 0, 0, n);
        }else if (com == 1){
            cin >> s >> t;
            cout << query(s, t+1, 0, 0, n) << endl;
        }
    }
    return 0;
}
