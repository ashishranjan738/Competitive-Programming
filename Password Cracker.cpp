#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <iterator>
using namespace std;
vector<string> parse(const string& attempt, const unordered_set<string> &passwords) {
    vector<int> starts(attempt.size(), -1);
    for (int end = 0; end < attempt.size(); ++end) {
        if (passwords.count(attempt.substr(0, end+1))) {
            starts[end] = 0;
            continue;
        }
        for (int split = 1; split <= end; ++split) {
            if (starts[split-1] != -1 && passwords.count(attempt.substr(split, end-split+1))) {
                starts[end] = split;
                break;
            }
        }
    }
    if (starts.back() == -1) {
        return {"WRONG PASSWORD"};
    }
    vector<string> result;
    int end = attempt.size()-1;
    do {
        int start = starts[end];
        result.emplace_back(attempt.substr(start, end-start+1));
        end = start-1;
    } while (end != -1);
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        unordered_set<string> passwords;
        for (int i = 0; i < N; ++i) {
            string password;
            cin >> password;
            passwords.emplace(password);
        }
        string attempt;
        cin >> attempt;
        auto parsed = parse(attempt, passwords);
        copy(parsed.cbegin(), parsed.cend(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    return 0;
}
