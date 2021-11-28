// Z-function
// To find all the matching substring from a given string
// Time complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    int n = s.size();
    vector<int> z(n);

    z[0] = 0;

    for(int i = 1, r=0, l=0; i<n; i++) {
        if(i<=r) z[i] = min(r-i+1, z[i-l]);

        while(z[i]+i-1 < n && s[z[i]] == s[z[i]+i]) 
            z[i]++;

        if(z[i]+i-1 > r) l = i, r = z[i]+i-1;
    }

    for(int i=0; i<n; i++) {
        cout << z[i] << " ";
    }
}