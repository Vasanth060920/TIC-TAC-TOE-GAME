#include <iostream>
#include <vector>

struct Task {
    std::string name;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& taskName) {
    tasks.push_back({taskName, false});
    std::cout << "Task added: " << taskName << "\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].name << " - "
                  << (tasks[i].completed ? "Completed" : "Pending") << "\n";
    }
}

void markCompleted(std::vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[index - 1].name << "\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        std::cout << "Task removed: " << tasks[index - 1].name << "\n";
        tasks.erase(tasks.begin() + index - 1);
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;
    std::string taskName;
    int taskIndex;
    
    do {
        std::cout << "\nTO-DO LIST MANAGER\n";
        std::cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1:
                std::cout << "Enter task name: ";
                std::getline(std::cin, taskName);
                addTask(tasks, taskName);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                markCompleted(tasks, taskIndex);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
todo
