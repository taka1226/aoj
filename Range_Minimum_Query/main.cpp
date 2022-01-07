#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1 << 17;
const ll INF = (1 << 31) - 1;
//input
int n;
ll dat[MAX_N * 2 + 5];

int N, Q;

void init(int n_){
    n = 1;
    while (n < n_) n *= 2;

    //すべての値をINF
    for (int i=0;i<2 * n - 1;i++)dat[i] = INF;
}

//index k を a に変更
void update(int k, ll a){
    k += n - 1;
    dat[k] = a;
    while (k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

//[a, b) の最小値を求める
ll query(int a, int b, int k, int l, int r){
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];
    else{
        ll v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(v1, v2);
    }
}

int main(){
    cin >> N >> Q;
    init(N);
    for (int i=0;i<Q;i++){
        int com;cin >> com;
        if (com == 0){
            int x;
            ll y;
            cin >> x >> y;
            update(x, y);
        }else if (com == 1){
            int x, y;
            cin >> x >> y;
            cout << query(x, y+1, 0, 0, n) << endl;
        }
    }
    return 0;
}
