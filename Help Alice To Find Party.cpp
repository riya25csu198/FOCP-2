#include <iostream>

using namespace std;

int main() {
    // Use long long to handle constraints up to 10^18
    long long L, R;
    
    if (cin >> L >> R) {

        long long countOddsR = (R + 1) / 2;
        long long countOddsLMinus1 = L / 2; // (L - 1 + 1) / 2 simplifies to L / 2
        
        long long totalOdds = countOddsR - countOddsLMinus1;
        
        if (totalOdds % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }
    
    return 0;
}
