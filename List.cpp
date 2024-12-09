#include <iostream>
#include <cstring>  // For strcpy, to copy descriptions
using namespace std;

class Task {
private:
    char description[100];
    bool isCompleted;

public:
    // Constructor to initialize a task
    Task(const char* desc = "") {
        strcpy(description, desc);
        isCompleted = false;
    }

    // Getter and setter for description
    const char* getDescription() const {
        return description;
    }
    
    void setDescription(const char* desc) {
        strcpy(description, desc);
    }

    // Getter and setter for completion status
    bool getIsCompleted() const {
        return isCompleted;
    }

    void setIsCompleted(bool completed) {
        isCompleted = completed;
    }

    // Display task status
    void displayTask(int taskNumber) const {
        cout << taskNumber << ". " << description;
        if (isCompleted) {
            cout << " (Completed)";
        } else {
            cout << " (Pending)";
        }
        cout << endl;
    }
};

class ToDoList {
private:
    Task tasks[10];
    int taskCount;

public:
    // Constructor to initialize the task list
    ToDoList() : taskCount(0) {}

    // Add a task to the list
    void addTask() {
        if (taskCount < 10) {
            char taskDescription[100];
            cout << "Enter task description: ";
            cin.ignore();  
            cin.getline(taskDescription, 100); 
            tasks[taskCount].setDescription(taskDescription);
            tasks[taskCount].setIsCompleted(false);  // Initially, the task is not completed
            taskCount++;
            cout << "Task added successfully!" << endl;
        } else {
            cout << "Task list is full! Cannot add more tasks." << endl;
        }
    }

    // View all tasks
    void viewTasks() const {
        if (taskCount == 0) {
            cout << "No tasks available!" << endl;
        } else {
            cout << "\nTasks List:" << endl;
            for (int i = 0; i < taskCount; ++i) {
                tasks[i].displayTask(i + 1);
            }
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted() {
        int taskNumber;
        cout << "Enter task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].setIsCompleted(true);
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Remove a task from the list
    void removeTask() {
        int taskNumber;
        cout << "Enter task number to remove: ";
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            // Shift tasks after the one removed
            for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;  // Decrease the task count
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
};

int main() {
    ToDoList toDoList;  // Create an instance of ToDoList
    int choice;
    while (true) {
        // Display menu to the user
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1:
                toDoList.addTask();
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                toDoList.markTaskAsCompleted();
                break;
            case 4:
                toDoList.removeTask();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
