# contagemDeNotasComC++ (for user)

ATM Withdrawal Documentation
Welcome to the ATM Withdrawal documentation. This software is designed to simulate a basic ATM withdrawal system, allowing users to input a desired withdrawal amount and receive a distribution of banknotes to fulfill that request.
Getting Started
To use the ATM Withdrawal r, follow these simple steps:
Launch the Program: Start the program by executing the provided executable file or by running the source code through a compatible compiler.
Input Withdrawal Amount: Upon launching the program, you will be prompted to enter the amount you wish to withdraw. Simply type the desired amount and press Enter.
View Banknote Distribution: After entering the withdrawal amount, the program will calculate and display the distribution of banknotes required to fulfill your request. This distribution will show the denomination of each banknote and the corresponding count.
Repeat or Exit: You can continue to withdraw amounts by following the same process. To exit the program, simply enter '9999' when prompted for the withdrawal amount.
Important Notes
Available Banknotes: The program operates with a predefined set of available banknotes. These banknotes and their quantities are defined within the program code.
Insufficient Funds: If the entered withdrawal amount cannot be fulfilled with the available banknotes, the program will display a message indicating that the requested amount cannot be distributed.
Administrator Code: To stop the program at any time, enter '9999' when prompted for the withdrawal amount. This serves as an administrator code to halt the program execution.
Example Usage
Below is an example of how to use the ATM Withdrawal Simulator:
Enter Withdrawal Amount: The program prompts: "Enter the amount you want to withdraw:". You enter '150' and press Enter.
View Banknote Distribution: The program calculates the distribution of banknotes required to fulfill a withdrawal of 150 units and displays it as follows:
makefile
Distribution:
100: 1
50: 1
3. 	Continue or Exit: You can choose to continue withdrawing amounts or exit the program by entering '9999'.
Conclusion
The ATM Withdrawal Simulator provides a simple and intuitive way to simulate cash withdrawals and understand the distribution of banknotes for various withdrawal amounts. It can be used for educational purposes or as a basic tool for understanding ATM operations.
For any inquiries or feedback, please contact kelvin.moraes117@gmail.com
Thank you for using the ATM Withdrawal!


# contagemDeNotasComC++ (for programmers)

The provided code is designed to simulate a simple ATM withdrawal system. The program takes an input for the desired withdrawal amount, then calculates and displays the distribution of banknotes to fulfill that request.
Code Explanation
The code consists of a
struct
called
Banknote
, a function called
distributeBanknotes
, a function called
printDistribution
, and the
main
function.
Banknote Struct
struct Banknote {
    int value;
    int count;
};
The
Banknote
struct represents a banknote with its value and the count of available banknotes of that value.
distributeBanknotes Function
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
The
distributeBanknotes
function takes the withdrawal
amount
and a vector of
availableBanknotes
as input. It then calculates the distribution of banknotes needed to fulfill the withdrawal amount.
printDistribution Function
void printDistribution(const vector<Banknote>& distribution) {
    cout << "Distribution:\n";
    for (const Banknote& banknote : distribution) {
        cout << banknote.value << ": " << banknote.count << "\n";
    }
}
The
printDistribution
function takes the distribution of banknotes as input and prints out the values and counts of the distributed banknotes.
Main Function
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

    int amount;
    while (true) {
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;

        if (amount == 9999){
            cout << "System unstoppable with administrator code" << endl;
            break;
        }

        // Distribute banknotes
        vector<Banknote> distribution = distributeBanknotes(amount, availableBanknotes);

        // Print distribution
        printDistribution(distribution);
    }

    return 0;
}
The
main
function initializes the available banknotes and then prompts the user to input a withdrawal amount. If the input is 9999, the system stops. Otherwise, it calls the
distributeBanknotes
function to calculate the banknote distribution and then calls the
printDistribution
function to display the result.
This software can be used as a basic ATM simulator for managing the distribution of banknotes for cash withdrawals.
