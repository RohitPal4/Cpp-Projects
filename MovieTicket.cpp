#include <iostream>
#include <vector>

using namespace std;

class BookingManager {
private:
    struct Booking {
        int ticket_id;
        string movie_name;
        string customer_name;
        int no_of_tickets;
        float ticket_price;
        float total_amount;

        Booking(int id, string movie, string customer, int tickets, float price) {
            ticket_id = id;
            movie_name = movie;
            customer_name = customer;
            no_of_tickets = tickets;
            ticket_price = price;
            total_amount = no_of_tickets * ticket_price;
        }

        void setTicketPrice(float price) {
            ticket_price = price;
            total_amount = no_of_tickets * ticket_price;
        }

        void printBooking() {
            cout << "Ticket ID: " << ticket_id << endl;
            cout << "Movie Name: " << movie_name << endl;
            cout << "Customer Name: " << customer_name << endl;
            cout << "No. of Tickets: " << no_of_tickets << endl;
            cout << "Ticket Price: " << ticket_price << endl;
            cout << "Total Amount: " << total_amount << endl << endl;
        }
    };

    vector<Booking> bookings;
    int ticket_counter = 0;

public:
    void bookTickets() {
        string movie, customer;
        int tickets;
        float price;
        cout << "Enter movie name: ";
        cin.ignore();
        getline(cin, movie);
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, customer);
        cout << "Enter number of tickets: ";
        cin >> tickets;
        cout << "Enter ticket price: ";
        cin >> price;

        bookings.push_back(Booking(++ticket_counter, movie, customer, tickets, price));
        cout << "Booking successful. Ticket ID: " << ticket_counter << endl;
    }

    void cancelTickets() {
        int ticket_id;
        cout << "Enter ticket ID to cancel: ";
        cin >> ticket_id;

        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->ticket_id == ticket_id) {
                bookings.erase(it);
                cout << "Ticket cancellation successful." << endl;
                return;
            }
        }

        cout << "Ticket with ID " << ticket_id << " not found." << endl;
    }

    void changeTicketPrice() {
        int ticket_id;
        float price;
        cout << "Enter ticket ID: ";
        cin >> ticket_id;
        cout << "Enter new ticket price: ";
        cin >> price;

        for (auto& booking : bookings) {
            if (booking.ticket_id == ticket_id) {
                booking.setTicketPrice(price);
                cout << "Ticket price changed successfully." << endl;
                return;
            }
        }

        cout << "Ticket with ID " << ticket_id << " not found." << endl;
    }

    void viewAllBookings() {
        if (bookings.empty()) {
            cout << "No bookings found." << endl;
            return;
        }

        cout << "All Booking Records:" << endl << endl;

        for (auto& booking : bookings) {
            booking.printBooking();
        }
    }
};

int main() {
    BookingManager manager;
    int choice;
     cout << "\n****************************************\n"
              << "*   Welcome my ticket Booking system   *\n"
              << "****************************************\n";

    while (true) {
        cout << endl;
        cout << "Movie Ticket Booking System" << endl;
        cout << "1. Book Tickets" << endl;
        cout << "2. Cancel Tickets" << endl;
        cout << "3. Change Ticket Price" << endl;
        cout << "4. View All Booking Records" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
            switch (choice) {
        case 1:
            manager.bookTickets();
            break;
        case 2:
            manager.cancelTickets();
            break;
        case 3:
            manager.changeTicketPrice();
            break;
        case 4:
            manager.viewAllBookings();
            break;
        case 5:
            cout << "Thank you for using the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

return 0;
}
