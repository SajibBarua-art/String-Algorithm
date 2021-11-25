// Problem link: https://www.spoj.com/problems/NHAY/

#include<bits/stdc++.h>
using namespace std;
 
#define fl(st, en, i) for(int i = st; i < en; i++)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define Case(c) cout << "Case " << c << ": "
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define el "\n"
const int mod = 1e9+7;

ll PRH(string s, int n) {
    ll p = 31;
	ll p_power = 1;

    ll result = s[0]-'a'+1;
    
    for(int i=1; i<n; i++) {
        p_power = (p_power * p) % mod;
        result = (result + (s[i]-'a'+1) * p_power) % mod;
    }

    return result;
}

const int range = 1e6+5;
ll dp[range];
ll inv[range];

ll power(ll a, ll n) {
    ll res = 1;

    while(n) {
        if(n&1) res = (res * a)%mod;

        n >>= 1;
        a = (a * a)%mod;
    }

    return res;
}

void init(string s) {
    ll p = 31;
    ll p_power = 1;

    dp[0] = s[0]-'a'+1;
    inv[0] = 1;

    for(int i=1; i<s.size(); i++) {
        p_power = (p_power * p)%mod;
        dp[i] = (dp[i-1] + (s[i]-'a'+1) * p_power) % mod;
        inv[i] = power(p_power, mod-2);
    }
}

ll substringHash(int l, int r) {
    ll res = dp[r];
    if(l>0) res = (res - dp[l-1] + mod)%mod;

    res = (res * inv[l]) % mod;

    return res;
}

int main() {
	int n;
	
	while(cin >> n) {
        string sub, s; cin >> sub >> s;

        ll sub_hash = PRH(sub, n);

        init(s);

        int flag = 1;

        for(int l = 0, r = n-1; r<s.size(); l++, r++) {
            if(substringHash(l, r) == sub_hash) {
                cout << l << el;
                flag = 0;
            }
        }

        if(flag) cout << el;
    }
}