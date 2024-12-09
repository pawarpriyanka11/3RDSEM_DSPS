/*A Music Library System is a software application used to manage
the storage and retrieval of music tracks and albums. System need
to maintain information such as track title, artist, album, genre, duration, release year, and any other relevant attributes. System
should able to add new music track, remove the track, update the
information of the track, search the specific track also it should
display the information of all the track which are present in the
database. Use the Concept of Circular Linked list to implement the
above system*/




#include <iostream>
using namespace std;

struct MusicTrack {
    char title[100];
    char artist[100];
    MusicTrack* next;
};

class MusicLibrary {
private:
    MusicTrack* head;

public:
    MusicLibrary() {
        head = NULL;
    }

    // Function to add a new track
    void addTrack() {
        MusicTrack* newTrack = new MusicTrack;
        cout << "Enter track title: ";
        cin >> newTrack->title;
        cout << "Enter artist name: ";
        cin >> newTrack->artist;
        
        if (head == NULL) {
            head = newTrack;
            newTrack->next = head; // Circular link
        } else {
            MusicTrack* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newTrack;
            newTrack->next = head; // Circular link
        }
        cout << "Track added!" << endl;
    }

    // Function to display all tracks
    void displayTracks() {
        if (head == NULL) {
            cout << "No tracks to display." << endl;
            return;
        }
        MusicTrack* temp = head;
        do {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Function to search for a track by title
    void searchTrack() {
        char searchTitle[100];
        cout << "Enter track title to search: ";
        cin >> searchTitle;

        MusicTrack* temp = head;
        bool found = false;
        do {
            if (strcmp(temp->title, searchTitle) == 0) {
                cout << "Track found!" << endl;
                cout << "Title: " << temp->title << ", Artist: " << temp->artist << endl;
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Track not found." << endl;
        }
    }

    // Function to remove a track
    void removeTrack() {
        char searchTitle[100];
        cout << "Enter track title to remove: ";
        cin >> searchTitle;

        if (head == NULL) {
            cout << "No tracks to remove." << endl;
            return;
        }

        MusicTrack* temp = head;
        MusicTrack* prev = NULL;

        // Search for the track to remove
        do {
            if (strcmp(temp->title, searchTitle) == 0) {
                if (prev == NULL) { // Removing head
                    MusicTrack* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    if (head->next == head) { // Only one element
                        delete head;
                        head = NULL;
                    } else {
                        last->next = temp->next;
                        head = temp->next;
                        delete temp;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "Track removed!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Track not found." << endl;
    }
};

int main() {
    MusicLibrary library;
    int choice;

    do {
        cout << "\nMusic Library System" << endl;
        cout << "1. Add a track" << endl;
        cout << "2. Display all tracks" << endl;
        cout << "3. Search for a track" << endl;
        cout << "4. Remove a track" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addTrack();
                break;
            case 2:
                library.displayTracks();
                break;
            case 3:
                library.searchTrack();
                break;
            case 4:
                library.removeTrack();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
