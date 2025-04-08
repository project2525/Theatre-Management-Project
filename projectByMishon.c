#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TOTAL_SEATS 120
#define ROWS 10
#define COLS 12

// Global variables
int seats[TOTAL_SEATS] = {0};
int ticketPrice = 500;
int totalTickets = 0;
int bookedSeats[120];
char movieName[50], timeSelected[50], dateSelected[50], hall[50], paymentMethod[50];
char userName[50];
char userEmail[100];
char userPhone[20];

// On-going and Upcoming movie lists
char ongoingMovies[3][50] = {"Mufasa", "La La Land", "Dunki"};
char upcomingMovies[5][50] = {"The Flash", "Guardians of the Galaxy Vol. 3", "Avatar 2", "Jurassic World: Dominion", "Spider-Man: No Way Home"};

// Movie request structure
struct MovieRequest {
    char name[50];
    char email[100];
    char movie[100];
} requests[100];
int requestCount = 0;

// Function declarations
void On_goingMovies();
void select_movie();
void displaySeats();
void bookSeat(int seatNumber);
void runTheatreBooking();
void time_date_seat();
void buy_tickets();
void upcoming_movies();
void requestMovie();
void processPayment();
void cardPayment();
void mobileBanking();
void payment_receipt();
void admin_portal();
void updateMovieList();

int main() {
    int choice;
    do {
        printf("\n\n----- HOME PAGE -----\n");
        printf("1. On-going movies\n");
        printf("2. Buy Tickets\n");
        printf("3. See available seats\n");
        printf("4. Upcoming movies\n");
        printf("5. Movie request\n");
        printf("6. Payment\n");
        printf("7. View receipt\n");
        printf("8. Admin portal\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: On_goingMovies(); 
                    break;
            case 2: select_movie(); 
                    break;
            case 3: displaySeats(); 
                    break;
            case 4: upcoming_movies(); 
                    break;
            case 5: requestMovie(); 
                    break;
            case 6: processPayment(); 
                    break;
            case 7: payment_receipt(); 
                    break;
            case 8: admin_portal(); 
                    break;
            case 9: printf("Exiting...\n"); 
                    break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

void admin_portal() {
    char password[20];
    printf("\n--- Admin Portal Login ---\n");
    printf("Enter Admin Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(password, "admin123") == 0) {
        int adminChoice;
        do {
            printf("\n--- Admin Portal ---\n");
            printf("1. View all bookings\n");
            printf("2. View movie requests\n");
            printf("3. Update on-going movie list\n");
            printf("4. Update upcoming movie list\n");
            printf("5. Return to Home Page\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);
            getchar();

            switch (adminChoice) {
                case 1:
                    printf("\nTotal Tickets Booked: %d\n", totalTickets);
                    printf("Total Amount Collected: %d BDT\n", totalTickets * ticketPrice);
                    break;
                case 2:
                    printf("\n--- Requested Movies ---\n");
                    for (int i = 0; i < requestCount; i++) {
                        printf("Name: %s, Email: %s, Movie: %s\n", requests[i].name, requests[i].email, requests[i].movie);
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; i++) {
                        printf("Current Movie %d: %s\n", i + 1, ongoingMovies[i]);
                        printf("Enter new movie name: ");
                        fgets(ongoingMovies[i], sizeof(ongoingMovies[i]), stdin);
                        ongoingMovies[i][strcspn(ongoingMovies[i], "\n")] = '\0';
                    }
                    break;
                case 4:
                    for (int i = 0; i < 5; i++) {
                        printf("Upcoming Movie %d: %s\n", i + 1, upcomingMovies[i]);
                        printf("Enter new movie name: ");
                        fgets(upcomingMovies[i], sizeof(upcomingMovies[i]), stdin);
                        upcomingMovies[i][strcspn(upcomingMovies[i], "\n")] = '\0';
                    }
                    break;
                case 5: return;
                default: printf("Invalid choice!\n");
            }
        } while (adminChoice != 5);
    } else {
        printf("Incorrect password! Access denied.\n");
    }
}

void requestMovie() {
    printf("\nEnter your name: ");
    fgets(requests[requestCount].name, sizeof(requests[requestCount].name), stdin);
    requests[requestCount].name[strcspn(requests[requestCount].name, "\n")] = '\0';

    printf("Enter your email: ");
    fgets(requests[requestCount].email, sizeof(requests[requestCount].email), stdin);
    requests[requestCount].email[strcspn(requests[requestCount].email, "\n")] = '\0';

    printf("Enter the name of the movie you want to request: ");
    fgets(requests[requestCount].movie, sizeof(requests[requestCount].movie), stdin);
    requests[requestCount].movie[strcspn(requests[requestCount].movie, "\n")] = '\0';

    printf("\nMovie request submitted successfully!\n");
    requestCount++;
}

void On_goingMovies() {
    int choice;
    do {
        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i + 1, ongoingMovies[i]);
        }
        printf("4. Return to HOME PAGE\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            strcpy(movieName, ongoingMovies[choice - 1]);
            time_date_seat();
        } else if (choice != 4) {
            printf("Please enter a valid choice!\n");
        }
    } while (choice != 4);
}

void select_movie() {
    On_goingMovies();
}

void displaySeats() {
    printf("\n        SCREEN THIS WAY\n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %2d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            int seatIndex = i * COLS + j;
            printf(seats[seatIndex] ? " X  " : "%3d ", seatIndex + 1);
        }
        printf("\n");
    }
}

void bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS || seats[seatNumber - 1]) {
        printf("Invalid or already booked seat!\n");
    } else {
        seats[seatNumber - 1] = 1;
        bookedSeats[totalTickets++] = seatNumber;
        printf("Seat %d successfully booked!\n", seatNumber);
    }
}

