#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Media {
    string title;
    string genre;
    int year;
    bool watched;
};

int main() {
    vector<Media> watchlist;
    int choice;

    do {
        cout << "\n===== WatchList Menu =====\n";
        cout << "1. Add Media\n";
        cout << "2. Show All Media\n";
        cout << "3. Filter by Genre\n";
        cout << "4. Show Watched\n";
        cout << "5. Show Unwatched\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buffer temizleme

        switch (choice) {
        case 1: {
            Media m;
            cout << "Enter Title: ";
            getline(cin, m.title);

            cout << "Enter Genre: ";
            getline(cin, m.genre);

            cout << "Enter Year: ";
            cin >> m.year;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buffer temizleme

            cout << "Watched? (1 = Yes, 0 = No): ";
            cin >> m.watched;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buffer temizleme

            watchlist.push_back(m);
            cout << "Media added successfully!\n";
            break;
        }
        case 2: {
            if (watchlist.empty()) {
                cout << "No media found.\n";
            }
            else {
                cout << "\n--- All Media ---\n";
                for (size_t i = 0; i < watchlist.size(); i++) {
                    cout << i + 1 << ". "
                        << watchlist[i].title
                        << " (" << watchlist[i].year << ") - "
                        << watchlist[i].genre
                        << " - "
                        << (watchlist[i].watched ? "Watched" : "Not Watched")
                        << endl;
                }
            }
            break;
        }
        case 3: {
            if (watchlist.empty()) {
                cout << "Media is empty.\n";
            }
            else {
                string filterGenre;
                cout << "Enter genre to filter: ";
                getline(cin, filterGenre);

                bool found = false;
                cout << "\n--- Media in Genre: " << filterGenre << " ---\n";
                for (size_t i = 0; i < watchlist.size(); i++) {
                    if (watchlist[i].genre == filterGenre) {
                        cout << i + 1 << ". "
                            << watchlist[i].title
                            << " (" << watchlist[i].year << ") - "
                            << (watchlist[i].watched ? "Watched" : "Not Watched")
                            << endl;
                        found = true;
                    }
                }
                if (!found) cout << "No media found in this genre.\n";
            }
            break;
        }
        case 4: {
            if (watchlist.empty()) {
                cout << "Media is empty.\n";
            }
            else {
                cout << "\n--- Watched Media ---\n";
                bool found = false;
                for (size_t i = 0; i < watchlist.size(); i++) {
                    if (watchlist[i].watched) {
                        cout << i + 1 << ". "
                            << watchlist[i].title
                            << " (" << watchlist[i].year << ") - "
                            << watchlist[i].genre
                            << endl;
                        found = true;
                    }
                }
                if (!found) cout << "No watched media found.\n";
            }
            break;
        }
        case 5: {
            if (watchlist.empty()) {
                cout << "Media is empty.\n";
            }
            else {
                cout << "\n--- Unwatched Media ---\n";
                bool found = false;
                for (size_t i = 0; i < watchlist.size(); i++) {
                    if (!watchlist[i].watched) {
                        cout << i + 1 << ". "
                            << watchlist[i].title
                            << " (" << watchlist[i].year << ") - "
                            << watchlist[i].genre
                            << endl;
                        found = true;
                    }
                }
                if (!found) cout << "No unwatched media found.\n";
            }
            break;
        }
        case 6:
            cout << "Exiting WatchList... Bye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
