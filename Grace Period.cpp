/*
Grace Period
time limit per test1 second
memory limit per test256 megabytes
The final evening practice is about to begin, and Grace is watching the clock at the door. The room is scheduled to close at time C
, but she allows teams a grace period of g
 minutes.

A team arriving at time t
 is accepted if and only if t≤C+g
. An accepted team's lateness is max(0,t−C)
: teams arriving no later than C
 contribute zero lateness.

Determine how many teams are accepted and the sum of the lateness values of all accepted teams.


Input
The first line contains three integers n
, C
, and g
 (1≤n≤200000
, 0≤C,g≤109
): the number of teams, the scheduled closing time, and the grace-period length.

The second line contains n
 integers t1,t2,…,tn
 (0≤ti≤109
), where ti
 is the arrival time of team i
.

Output
Print two integers: the number of accepted teams and the sum of their lateness values.

Example
InputCopy
6 100 5
90 100 104 105 106 102
OutputCopy
5 11
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c,g;
    cin>>n>>c>>g;
    vector<int> num_t(n);
    for(int i=0;i<n;i++){
        cin>>num_t[i];
    }
    long long lateness=0;
    int acc=0;
    for(int i=0;i<n;i++){
        if (num_t[i]<=g+c){
            acc+=1;
            lateness+=max(0,num_t[i]-c);
        }
    }
    cout<<acc<<" "<<lateness<<endl;
    return 0;
}