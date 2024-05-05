#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Banknote {
    int value;
    int count;
};

vector<Banknote> distributeBanknotes(int amount, const vector<Banknote>& availableBanknotes) {
    vector<Banknote> distribution;

    for (const Banknote& banknote : availableBanknotes) {
        if (banknote.value <= amount) {
            int banknoteCount = min(amount / banknote.value, banknote.count);
            distribution.push_back({banknote.value, banknoteCount});
            amount -= banknoteCount * banknote.value;

            if (amount == 0)
                break;
        }
    }

    if (amount > 0) {
        cout << "Cannot distribute the requested amount.\n";
        distribution.clear();
    }

    return distribution;
}

void printDistribution(const vector<Banknote>& distribution) {
    cout << "Distribution:\n";
    for (const Banknote& banknote : distribution) {
        cout << banknote.value << ": " << banknote.count << "\n";
    }
}

int main() {
    // Define available banknotes
    vector<Banknote> availableBanknotes = {
        {100, 10},
        {50, 10},
        {20, 20},
        {10, 20},
        {5, 50},
        {1, 50}
    };

    // Get desired amount from user
    int amount;
    while (true) {
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;

        if (amount == 9999){
            cout << "System unstoppable with administrator code" << endl;
            break;}

        // Distribute banknotes
        vector<Banknote> distribution = distributeBanknotes(amount, availableBanknotes);

        // Print distribution
        printDistribution(distribution);
    }

    return 0;
}