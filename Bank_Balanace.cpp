#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    unordered_map<int, int> bank; // userID -> balance

    while (Q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string type;
        ss >> type;

        if (type == "CREATE") {
            int x, y;
            ss >> x >> y;

            if (bank.find(x) == bank.end()) {
                bank[x] = y;
                cout << "true\n";
            } else {
                bank[x] += y;
                cout << "false\n";
            }
        }

        else if (type == "DEBIT") {
            int x, y;
            ss >> x >> y;

            if (bank.find(x) == bank.end() || bank[x] < y) {
                cout << "false\n";
            } else {
                bank[x] -= y;
                cout << "true\n";
            }
        }

        else if (type == "CREDIT") {
            int x, y;
            ss >> x >> y;

            if (bank.find(x) == bank.end()) {
                cout << "false\n";
            } else {
                bank[x] += y;
                cout << "true\n";
            }
        }

        else if (type == "BALANCE") {
            int x;
            ss >> x;

            if (bank.find(x) == bank.end()) {
                cout << -1 << "\n";
            } else {
                cout << bank[x] << "\n";
            }
        }
    }

    return 0;
}
