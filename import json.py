import json
import os

TODO_FILE = 'todo.json'

def load_todo_list():
    if not os.path.exists(TODO_FILE):
        return []
    with open(TODO_FILE, 'r') as file:
        return json.load(file)

def save_todo_list(todo_list):
    with open(TODO_FILE, 'w') as file:
        json.dump(todo_list, file, indent=4)

def add_task(task):
    todo_list = load_todo_list()
    todo_list.append({"task": task, "completed": False})
    save_todo_list(todo_list)
    print(f'Task "{task}" added.')

def delete_task(task_index):
    todo_list = load_todo_list()
    if 0 <= task_index < len(todo_list):
        removed_task = todo_list.pop(task_index)
        save_todo_list(todo_list)
        print(f'Task "{removed_task["task"]}" deleted.')
    else:
        print("Invalid task index.")

def display_todo_list():
    todo_list = load_todo_list()
    if not todo_list:
        print("No tasks in the todo list.")
    else:
        for index, task in enumerate(todo_list):
            status = "✔" if task["completed"] else "✘"
            print(f"{index}. [{status}] {task['task']}")

def complete_task(task_index):
    todo_list = load_todo_list()
    if 0 <= task_index < len(todo_list):
        todo_list[task_index]["completed"] = True
        save_todo_list(todo_list)
        print(f'Task "{todo_list[task_index]["task"]}" marked as completed.')
    else:
        print("Invalid task index.")

def main():
    while True:
        print("\nTodo List CLI")
        print("1. Add Task")
        print("2. Delete Task")
        print("3. Display Todo List")
        print("4. Complete Task")
        print("5. Exit")

        choice = input("Enter your choice: ")
        if choice == '1':
            task = input("Enter the task: ")
            add_task(task)
        elif choice == '2':
            display_todo_list()
            try:
                task_index = int(input("Enter the task index to delete: "))
                delete_task(task_index)
            except ValueError:
                print("Invalid input. Please enter a number.")
        elif choice == '3':
            display_todo_list()
        elif choice == '4':
            display_todo_list()
            try:
                task_index = int(input("Enter the task index to complete: "))
                complete_task(task_index)
            except ValueError:
                print("Invalid input. Please enter a number.")
        elif choice == '5':
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
