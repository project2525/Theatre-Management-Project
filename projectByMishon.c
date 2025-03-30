#include<stdio.h>
#include<string.h>

//function declaration
void On_goingMovies();
void select_movie();
void displaySeats();
void bookSeat(int seatNumber);
void startBooking();
void runTheatreBooking();
void time_date_seat();
void buy_tickets();
void upcoming_movies();
void requestMovie();
void processPayment();




#define TOTAL_SEATS 120
#define ROWS 10
#define COLS 12

int seats[TOTAL_SEATS] = {0};  // 0 = Available, 1 = Booked
int ticketPrice = 500; // Example ticket price
int totalTickets = 0;  // Stores the number of booked tickets

int main()
{
    int n, choice;
    char name[50];
    char movie[50];
    do {
        printf("\n\n----- HOME PAGE -----\n");
        printf("1. On-going movies\n");
        printf("2. Buy Tickets\n");
        printf("3. See available seats\n");
        printf("4. Upcoming movies\n");
        printf("5. Movie request\n");
        printf("6. Payment\n");
        printf("7. Save receipt\n");
        printf("8. Admin portal\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    
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

            default: printf("\nInvalid choice! Try again.\n");
        } 
    } while (choice != 8);

    return 0;
}

void On_goingMovies() {
    int choice;
    do {
        printf("\ni. Mufasa\n");
        printf("ii. La La Land\n");
        printf("iii. Dunki\n");
        printf("\n");
        printf("1. Buy Ticket\n");
        printf("2. Return to HOME PAGE\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: select_movie();
                break;

            case 2: return;
                    
            default: printf("Please enter a valid choice!\n");    /* eikhane baki aseee!!!!!!!! */
            }
        } while (choice != 2);
            
}

void select_movie() {
    int choice;
    do {
        printf("\n1. Mufasa\n");
        printf("2. La La Land\n");
        printf("3. Dunki\n");
        printf("4. Return to Home Page\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3: time_date_seat();
                break;

            case 4: return;

            default: printf("Invalid choice!!\n");
        }
    } while (choice != 3);
}

void displaySeats() {
    printf("\n        SCREEN THIS WAY\n\n");
    
    for (int i = 0; i < ROWS; i++) {
        printf("Row %2d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            int seatIndex = i * COLS + j;
            if (seats[seatIndex] == 0) {
                printf("%3d ", seatIndex + 1);  // Show seat number if available
            } else {
                printf(" X  ");  // Show 'X' for booked seats
            }
        }
        printf("\n");
    }
}
// Function to book a seat
void bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number! Choose between 1 and %d.\n", TOTAL_SEATS);
        return;
    }
    if (seats[seatNumber - 1] == 1) {
        printf("Seat %d is already booked! Choose another seat.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = 1;  // Mark seat as booked
        totalTickets++;  // Increment the number of booked tickets
        printf("Seat %d successfully booked!\n", seatNumber);
    }
}

// Function to start booking process
void startBooking() {
    int seatNumber;
    
    while (1) {
        displaySeats();
        
        printf("\nEnter seat number to book (1-120) or 0 to exit: ");
        scanf("%d", &seatNumber);
        
        if (seatNumber == 0) {
            printf("Thank you for booking! Please pay for ticket from Home Page :)\n");
            return;
        }
        
        bookSeat(seatNumber);
    }
}
// Entry function to call everything
void runTheatreBooking() {
    startBooking();
}
void time_date_seat() {
    int time_choice, date_choice;
        printf("Select show-time:\n");
        printf("1. 11:20 am \n2. 4:20 pm \n3. 7:45pm\n");
        printf("Enter your time choice: ");
        scanf("%d", &time_choice);
        printf("\n");
        printf("\nSelect show-date:\n");
        printf("1. 31/03/2025 \n2. 07/04/2025 \n3. 12/05/2025\n");
        printf("Enter your date choice: ");
        scanf("%d", &date_choice);
        printf("\n");

        buy_tickets();
        runTheatreBooking();
    }


void buy_tickets() {
    char name[50], email[100], contact[15];

        printf("\n------ Ticket Booking Page ------\n");

        fflush(stdin); // Flush the input buffer (may not work in GCC)
        printf("Name: ");
        gets(name);

        printf("EMAIL address: ");
        gets(email);

        printf("Contact number: ");
        gets(contact);

        printf("\nThank you, %s! Your ticket details have been recorded.\n", name);
}

void upcoming_movies() {
        printf("\n--- Upcoming Movies ---\n");
        printf("1. Deadpool & Wolverine\n");
        printf("2. Inside Out 2\n");
        printf("3. The Joker 2\n");
        printf("\nReturning to HOME PAGE...\n");
}

void requestMovie() {
    char movie[50];
    printf("\nEnter the name of the movie you want to request (Press enter to finish):\n");
    getchar();
    while (1) {
        fgets(movie, sizeof(movie), stdin);
        if (strcmp(movie, "\n") == 0) {
            break;
        }
        printf("Movie '%s' has been requested. Enter another or press enter to finish...\n", movie);
    }
}

void processPayment() {
    int paymentType, mobileChoice;
    char transactionID[50], phoneNumber[15];
    int totalAmount = totalTickets * ticketPrice;

    if (totalTickets == 0) {
        printf("\nNo tickets booked yet! Please book your tickets first.\n");
        return;
    }

    printf("\n--- Payment Options ---\n");
    printf("1. Cash Payment\n");
    printf("2. Mobile Banking\n");
    printf("3. Card Payment\n");
    printf("\nEnter your choice: ");
    scanf("%d", &paymentType);

    switch (paymentType) {
        case 1:
            printf("\nTotal amount: %d BDT\n", totalAmount);
            printf("Please arrive at least 30-40 minutes before the movie starts to complete the payment.\n");
            break;

        case 2:
            printf("\nChoose Mobile Banking Option:\n");
            printf("1. Bkash\n");
            printf("2. Nagad\n");
            printf("3. Rocket\n");
            printf("\nEnter your choice: ");
            scanf("%d", &mobileChoice);

            printf("\nTotal amount: %d BDT\n", totalAmount);
            printf("Payment number: 01XXXXXXXXX\n");

            printf("Enter your transaction ID: ");
            scanf("%s", transactionID);

            printf("Enter your mobile number used for payment: ");
            scanf("%s", phoneNumber);
            
            printf("\nPayment Successful! Transaction ID: %s\n", transactionID);
            break;

        case 3:
            printf("\nTotal amount: %d BDT\n", totalAmount);
            printf("Processing card payment...\n");
            printf("Payment Successful!\n");
            break;

        default:
            printf("\nInvalid payment option!\n");
    }
}
