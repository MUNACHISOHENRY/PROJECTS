import json
import os

FILENAME = "Todo_list.json"

if os.path.exists(FILENAME):
    with open(FILENAME, "r") as file:
        tasks = json.load(file)
else:
    tasks = []  

def save_tasks():
    "Save the current tasks to a JSON file."
    with open(FILENAME, "w") as file:  
        json.dump(tasks, file, indent=4)

def main():
    while True:
        print("\n--TO DO LIST--")
        print("1. Add Task")
        print("2. Delete Task")
        print("3. List of Current Tasks")
        print("4. Mark as Done")
        print("5. Clear all?")
        print("6. Exit")

        choice = input("\nENTER YOUR SELECTION: ")

        if choice == '1':
            task_description = input("Enter task: ")
            tasks.append({"Task": task_description, "Done": False})
            save_tasks()  
            print(f"Task '{task_description}' added successfully.")

            print("\nCurrent Tasks:")
            for index, task in enumerate(tasks, start=1):
                status = "Done" if task["Done"] else "Not Done"
                print(f"{index}. {task['Task']} [{status}]")
                
        elif choice == "2":
            task_number = int(input("Enter Task NO to remove: "))
            if 0 < task_number <= len(tasks):
                deleted_task = tasks[task_number - 1]
                tasks.remove(deleted_task)
                save_tasks()
                print(f"'{deleted_task['Task']}' deleted.")
            else:
                print("Invalid task number.")

        elif choice == "3":
            if tasks:
                print("LIST OF TASKS:")
                for index, task in enumerate(tasks, start=1):
                    status = "Done" if task["Done"] else "Not Done"
                    print(f"{index}. {task['Task']} [{status}]")
            else:
                print("No tasks were found.")

        elif choice == "4":
            task_number = int(input("Enter task number to mark as DONE: "))
            if 0 < task_number <= len(tasks):
                tasks[task_number - 1]["Done"] = True  
                save_tasks()  
                print("Task marked as done!")
            else:
                print("Invalid task number.")

        elif  choice == "5":
            print("Clear all?")
            clear_all = input("y/n: ")
            if clear_all == "y":
                tasks.clear()  
                save_tasks()  
                print("Tasks have been cleared.")
            else:
                print("Task still intact!")

        elif choice == "6":
            print("Enjoy your weekend!")
            break
        
        else:
            print("Invalid choice. Please try again.")
        

if __name__ == "__main__":
    main()  
