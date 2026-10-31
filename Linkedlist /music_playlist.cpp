#include <iostream>
#include <string>
using namespace std;

struct Song { string title; int duration; Song* next; };   // duration in seconds
Song* head = NULL;

void addSong(string t, int d) {
    Song* s = new Song{t, d, NULL};
    if (!head) { head = s; return; }
    Song* p = head;
    while (p->next) p = p->next;
    p->next = s;
}

void display() {
    if (!head) { cout << "Playlist empty\n"; return; }
    int i = 1;
    for (Song* p = head; p; p = p->next, i++)
        cout << i << ". " << p->title << " (" << p->duration << " sec)\n";
}

void sortByTitle() {
    for (Song* i = head; i; i = i->next)
        for (Song* j = i->next; j; j = j->next)
            if (i->title > j->title) { swap(i->title, j->title); swap(i->duration, j->duration); }
}

void sortByDuration() {
    for (Song* i = head; i; i = i->next)
        for (Song* j = i->next; j; j = j->next)
            if (i->duration > j->duration) { swap(i->title, j->title); swap(i->duration, j->duration); }
}

int main() {
    int ch, d;
    string t;
    do {
        cout << "\n1.Add Song 2.Sort by Title 3.Sort by Duration 4.Display 5.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Title (no spaces): "; cin >> t; cout << "Duration (sec): "; cin >> d; addSong(t, d); break;
            case 2: sortByTitle(); cout << "Sorted by title\n"; break;
            case 3: sortByDuration(); cout << "Sorted by duration\n"; break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}