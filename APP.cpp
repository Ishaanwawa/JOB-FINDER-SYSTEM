#include <iostream>
#include <string>
using namespace std;

const int MAX_JOBS = 100;
const int MAX_APPLICATIONS = 100;
const int MAX_USERS = 100;
const string ADMIN_PASSWORD = "pass@123";

struct Job {
    int id;
    string title;
    string description;
};

struct Application {
    int jobId;
    string userName;
    string status;
};

struct User {
    string userName;
    string password;
};

Job jobs[MAX_JOBS];
Application applications[MAX_APPLICATIONS];
User users[MAX_USERS];
int jobCount = 0;
int applicationCount = 0;
int userCount = 0;

void addJob(string title, string description) {
    if (jobCount < MAX_JOBS) {
        jobs[jobCount] = {jobCount + 1, title, description};
        jobCount++;
        cout << "Job added successfully!\n";
    } else {
        cout << "Job list is full!\n";
    }
}

void removeJob(int jobId) {
    if (jobId < 1 || jobId > jobCount) {
        cout << "Invalid Job ID!\n";
        return;
    }
    jobs[jobId - 1] = jobs[jobCount - 1];
    jobCount--;
    cout << "Job removed successfully!\n";
}

void viewJobs() {
    cout << "Available Jobs:\n";
    for (int i = 0; i < jobCount; i++) {
        cout << jobs[i].id << ". " << jobs[i].title << " - " << jobs[i].description << "\n";
    }
}

void applyJob(int jobId, string userName) {
    if (jobId < 1 || jobId > jobCount) {
        cout << "Invalid Job ID!\n";
        return;
    }
    applications[applicationCount++] = {jobId, userName, "Pending"};
    cout << "Application submitted successfully!\n";
}

void viewApplications() {
    cout << "Pending Applications:\n";
    for (int i = 0; i < applicationCount; i++) {
        if (applications[i].status == "Pending") {
            cout << "Job ID: " << applications[i].jobId << " | Applicant: " << applications[i].userName << " | Status: " << applications[i].status << "\n";
        }
    }
}

void reviewApplication(string userName, int jobId, string decision) {
    for (int i = 0; i < applicationCount; i++) {
        if (applications[i].jobId == jobId && applications[i].userName == userName) {
            applications[i].status = decision;
            cout << "Application " << decision << "!\n";
            return;
        }
    }
    cout << "Application not found!\n";
}

void viewUserApplications(string userName) {
    cout << "Your Applications:\n";
    for (int i = 0; i < applicationCount; i++) {
        if (applications[i].userName == userName) {
            cout << "Job ID: " << applications[i].jobId << " | Status: " << applications[i].status << "\n";
        }
    }
}

bool userLogin(string &userName) {
    string password;
    cout << "Enter Username: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].userName == userName && users[i].password == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid credentials!\n";
    return false;
}

void userRegister() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached!\n";
        return;
    }
    string userName, password;
    cout << "Enter New Username: ";
    cin >> userName;
    cout << "Enter New Password: ";
    cin >> password;
    users[userCount++] = {userName, password};
    cout << "Registration successful! You can now log in.\n";
}

int main() {
    int choice, role, jobId;
    string title, description, userName, decision, password;

    while (true) {
        cout << "\nSelect Role: 1. Admin  2. User  3. Exit\n";
        cin >> role;

        if (role == 1) {
            cout << "Enter Admin Password: ";
            cin >> password;
            if (password != ADMIN_PASSWORD) {
                cout << "Incorrect password!\n";
                continue;
            }
            while (true) {
                cout << "\nAdmin Menu:\n1. Add Job\n2. Remove Job\n3. View Jobs\n4. View Applications\n5. Review Application\n6. Switch Role\nChoice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter Job Title: ";
                        cin.ignore();
                        getline(cin, title);
                        cout << "Enter Job Description: ";
                        getline(cin, description);
                        addJob(title, description);
                        break;
                    case 2:
                        cout << "Enter Job ID to Remove: ";
                        cin >> jobId;
                        removeJob(jobId);
                        break;
                    case 3:
                        viewJobs();
                        break;
                    case 4:
                        viewApplications();
                        break;
                    case 5:
                        cout << "Enter Applicant Name: ";
                        cin >> userName;
                        cout << "Enter Job ID: ";
                        cin >> jobId;
                        cout << "Accept or Reject? ";
                        cin >> decision;
                        reviewApplication(userName, jobId, decision);
                        break;
                    case 6:
                        goto role_selection;
                    default:
                        cout << "Invalid choice!\n";
                }
            }
        } else if (role == 2) {
            int userChoice;
            cout << "1. Login  2. Sign up\n";
            cin >> userChoice;
            if (userChoice == 2) {
                userRegister();
                continue;
            }
            if (!userLogin(userName)) continue;

            while (true) {
                cout << "\nUser Menu:\n1. View Jobs\n2. Apply for Job\n3. View Application Status\n4. Switch Role\nChoice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        viewJobs();
                        break;
                    case 2:
                        cout << "Enter Job ID to Apply: ";
                        cin >> jobId;
                        applyJob(jobId, userName);
                        break;
                    case 3:
                        viewUserApplications(userName);
                        break;
                    case 4:
                        goto role_selection;
                    default:
                        cout << "Invalid choice!\n";
                }
            }
        } else if (role == 3) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid role selection!\n";
        }

        role_selection:;
    }
    return 0;
}
