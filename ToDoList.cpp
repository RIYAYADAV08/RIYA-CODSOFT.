#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, taskDescription);
    tasks.emplace_back(taskDescription);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].completed ? "Completed" : "Pending") << "] "
                  << tasks[i].description << "\n";
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;
    std::cin.ignore(); 

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;
    std::cin.ignore(); 

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
