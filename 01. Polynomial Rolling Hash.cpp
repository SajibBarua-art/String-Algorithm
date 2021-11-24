// Polynomial Rolling Hash

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

int hash_key(string key) {
    ll hash_key = 0;
    ll p = 31;
    ll p_power = 1;

    for(char ch: key) {
        hash_key = ( hash_key + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return hash_key;
}

int main() {
    while(1) {
        string key; cin >> key;

        if(key == ".") break;

        cout << "Key : " << key << "  Hash Key is: " << hash_key(key) << endl;
    }
}