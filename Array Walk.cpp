// B. Array Walk
// time limit per test2 seconds
// memory limit per test256 megabytes
// You are given an array a1,a2,…,an
// , consisting of n
//  positive integers.

// Initially you are standing at index 1
//  and have a score equal to a1
// . You can perform two kinds of moves:

// move right — go from your current index x
//  to x+1
//  and add ax+1
//  to your score. This move can only be performed if x<n
// .
// move left — go from your current index x
//  to x−1
//  and add ax−1
//  to your score. This move can only be performed if x>1
// . Also, you can't perform two or more moves to the left in a row.
// You want to perform exactly k
//  moves. Also, there should be no more than z
//  moves to the left among them.

// What is the maximum score you can achieve?

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of testcases.

// The first line of each testcase contains three integers n,k
//  and z
//  (2≤n≤105
// , 1≤k≤n−1
// , 0≤z≤min(5,k)
// ) — the number of elements in the array, the total number of moves you should perform and the maximum number of moves to the left you can perform.

// The second line of each testcase contains n
//  integers a1,a2,…,an
//  (1≤ai≤104
// ) — the given array.

// The sum of n
//  over all testcases does not exceed 3⋅105
// .

// Output
// Print t
//  integers — for each testcase output the maximum score you can achieve if you make exactly k
//  moves in total, no more than z
//  of them are to the left and there are no two or more moves to the left in a row.

// Example
// InputCopy
// 4
// 5 4 0
// 1 5 4 3 2
// 5 4 1
// 1 5 4 3 2
// 5 4 4
// 10 20 30 40 50
// 10 7 3
// 4 6 8 2 9 9 7 4 10 9
// OutputCopy
// 15
// 19
// 150
// 56
// Note
// In the first testcase you are not allowed to move left at all. So you make four moves to the right and obtain the score a1+a2+a3+a4+a5
// .

// In the second example you can move one time to the left. So we can follow these moves: right, right, left, right. The score will be a1+a2+a3+a2+a3
// .

// In the third example you can move four times to the left but it's not optimal anyway, you can just move four times to the right and obtain the score a1+a2+a3+a4+a5
// .



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 前缀和
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        // best[i] = 前 i+1 对相邻元素中的最大和
        vector<int> best(n - 1);
        best[0] = a[0] + a[1];

        for (int i = 1; i < n - 1; i++) {
            best[i] = max(best[i - 1], a[i] + a[i + 1]);
        }

        // 不向左走
        long long ans = pre[k + 1];

        // 枚举向左走的次数
        for (int l = 1; l <= z; l++) {
            int pos = k - 2 * l;

            if (pos < 0) break;

            long long score = pre[pos + 1]
                            + 1LL * l * best[pos];

            ans = max(ans, score);
        }

        cout << ans << '\n';
    }

    return 0;
}

