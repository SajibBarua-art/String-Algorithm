#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int range = 1e6+5;
const int mod = 1e9+7;

// dp[i] means hash value of substring 0 to i
ll dp[range];
// inv[i] means modular inverse value of mod^i
ll inv[range];

ll power(ll a, ll n) {
    ll result = 1;

    while(n) {
        if(n&1) result = (result * a)%mod;

        n >>= 1;
        a = (a * a)%mod;
    }

    return result;
}

void init(string input_string) {
    ll p = 31;
    ll p_power = 1;
    dp[0] = input_string[0] - 'a' + 1;
    inv[0] = 1;

    for(int i = 1; i<input_string.size(); i++) {
        p_power = (p_power * p)%mod;
        inv[i] = power(p_power, mod-2);

        dp[i] = (dp[i-1] + (input_string[i] - 'a' + 1)*p_power)%mod;
    }
}

ll substringHash(int l, int r) {
    ll result = dp[r];
    if(l>0) result -= dp[l-1];

    result = (result * inv[l])%mod;

    return result;
}

int main() {
    string input_string; cin >> input_string;

    int t; cin >> t;

    init(input_string);

    while(t--) {
        int l, r;
        cin >> l >> r;

        cout << substringHash(l, r) << endl;
    }
}