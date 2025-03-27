#include<stdio.h>
void On_goingMovies() {
    int choice;
    printf("i. Mufasa\n");
    printf("ii. La La Land\n");
    printf("iii. Dunki\n");
    printf("\n");
    printf("1. Buy Ticket\n");
    printf("2. Return to HOME PAGE\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("GO STUDY FIRST!");
                break;
        
        default: printf("Error!\n");
    }
}


int main()
{
    int n, choice;
    char name[50];
    do {
        printf("\n----- HOME PAGE -----\n");
        printf("1. On-going movies\n");
        printf("2. Buy Tickets\n");
        printf("3. See available seats\n");
        printf("4. Upcoming movies\n");
        printf("5. Movie request\n");
        printf("6. Save receipt\n");
        printf("7. Admin portal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1: 
                On_goingMovies();
                break;
            // case 2:
            //     if(insertStudent(students, &n))
            //         printf("\nStudent added successfully!\n");
            //     else
            //         printf("\nArray is full! Cannot add more students.\n");
            //     break;
            // case 3:
            //     printf("\nEnter the name of the student to delete: ");
            //     scanf(" %[^\n]", name);
            //     if (deleteStudent(students, &n, name))
            //         printf("\nStudent deleted successfully!\n");
            //     else
            //         printf("\nStudent not found!\n");
            //     break;
            // case 4:
            //     printf("\nEnter the ID of the student to modify: ");
            //     scanf("%d", &id);
            //     modifyStudent(students, n, id);
            //     break;
            // case 5:
            //     printf("\nExiting program...\n");
            //     break;
            default:
                printf("\nInvalid choice! Try again.\n");
        } 
    } while (choice != 5);

    return 0;
}
