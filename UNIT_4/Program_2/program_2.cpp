#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Log {
    string message;
};

int main() {
    ofstream outputFile("system.log");

    if (!outputFile) {
        cout << "Unable to create log file." << endl;
        return 1;
    }

    outputFile << "2026-09-15 09:00:00 INFO System started\n";
    outputFile << "2026-09-15 09:15:00 WARNING CPU usage high\n";
    outputFile << "2026-09-15 09:30:00 ERROR Network connection lost\n";
    outputFile << "2026-09-15 09:45:00 INFO System backup completed\n";
    outputFile << "2026-09-15 10:00:00 CRITICAL Storage almost full\n";

    outputFile.close();

    ifstream inputFile("system.log");

    if (!inputFile) {
        cout << "Unable to open log file." << endl;
        return 1;
    }

    vector<Log> importantLogs;
    string text;

    while (getline(inputFile, text)) {
        if (text.find("ERROR") != string::npos ||
            text.find("CRITICAL") != string::npos) {

            Log entry;
            entry.message = text;
            importantLogs.push_back(entry);
        }
    }

    inputFile.close();

    cout << "===== IMPORTANT LOG EVENTS =====" << endl;

    for (const auto& entry : importantLogs) {
        cout << entry.message << endl;
    }

    cout << "Total important events: "
         << importantLogs.size() << endl;

    return 0;
}