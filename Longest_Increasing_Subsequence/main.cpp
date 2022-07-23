#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll INF = LLONG_MAX;
const int MAX_N = 100005;

int N;
ll A[MAX_N];

int main(){
    cin >> N;
    vector<ll> dp(N, INF);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    for (int i=0;i<N;i++){
        int index = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[index] = A[i];
    }

    int ans = 0;
    for (int i=0;i<N;i++){
        if (dp[i] != LLONG_MAX){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
