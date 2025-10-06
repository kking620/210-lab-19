#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Movie
{
    private:
    string movieTitle;
    Node movieInfo;
};

struct Node {
    float value;
    string comments;
    Node *next;
};

void addToHead(float val, string com, Node *&hd);
void output(float val, int c, Node * hd);
void deleteList(Node *hd);

int main()
{
    Node *head = nullptr;
    int count = 0;
    float reviewScore;
    float totalScore;
    string reviewNotes;
    char response;

    cout << "Enter a review? Y/N ";
    cin >> response;
    cin.ignore();

    if (response == 'y' || response == 'Y') 
    {
        //asks the user whether they would like to insert the previously obtained random value at the head or the tail end of the linked list
        while (true)
        {
            if(response == 'Y' || response == 'y')
            {
                count++;
                
                cout << "Enter review rating 0-5: ";
                cin >> reviewScore;
                cin.ignore();

                totalScore += reviewScore;

                cout << "Enter review comments: ";
                getline(cin, reviewNotes);

                //determines, which function will be called to either add the value found to the front or back of the linked list respectively
                addToHead(reviewScore, reviewNotes, head);
            }
                
            cout << "Enter another review? Y/N: ";
            cin >> response;
            cin.ignore();

            if (response == 'n' || response == 'N') break;
            else if(response != 'Y' && response != 'y' && response != 'n' && response != 'N')
                cout << "Invalid response. Please try again.\n"; 
        }
    }

    output(totalScore, count, head);
    deleteList(head);

    return 0;
}

void output( float val, int c, Node * hd) 
{
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;

    cout << "Outputting all reviews:\n";

    while (current) 
    {
        cout << setw(15) << "> Review #" << count++ << ": " << current->value << ": " << current->comments << endl;
        current = current->next;
    }

    float average = val / c;
    cout << setw(24) << "> Average Rating : " << average << endl;
}

void addToHead(float val, string com, Node *&hd)
{
    Node *newVal = new Node;
        
    // if this is the first node, it's the new head
        if (!hd) 
        { 
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = val;
            newVal->comments = com;
        }
        // if its a second or subsequent node; place at the head
        else 
        {
            newVal->next = hd;
            newVal->value = val;
            newVal->comments = com;
            hd = newVal;
        }
}

void deleteList(Node *hd)
{
    // deleting the linked list
    Node *current = hd;
    while (current) 
    {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}