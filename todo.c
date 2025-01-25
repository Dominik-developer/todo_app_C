#include <stdio.h>
#include <string.h>

/* to do app  */

#define MAX_TASKS 10
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH]; // Array to store tasks
int taskCount = 0; // task counter

void viewTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available. \n");
        return;
    }

    printf("\n Your tasks: \n");
    for(int i =0; i < taskCount; i++) {
        printf("%d.%s \n", i+1, tasks[i]);
    }
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\n Error: Task list is full. You cannot add more tasks. \n");
        return;
    }

    printf("\n Enter your task: ");
    getchar(); //cleaning input buffer (memory)

    fgets(tasks[taskCount], MAX_LENGTH, stdin); // fgets() read all line, snanf() read only to first space

    size_t length = strlen(tasks[taskCount]); // Remove trailing newline character (if any)
    if (length > 0 && tasks[taskCount][length - 1] == '\n' ) { // if last character is \n
        tasks[taskCount][length - 1] = '\0'; // we change it for \0
    }

    taskCount++; // adding 1 to taksCount
    printf("\nTask added successfully!\n");
}

void removeTask() {
    if (taskCount == 0) {
        printf("\n Error: No tasks available to remove. \n");
    }

    int taskNum;
    printf("\n Enter the number of the task to remove: ");
    scanf("%d", &taskNum);

    if (taskNum < 1 || taskNum > taskCount) {
        printf("\n Error: Invalid task number. \n");
        return;
    }

    //removing the task
    for (int i = taskNum - 1; i < taskCount - 1; i++ ) { // it is hard to explain; taskNUM = i
        strcpy(tasks[i], tasks[i+1]); // copying task from i+1 to i and doing so with the next tasks in table till we reach end of table
    }

    taskCount--; // remoing last task which is the same as the one before him;  taskCount - 1
    printf("\n Task removed successfully! \n");
}

void editTask() {
    if (taskCount == 0) {
        printf("\n Error: No tasks available to edit. \n");
    }

    int taskNum;
    printf("\n Enter the number of the task to edit: ");
    scanf("%d", &taskNum);

    if (taskNum < 1 || taskNum > taskCount) {
        printf("\n Error: Invalid task number. \n");
        return;
    }

    printf("Enter the new description for Task %d: ", taskNum);
    getchar(); 

    fgets(tasks[taskNum - 1], MAX_LENGTH, stdin);

    size_t length = strlen(tasks[taskNum - 1]);
    if (length > 0 && tasks[taskNum - 1][length - 1] == '\n' ) {
        tasks[taskNum - 1][length - 1] = '\0';
    }

    printf("\nTask %d updated successfully!\n", taskNum);
}


// *********************************** main()
int main() {

    int choice;

    printf("Welcome to the TODO List System! \n");

    do {
        // menu
        printf("\n Menu: \n");
        printf("1. View tasks \n");
        printf("2. Add a task \n");
        printf("3. Delete a task \n");
        printf("4. Edit a task \n");
        printf("0. Exit \n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1 : 
                printf("Displaying the task list... \n");
                viewTasks();
                break;

            case 2 : 
                printf("Adding a new task... \n");
                addTask();
                break;

            case 3 : 
                printf("Deleting a task... \n");
                removeTask();
                break;

            case 4 : 
                printf("Editing a task... \n");
                editTask();
                break;

            case 0 : 
                printf("Exiting the program. Goodbye! \n");
                break;

            default:
                printf("Invalid choice. Please try again. \n");
        }

    } while (choice != 0 ); // till choice = 0

    return 0;
}

