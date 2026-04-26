#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    unordered_map<int, unordered_set<int>> movie;

    while (Q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string type;
        ss >> type;

        if (type == "BOOK") {
            int x, y;
            ss >> x >> y;

            if (movie[y].count(x) || movie[y].size() >= 100)
                cout << "false\n";
            else {
                movie[y].insert(x);
                cout << "true\n";
            }
        }

        else if (type == "CANCEL") {
            int x, y;
            ss >> x >> y;

            if (!movie[y].count(x))
                cout << "false\n";
            else {
                movie[y].erase(x);
                cout << "true\n";
            }
        }

        else if (type == "IS_BOOKED") {
            int x, y;
            ss >> x >> y;

            if (movie[y].count(x))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (type == "AVAILABLE_TICKETS") {
            int y;
            ss >> y;

            cout << 100 - movie[y].size() << "\n";
        }
    }
}
