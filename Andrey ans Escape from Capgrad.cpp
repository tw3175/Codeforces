/*
D. Andrey and Escape from Capygrad
time limit per test2 seconds
memory limit per test256 megabytes
An incident occurred in Capygrad, the capital of Tyagoland, where all the capybaras in the city went crazy and started throwing mandarins. Andrey was forced to escape from the city as far as possible, using portals.

Tyagoland is represented by a number line, and the city of Capygrad is located at point 0
. There are n
 portals all over Tyagoland, each of which is characterised by four integers li
, ri
, ai
 and bi
 (1≤li≤ai≤bi≤ri≤109
). Note that the segment [ai,bi]
 is contained in the segment [li,ri]
.

If Andrey is on the segment [li,ri]
, then the portal can teleport him to any point on the segment [ai,bi]
. Andrey has a pass that allows him to use the portals an unlimited number of times.

Andrey thinks that the point x
 is on the segment [l,r]
 if the inequality l≤x≤r
 is satisfied.

Andrey has q
 options for where to start his escape, each option is characterized by a single integer xi
 — the starting position of the escape. He wants to escape from Capygrad as far as possible (to the point with the maximum possible coordinate). Help Andrey determine how far he could escape from Capygrad, starting at each of the q
 positions.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of sets of test cases. The description of test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of portals.

Each of the next n
 lines contains four integers li
, ri
, ai
, and bi
 (1≤li≤ai≤bi≤ri≤109)
 — the characteristics of the portals.

The next line contains a single integer q
 (1≤q≤2⋅105
) — the number of positions.

The following line contains q
 integers x1,x2,…,xq
 (1≤xi≤109
) — the position from which Andrey will start his escape in the i
-th options.

It is guaranteed that the sum of n
 and the sum of q
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single line of q
 integers, containing the answers to Andrey's questions.

Example
InputCopy
5
3
6 17 7 14
1 12 3 8
16 24 20 22
6
10 2 23 15 28 18
3
3 14 7 10
16 24 20 22
1 16 3 14
9
2 4 6 8 18 23 11 13 15
2
1 4 2 3
3 9 6 7
3
4 8 1
5
18 24 18 24
1 8 2 4
11 16 14 14
26 32 28 30
5 10 6 8
9
15 14 13 27 22 17 31 1 7
6
9 22 14 20
11 26 13 24
21 33 22 23
21 33 25 32
1 6 3 4
18 29 20 21
8
11 23 16 5 8 33 2 21
OutputCopy
14 14 23 15 28 22 
14 14 14 14 22 23 14 14 15 
7 8 7 
15 14 14 30 24 17 31 4 8 
32 32 32 5 8 33 4 32 
Note
In the first test case:


Optimal actions when starting from each position:

Use portal 1
 and teleport to point b1=14
.
Use portal 2
 first and teleport to point 6
, which is on the segment [l1,r1]=[6,17]
, then use portal 1
 and teleport to point b1=14
.
Stay at point x3=23
 without using any portals.
Stay at point x4=15
 without using any portals.
Point x5=28
 is not on any segment, so Andrey won't be able to teleport anywhere.
Point x6=18
 is only on the segment [l3,r3]=[16,24]
, use portal 3
 and teleport to point b3=22
.
In the fifth test case:


Optimal actions when starting from each position:

Use portal 1
 first and teleport to point 15
 on the segment [a1,b1]=[14,20]
, then use portal 2
 and teleport to point 21
, which is on the segment [l4,r4]=[21,33]
 and on the segment [a2,b2]=[13,24]
, then teleport to point b4=32
.
Use portal 6
 first and teleport to point 20
 on the segment [a6,b6]=[20,21]
, then use portal 2
 and teleport to point 22
, which is simultaneously on the segment [l4,r4]=[21,33]
 and on the segment [a2,b2]=[13,24]
, then teleport to point b4=32
.
Perform the same actions as from the first position.
Stay at point x4=5
 without using any portals.
Point 8
 is not on any segment, so Andrey won't be able to teleport anywhere.
Stay at point x6=33
 without using any portals.
Use portal 5
 and teleport to point b5=4
.
Perform the same actions as from the first position.
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

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;

            v.push_back({l, b});
        }

        // 1. 按左端点排序
        sort(v.begin(), v.end());

        // 2. 合并区间
        vector<pair<int, int>> seg;

        for (auto [l, r] : v) {
            if (seg.empty() || l > seg.back().second) {
                seg.push_back({l, r});
            } else {
                seg.back().second = max(seg.back().second, r);
            }
        }

        // 3. 处理查询
        int q;
        cin >> q;

        while (q--) {
            int x;
            cin >> x;

            int left = 0;
            int right = (int)seg.size() - 1;
            int idx = -1;

            // 找左端点 <= x 的最后一个区间
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (seg[mid].first <= x) {
                    idx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (idx != -1 && x <= seg[idx].second) {
                x = seg[idx].second;
            }

            cout << x << " ";
        }

        cout << "\n";
    }

    return 0;
}