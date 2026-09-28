#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string studentName;
    float score;

public:
    Student() {
        id = 0;
        score = 0;
    }

    Student(int i, string n, float s) {
        id = i;
        studentName = n;
        score = s;
    }

    void writeData(ofstream& file) const {
        file << id << "," << studentName << "," << score << endl;
    }

    bool readData(string data) {
        string idText, scoreText;
        stringstream ss(data);

        if (!getline(ss, idText, ','))
            return false;

        if (!getline(ss, studentName, ','))
            return false;

        if (!getline(ss, scoreText))
            return false;

        id = stoi(idText);
        score = stof(scoreText);

        return true;
    }

    void showData() const {
        cout << "ID: " << id
             << " | Student: " << studentName
             << " | Score: " << score << endl;
    }
};

int main() {
    ofstream fileOut("student_data.csv");

    if (!fileOut) {
        cout << "File could not be opened for writing." << endl;
        return 1;
    }

    Student st4(204, "Abhishek Sapkale", 101.0);
Student st5(205, "Sarth Dange", 99.0);
Student st6(206, "Soham Bandge", 88.5);
Student st7(207, "Shubham Narsale", 99.5);
Student st8(208, "Om Shahane", 90.0);
Student st9(209, "Saujas Salunke", 100.0);
Student st10(210, "Prathamesh Shetty", 85.0);
Student st11(211, "Soham Ranadhir", 89.0);
Student st12(212, "Akshay Karki", 77.5);
Student st13(213, "Anuj Suryavanshi", 82.0);
Student st14(214, "Nihal Roundhal", 79.0);

    st4.writeData(fileOut);
    st5.writeData(fileOut);
    st6.writeData(fileOut);
    st7.writeData(fileOut);
    st8.writeData(fileOut);
    st9.writeData(fileOut);
    st10.writeData(fileOut);
    st11.writeData(fileOut);
    st12.writeData(fileOut);
    st13.writeData(fileOut);
    st14.writeData(fileOut);

    fileOut.close();

    ifstream fileIn("student_data.csv");

    if (!fileIn) {
        cout << "File could not be opened for reading." << endl;
        return 1;
    }

    cout << "===== STUDENT RECORDS =====" << endl;

    string data;

    while (getline(fileIn, data)) {
        Student student;

        if (student.readData(data)) {
            student.showData();
        }
    }

    fileIn.close();

    return 0;
}