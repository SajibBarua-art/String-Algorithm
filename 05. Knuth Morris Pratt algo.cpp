// Problem link: https://www.spoj.com/problems/NHAY/
// To search a substring, all the appearence from a given string

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

void KMP(vector<int> pi, int n) {
    for(int i=0; i<pi.size(); i++) 
        if(pi[i] == n) cout << i-2*n << el;
}

void prefixFunction(string s, int n) {
    int l = s.size();
    vector<int> pi(l);

    pi[0] = 0;

    for(int i = 1; i<l; i++) {
        int j = pi[i-1];

        while(j>0 && s[i] != s[j]) j = pi[j-1];

        if(s[i] == s[j]) j++;

        pi[i] = j;
    }

    KMP(pi, n);
}

int main() {
    int n;

    while(cin >> n) {
        string sub, s; cin >> sub >> s;

        s = sub + "#" + s;

        prefixFunction(s, n);
    }
}
