/*
B. First or Second
time limit per test2 seconds
memory limit per test256 megabytes

There are n
 children standing in a line, where the niceness of the i
-th child is ai
. Santa is deciding which children belong on the nice list and which belong on the naughty list.

An integer X
 is initially set to 0
. Santa will perform the following operation exactly n−1
 times:

Choose the first or second child in line and remove them from the line.
Let w
 be the niceness of the chosen child.
If the first child was chosen, add them to the nice list and add w
 to X
.
If the second child was chosen, add them to the naughty list and subtract w
 from X
.
Note that after all operations, exactly one child remains unassigned to a list.

Determine the maximum possible value of X
 that Santa can obtain after all n−1
 operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) — the number of children.

The second line contains n
 integers a1,a2,…,an
 (−109≤ai≤109
) — the niceness of each child.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible value of X
 that Santa can obtain after all n−1
 operations.

Example
InputCopy
7
2
2 -3
4
1 4 3 4
4
-4 2 3 -6
5
-2 -3 4 10 -9
5
-12345678 -1000000000 -999999999 1000000000 -999999999
2
-7 1
5
7 -6 -1 -8 -8
OutputCopy
3
8
4
15
2987654321
-1
29
Note
In the first test case, Santa will perform exactly one operation. If he chooses the first child, he will add a1=2
 to X
 to get X=2
; if he chooses the second child, he will subtract a2=−3
 from X
 to get X=3
. Thus, the answer is 3
.

In the second test case, it is optimal to select the first child in all three operations. The value of X
 will be 1+4+3=8
.

In the third test case, below is an optimal sequence of operations:

#	Type	Niceness of remaining children	X
 after operation
0	—	[−4,2,3,−6]
0
1	First	[2,3,−6]
−4
2	First	[3,−6]
−2
3	Second	[3]
4
In the fourth test case, below is an optimal sequence of operations:

#	Type	Niceness of remaining children	X
 after operation
0	—	[−2,−3,4,10,−9]
0
1	Second	[−2,4,10,−9]
3
2	First	[4,10,−9]
1
3	First	[10,−9]
5
4	First	[−9]
15

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long suffix = 0;
        for (int i = 1; i < n; i++) {
            suffix += a[i];
        }

        // 最后留下 a[0]
        long long ans = -suffix;
        long long prefix = 0;

        // 枚举最后留下 a[k]
        for (int k = 1; k < n; k++) {
            suffix -= a[k];

            long long x = a[0] + prefix - suffix;
            ans = max(ans, x);

            prefix += abs(a[k]);
        }

        cout << ans << '\n';
    }

    return 0;
}
