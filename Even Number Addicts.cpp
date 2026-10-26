/*
Even Number Addicts
time limit per test2 seconds
memory limit per test512 megabytes
Alice and Bob are playing a game on a sequence a1,a2,…,an
 of length n
. They move in turns and Alice moves first.

In the turn of each player, he or she should select an integer and remove it from the sequence. The game ends when there is no integer left in the sequence.

Alice wins if the sum of her selected integers is even; otherwise, Bob wins.

Your task is to determine who will win the game, if both players play optimally.

Input
Each test contains multiple test cases. The first line contains an integer t
 (1≤t≤100
) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer n
 (1≤n≤100
), indicating the length of the sequence.

The second line of each test case contains n
 integers a1,a2,…,an
 (−109≤ai≤109
), indicating the elements of the sequence.

Output
For each test case, output "Alice" (without quotes) if Alice wins and "Bob" (without quotes) otherwise.

Example
InputCopy
4
3
1 3 5
4
1 3 5 7
4
1 2 3 4
4
10 20 30 40
OutputCopy
Alice
Alice
Bob
Alice
Note
In the first and second test cases, Alice always selects two odd numbers, so the sum of her selected numbers is always even. Therefore, Alice always wins.

In the third test case, Bob has a winning strategy that he always selects a number with the same parity as Alice selects in her last turn. Therefore, Bob always wins.

In the fourth test case, Alice always selects two even numbers, so the sum of her selected numbers is always even. Therefore, Alice always wins.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2][2];

bool dfs(int odd, int even, int p, int turn) {
    if (odd == 0 && even == 0)
        return p == 0;

    int &res = dp[odd][even][p][turn];
    if (res != -1) return res;

    if (turn == 0) {
        // Alice 只要存在一种获胜走法即可
        res = 0;

        if (odd > 0)
            res |= dfs(odd - 1, even, p ^ 1, 1);

        if (even > 0)
            res |= dfs(odd, even - 1, p, 1);
    } else {
        // Bob 会选择对 Alice 最不利的走法
        res = 1;

        if (odd > 0)
            res &= dfs(odd - 1, even, p, 0);

        if (even > 0)
            res &= dfs(odd, even - 1, p, 0);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int odd = 0, even = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 2 != 0) odd++;
            else even++;
        }

        memset(dp, -1, sizeof(dp));

        if (dfs(odd, even, 0, 0))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}