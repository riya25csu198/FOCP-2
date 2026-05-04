#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 0;
    }

    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "{name} doesn't fix bugs, they just rename them as features.",
        "{name}'s logic is like weak WiFi.",
        "{name} codes like deadlines don't exist.",
        "{name}'s program runs… sometimes."
    };

    srand(time(0));
    int index = rand() % roasts.size();

    string roast = roasts[index];

    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    cout << roast << endl;

    return 0;
}
