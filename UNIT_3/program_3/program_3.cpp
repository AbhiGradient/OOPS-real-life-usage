#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class DataChecker {
public:
    bool checkMarks(int marks) const {
        if (marks >= 0 && marks <= 100)
            return true;
        return false;
    }

    bool checkAmount(double amount) const {
        if (amount > 0 && amount <= 1000000)
            return true;
        return false;
    }

    bool checkName(string name) const {
        if (name.empty())
            return false;

        for (char ch : name) {
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
                return false;
        }

        return true;
    }
};

int main() {
    DataChecker checker;

    cout << boolalpha;
    cout << "===== DATA CHECKER =====" << endl;

    cout << "Marks 75: "
         << checker.checkMarks(75) << endl;

    cout << "Marks 110: "
         << checker.checkMarks(110) << endl;

    cout << "Amount Rs. 25000: "
         << checker.checkAmount(25000) << endl;

    cout << "Name Abhishek Sapkale: "
         << checker.checkName("Abhishek Sapkale") << endl;

    cout << "Name Abhi123: "
         << checker.checkName("Abhi123") << endl;

    return 0;
}