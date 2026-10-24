/*
A. Zero Sum
time limit per test1 second
memory limit per test256 megabytes

You are given an array a
 of length n
, consisting only of −1
 and 1
.

You may perform the following operation on a
 any number of times:

Choose an index i
 satisfying 1≤i≤n−1
.
Assign ai=−ai
 and ai+1=−ai+1
.
Determine whether it is possible to make the sum of elements of a
 equal to 0
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤200
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤100
) — the length of array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (ai∈{−1,1}
) — the array a
.

Output
For each test case, print "YES" if it is possible to make the sum of elements of a
 equal to 0
, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
1
-1
2
1 -1
2
1 1
5
1 -1 1 -1 1
6
-1 1 -1 -1 -1 -1
OutputCopy
NO
YES
NO
NO
YES
Note
In the first example, we cannot perform any operations, and the sum of elements of a
 equals −1≠0
, so the answer is "NO".

In the second example, the sum of elements of a
 is already 0
, so the answer is "YES".

In the fifth example, we can perform an operation with i=3
, transforming a
 as follows: [−1,1,−1,−1,−1,−1]→[−1,1,1,1,−1,−1]
. The sum of the resulting array is 0
, so the answer is "YES".
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int neg = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1) neg++;
        }

        if (n % 2 == 0 && neg % 2 == (n / 2) % 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