void runTheatreBooking() {
    int seatNumber;
    while (1) {
        displaySeats();
        printf("\nEnter seat number to book (1-120) or 0 to exit: ");
        scanf("%d", &seatNumber);
        if (seatNumber == 0) break;
        bookSeat(seatNumber);
    }
    printf("\nThank you for booking! Please proceed to payment from the Home Menu.\n");
}

void time_date_seat() {
    int time_choice, date_choice;
    printf("Select show-time:\n1. 11:20 am\n2. 4:20 pm\n3. 7:45 pm\nEnter your time choice: ");
    scanf("%d", &time_choice);
    printf("\nSelect show-date:\n1. 31/03/2025\n2. 07/04/2025\n3. 12/05/2025\nEnter your date choice: ");
    scanf("%d", &date_choice);

    strcpy(timeSelected, (time_choice == 1) ? "11:20 am" : (time_choice == 2) ? "4:20 pm" : "7:45 pm");
    strcpy(dateSelected, (date_choice == 1) ? "31/03/2025" : (date_choice == 2) ? "07/04/2025" : "12/05/2025");
    strcpy(hall, "Main Hall");

    buy_tickets();
    runTheatreBooking();
}

void buy_tickets() {
    printf("\n------ Ticket Booking Page ------\n");

    printf("Name: ");
    getchar(); // clear buffer
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = '\0';

    printf("Email address: ");
    fgets(userEmail, sizeof(userEmail), stdin);
    userEmail[strcspn(userEmail, "\n")] = '\0';

    printf("Contact number: ");
    fgets(userPhone, sizeof(userPhone), stdin);
    userPhone[strcspn(userPhone, "\n")] = '\0';

    printf("\nThank you, %s! Your ticket details have been recorded.\n", userName);
}

