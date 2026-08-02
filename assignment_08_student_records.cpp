// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
// TASK: Student Record Management System
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Struct to represent a Student record
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate average score for a student
double calculateStudentAverage(const Student& s) {
    if (s.scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// 1. Function to add a student
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    cin.ignore(); // Clear newline character from input buffer
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// 2. Function to display all students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n------------------------------------------------------------\n";
    cout << left << setw(15) << "ID" 
         << setw(20) << "Name" 
         << setw(15) << "Average" 
         << "Scores\n";
    cout << "------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(15) << s.id 
             << setw(20) << s.name 
             << fixed << setprecision(2) << setw(15) << calculateStudentAverage(s);
        
        cout << "[ ";
        for (size_t i = 0; i < s.scores.size(); i++) {
            cout << s.scores[i] << (i + 1 < s.scores.size() ? ", " : "");
        }
        cout << " ]\n";
    }
    cout << "------------------------------------------------------------\n";
}

// 3. Function to calculate average score for a specific student by ID
void calculateAverageForStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    for (const auto& s : students) {
        if (s.id == searchID) {
            double avg = calculateStudentAverage(s);
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << avg << "\n";
            return;
        }
    }

    cout << "Error: Student ID " << searchID << " not found.\n";
}

// Function to display menu options
void displayMenu() {
    cout << "\n================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU   \n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}