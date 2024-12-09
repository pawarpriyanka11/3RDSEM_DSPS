/*A Charity Management system need to manage the information
about donors, donations and other relevant data. System need to
maintain information about each donors. System should able to
add new donor, remove the donor, update the information of the
donor, search the specific donor also it should display the
information of all the donor which are present in the database. Use
the concept of the Linked List to implement the above system*/

#include <iostream>
#include <string>
using namespace std;

struct Donor {
    string name;
    string contactNumber;
    int totalDonation;
    Donor* next = NULL;
};

class CharityManagement {
public:
    Donor* head;
    CharityManagement() {
        head = NULL;
    }

    // Add a new donor
    void addDonor(string name, string contact, int donation) {
        Donor* newDonor = new Donor;
        newDonor->name = name;
        newDonor->contactNumber = contact;
        newDonor->totalDonation = donation;
        newDonor->next = head;
        head = newDonor;
        cout << "Donor added: " << name << endl;
    }

    // Remove a donor by name
    void removeDonor(string name) {
        if (head == NULL) {
            cout << "No donors in the database." << endl;
            return;
        }

        // If the first donor has the name we want to remove
        if (head->name == name) {
            Donor* temp = head;
            head = head->next;
            delete temp;
            cout << "Donor " << name << " removed." << endl;
            return;
        }

        Donor* current = head;
        while (current->next != NULL) {
            if (current->next->name == name) {  // Check the name of the next donor
                Donor* temp = current->next;  // Store the next donor in temp
                current->next = current->next->next;  // Remove the donor
                delete temp;
                cout << "Donor " << name << " removed." << endl;
                return;
            }
            current = current->next;  // Move to the next donor
        }

        cout << "Donor " << name << " not found." << endl;
    }

    // Update donor information by name
    void updateDonor(string name) {
        Donor* current = head;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Enter new contact number: ";
                cin >> current->contactNumber;
                cout << "Enter new total donation amount: ";
                cin >> current->totalDonation;
                cout << "Donor information updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Donor " << name << " not found." << endl;
    }

    // Search for a donor by name
    void searchDonor(string name) {
        Donor* current = head;
        while (current) {
            if (current->name == name) {
                cout << "Donor found: " << endl;
                cout << "Name: " << current->name << ", Contact Number: " << current->contactNumber
                     << ", Total Donation: $" << current->totalDonation << endl;
                return;
            }
            current = current->next;
        }
        cout << "Donor " << name << " not found." << endl;
    }

    // Display all donors
    void displayDonors() {
        if (head == NULL) {
            cout << "No donors in the database." << endl;
            return;
        }

        Donor* current = head;
        while (current != NULL) {
            cout << "Name: " << current->name << ", Contact Number: " << current->contactNumber
                 << ", Total Donation: $" << current->totalDonation << endl;
            current = current->next;
        }
    }

    // Destructor to free memory
    ~CharityManagement() {
        while (head) {
            Donor* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CharityManagement charity;
    int choice;
    string name, contact;
    int donation;

    do {
        cout << "\nCharity Management System\n";
        cout << "1. Add Donor\n";
        cout << "2. Remove Donor\n";
        cout << "3. Update Donor Information\n";
        cout << "4. Search for Donor\n";
        cout << "5. Display All Donors\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline character

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter contact number: ";
                cin >> contact;
                cout << "Enter total donation amount: ";
                cin >> donation;
                charity.addDonor(name, contact, donation);
                break;

            case 2:
                cout << "Enter name of the donor to remove: ";
                cin >> name;
                charity.removeDonor(name);
                break;

            case 3:
                cout << "Enter name of the donor to update: ";
                cin >> name;
                charity.updateDonor(name);
                break;

            case 4:
                cout << "Enter name of the donor to search: ";
                cin >> name;
                charity.searchDonor(name);
                break;

            case 5:
                cout << "\nDisplaying all donors:\n";
                charity.displayDonors();
                break;

            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
