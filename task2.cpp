#include <iostream>
#include <vector>
using namespace std;

struct Task
{
    string description;
    bool completed;
};

void addTask(vector<Task> &todoList, string description)
{
    Task newTask = {description, false};
    todoList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

void displayTasks(const vector<Task> &todoList)
{
    if (todoList.empty())
    {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i)
    {
        cout << i + 1 << ". ";
        if (todoList[i].completed)
        {
            cout << "[X] ";
        }
        else
        {
            cout << "[ ] ";
        }
        cout << todoList[i].description << endl;
    }
}

void markTaskComplete(vector<Task> &todoList, size_t index)
{
    if (index >= 1 && index <= todoList.size())
    {
        todoList[index - 1].completed = true;
        cout << "Task marked as complete." << endl;
    }
    else
    {
        cout << "Invalid task index." << endl;
    }
}

int main()
{
    vector<Task> todoList;

    while (true)
    {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Mark Task Complete" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); // Clear newline character from buffer
            getline(cin, description);
            addTask(todoList, description);
        }
        else if (choice == 2)
        {
            displayTasks(todoList);
        }
        else if (choice == 3)
        {
            size_t index;
            cout << "Enter the task number to mark as complete: ";
            cin >> index;
            markTaskComplete(todoList, index);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
