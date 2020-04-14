// There are a lot of Poke'mons who are jealous of the fact that they do NOT have any specialty, they're the... normal type of Poke'mon. But, what they fail to realize is that their power is their normalcy, the ability to think, rationalize and then act.

// But, they do have an additional power... Poke'mons like Jigglypuff - which are normal, can figure out if a trainer is real or is a part of Team Rocket. And they need to use their power to a great extent.

// In an array, which consists of N elements, A1, A2, ..., AN, if a subarray has the total number of distinct elements as that of the original array, that determines the presence of Team Rocket.

// You've to help the normal type Poke'mons in figuring out the total number of subarrays having total number of distinct elements same as that of the original array.

// Input format:
// The first line of the input will consist of a single integer N. The next line will consist of N integers A1, A2, ... , AN.

// Output format: Output the answer to the problem.

// Constraints:
// 1 ≤ N ≤ 2 * 105
// 1 ≤ Ai ≤ 109

// Reference:
// enter image description here

// SAMPLE INPUT
// 5
// 1 2 2 1 1
// SAMPLE OUTPUT
// 8
// Explanation
// All the possible subarrays are [1,2] , [1,3] , [1,4] , [1,5] , [2,4] , [2,5] , [3,4] , [3,5]

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    int num_dist = set<int>(v.begin(), v.end()).size();
    map<int, int> m;
    long long int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(j, i);
        while (j < n && m.size() < num_dist)
            m[v[j++]]++;
        if (m.size() == num_dist)
            ans += n - j + 1;
        m[v[i]]--;
        if (m[v[i]] == 0)
            m.erase(v[i]);
    }
    cout << ans << "\n";
}

// Hint:
// Consider an example,
// 1 2 2 2 6 1 1 1 2
// Here num_dist is 3 so for i=0 our while loop runs till element 6(index is 4 and it becomes maxi) at this point s.size()==num_dist so whatever elements there after 6 are already present in our set 's' so we increment ans here by (n-maxi+1) because following are the possible subsets.
// 1 2 2 2 6 1 1 1 2
// 1 2 2 2 6 1 1 1
// 1 2 2 2 6 1 1
// 1 2 2 2 6 1
// 1 2 2 2 6

// so ans=ans+5

// for i=1 the while loop runs till element 1 (index is 5 and it becomes maxi) at this point s.size()==num_dist because in iteration '0' we erased element 1 from set s(line 63 and 64). now possible subsets are as follows.
// 2 2 2 6 1 1 1 2
// 2 2 2 6 1 1 1
// 2 2 2 6 1 1
// 2 2 2 6 1

// so ans=ans+4

// same for i=2,3,.....