void payment_receipt() {
    FILE *receiptFile = fopen("ticket.txt", "a");
    if (receiptFile == NULL) {
        printf("Error opening receipt file.\n");
        return;
    }

    printf("\n------ Printing Receipt ------\n");

    fprintf(receiptFile, "\n======= TICKET RECEIPT =======\n");
    fprintf(receiptFile, "Name           : %s\n", userName);
    fprintf(receiptFile, "Email          : %s\n", userEmail);
    fprintf(receiptFile, "Contact Number : %s\n", userPhone);
    fprintf(receiptFile, "Movie          : %s\n", movieName);
    fprintf(receiptFile, "Date           : %s\n", dateSelected);
    fprintf(receiptFile, "Time           : %s\n", timeSelected);
    fprintf(receiptFile, "Hall           : %s\n", hall);
    fprintf(receiptFile, "Seats Booked   : ");

    for (int i = 0; i < totalTickets; i++) {
        fprintf(receiptFile, "%d ", bookedSeats[i]);
    }

    fprintf(receiptFile, "\nTotal Tickets  : %d\n", totalTickets);
    fprintf(receiptFile, "Total Amount   : %d BDT\n", totalTickets * ticketPrice);
    fprintf(receiptFile, "Payment Method : %s\n", paymentMethod);

    if (strcmp(paymentMethod, "Cash") == 0) {
        fprintf(receiptFile, "Note           : Please arrive early and pay in cash.\n");
    } else if (strcmp(paymentMethod, "Mobile Banking") == 0) {
        fprintf(receiptFile, "Note           : Payment confirmed via mobile banking.\n");
    } else if (strcmp(paymentMethod, "Card") == 0) {
        fprintf(receiptFile, "Note           : Paid via card successfully.\n");
    }

    fprintf(receiptFile, "==============================\n\n");
    fclose(receiptFile);

    printf("Receipt saved successfully to 'ticket.txt'\n");
}

void processPayment() {
    int method;
    printf("\n--- Payment Options ---\n");
    printf("1. Cash\n");
    printf("2. Card\n");
    printf("3. Mobile Banking\n");
    printf("Enter your payment method: ");
    scanf("%d", &method);
    getchar(); // clear buffer

    switch (method) {
        case 1:
            strcpy(paymentMethod, "Cash");
            printf("Payment will be made at the counter. Please arrive at least 30 minutes before your movie starts and don't forget to bring your eReceipt.\n");
            break;
        case 2:
            cardPayment();
            break;
        case 3:
            mobileBanking();
            break;
        default:
            printf("Invalid payment option.\n");
            return;
    }
}

void cardPayment() {
    char cardDetails[50];
    char cardHolder[80];
    char cardValid[30];
    printf("\ncard number: ");
    scanf("%s", cardDetails);
    printf("Card holder name: ");
    scanf("%s", cardHolder);
    printf("Card validation: ");
    scanf("%s", cardValid);
    strcpy(paymentMethod, "Card");
    printf("\nPayment Successful.\n");
    payment_receipt();
}

void mobileBanking() {
    char provider[30];
    char number[20];
    char trxID[20];

    printf("\n--- Mobile Banking Payment ---\n");
    printf("Enter Mobile Banking Provider (e.g., bKash, Nagad, Rocket): ");
    fgets(provider, sizeof(provider), stdin);
    provider[strcspn(provider, "\n")] = '\0';

    printf("Enter Mobile Number: ");
    fgets(number, sizeof(number), stdin);
    number[strcspn(number, "\n")] = '\0';

    printf("Enter Transaction ID: ");
    fgets(trxID, sizeof(trxID), stdin);
    trxID[strcspn(trxID, "\n")] = '\0';

    strcpy(paymentMethod, "Mobile Banking");
    printf("Payment successful through %s (Number: %s, TrxID: %s)\n", provider, number, trxID);
}

void upcoming_movies() {
    printf("\nUpcoming Movies:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, upcomingMovies[i]);
    }
    printf("\nSelect a movie to book tickets or press 0 to go back: ");
    int choice;
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
        strcpy(movieName, upcomingMovies[choice - 1]);
        select_movie();
    }
}
