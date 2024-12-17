#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Struct to store course details
struct Course {
    string courseNumber;          // Course code or number (e.g., "CS101")
    string title;                 // Title of the course (e.g., "Introduction to Programming")
    vector<string> prerequisites; // List of prerequisites for the course
};

// Function prototypes
void loadData(map<string, Course>& courses, const string& fileName);
void printCourseList(const map<string, Course>& courses);
void printCourseInfo(const map<string, Course>& courses, const string& courseNumber);

int main() {
    map<string, Course> courses; // Map to store course details, where key is the course number
    int choice;                  // Variable to store the user's menu choice
    string fileName, courseNumber;

    cout << "Welcome to the course planner.\n";

    do {
        // Display the menu to the user
        cout << "\n1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n";
        cout << "What would you like to do? ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case 1: // Option to load data from a file
                cout << "Enter the file name: ";
                cin >> fileName;
                loadData(courses, fileName);
                break;

            case 2: // Option to print the list of courses
                printCourseList(courses);
                break;

            case 3: // Option to print details of a specific course
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                printCourseInfo(courses, courseNumber);
                break;

            case 9: // Option to exit the program
                cout << "Thank you for using the course planner!\n";
                break;

            default: // Handle invalid menu options
                cout << choice << " is not a valid option.\n";
        }
    } while (choice != 9); // Repeat until the user chooses to exit

    return 0;
}

// Function to load data from a file and populate the courses map
void loadData(map<string, Course>& courses, const string& fileName) {
    ifstream file(fileName); // Open the file for reading
    if (!file) {
        // Error handling for file not found or unreadable
        cout << "Error: Unable to open file '" << fileName << "'. Please check the file and try again.\n";
        return;
    }

    string line;
    int lineCount = 0; // Counter to track the current line number in the file

    while (getline(file, line)) {
        ++lineCount;
        if (line.empty()) {
            continue; // Skip empty lines in the file
        }

        stringstream ss(line); // Create a string stream for parsing the line
        string courseNumber, title;

        // Parse the course number and title, separated by commas
        if (!getline(ss, courseNumber, ',') || !getline(ss, title, ',')) {
            // Handle invalid line format
            cout << "Error: Invalid format on line " << lineCount << ". Skipping this line.\n";
            continue;
        }

        // Create a new Course object
        Course course;
        course.courseNumber = courseNumber;
        course.title = title;

        // Parse prerequisites (if any), separated by commas
        string prerequisite;
        while (getline(ss, prerequisite, ',')) {
            if (!prerequisite.empty()) { // Avoid adding empty strings as prerequisites
                course.prerequisites.push_back(prerequisite);
            }
        }

        // Add the course to the map using the course number as the key
        courses[courseNumber] = course;
    }

    cout << "Data loaded successfully. Total courses loaded: " << courses.size() << endl;
    file.close(); // Close the file
}

// Function to print the list of courses in alphanumeric order
void printCourseList(const map<string, Course>& courses) {
    if (courses.empty()) {
        // If no courses are loaded, display an error message
        cout << "No courses available. Please load data first.\n";
        return;
    }

    cout << "Here is a sample schedule:\n\n";
    // Iterate over the map and print course number and title
    for (const auto& pair : courses) {
        cout << pair.first << ", " << pair.second.title << endl;
    }
}

// Function to print detailed information about a specific course
void printCourseInfo(const map<string, Course>& courses, const string& courseNumber) {
    // Search for the course in the map using the course number
    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        const Course& course = it->second; // Retrieve the course details
        cout << course.courseNumber << ", " << course.title << endl;

        // Print prerequisites, if any
        if (!course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                cout << course.prerequisites[i];
                if (i < course.prerequisites.size() - 1) {
                    cout << ", "; // Separate prerequisites with a comma
                }
            }
            cout << endl;
        } else {
            // If no prerequisites, display "None"
            cout << "Prerequisites: None\n";
        }
    } else {
        // Handle case where the course is not found
        cout << "Course not found.\n";
    }
}
