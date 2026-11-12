#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<long long> pre(n), suf(n);

        pre[0] = b[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], b[i] + i);
        }

        suf[n-1] = b[n-1] - (n-1);
        for (int i = n-2; i >= 0; i--) {
            suf[i] = max(suf[i+1], b[i] - i);
        }

        long long ans = LLONG_MIN;

        for (int j = 1; j < n-1; j++) {
            ans = max(ans, pre[j-1] + b[j] + suf[j+1]);
        }

        cout << ans << '\n';
    }

    return 0;
}