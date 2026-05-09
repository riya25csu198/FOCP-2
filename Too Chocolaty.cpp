#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr) {

    map<int, int> freq;

    // Count frequencies
    for (int x : arr) {
        freq[x]++;
    }

    vector<int> available;

    // If a value appears:
    // once -> add once
    // 2 or more times -> add twice
    for (auto it : freq) {

        int value = it.first;
        int count = it.second;

        available.push_back(value);

        if (count >= 2) {
            available.push_back(value);
        }
    }

    // Sort descending
    sort(available.rbegin(), available.rend());

    long long alex = 0;
    long long bob = 0;

    // Alternate turns
    for (int i = 0; i < available.size(); i++) {

        if (i % 2 == 0)
            alex += available[i];
        else
            bob += available[i];
    }

    // Winner
    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, arr) << "\n";
    }

    return 0;
}
