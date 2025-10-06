#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Movie
{
    private:
        struct reviewNode
        {
            double rating;
            string comments;
            reviewNode *next;
        };
        
        string title;
        reviewNode * head = nullptr;

    public:
        void setMovieTitle(string t) {title = t;}
        double randomRating()
        {
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(1);
            double r = 1.0 + (static_cast<double>(rand()%5));

            return r;
        }

        void addReview(double rating, string comment) 
        {
            reviewNode* newReview = new reviewNode;
            if (!head)
            {
                head = newReview;
                newReview->next = nullptr;
                newReview->rating = rating;
                newReview ->comments = comment;
            }
            else 
            {
                newReview->next = nullptr;
                newReview->rating = rating;
                newReview ->comments = comment;
                head = newReview;
            }
        }
        void displayReviews()
        {
            cout << "Movie Title: " << title << endl;
            reviewNode* current = head;

            while (current != nullptr) 
            {
                cout  << setw(13) << "Rating: " << current->rating << endl;
                cout  << setw(23) << "Review Comment: \"" << current->comments << "\"" << endl;
                current = current->next;
            }
            cout << endl;
        }
        void deleteList()
        {
            reviewNode *current = head;
            while (current) 
            {
                head = current->next;
                delete current;
                current = head;
            }
            head = nullptr;
        }
};

int main()
{
    srand(time(0));
    
    vector <Movie> movies_c;
    
    ifstream fin ("input.txt");
    
    string title;
    double rS;
    string rN;

    if(fin.good())
    {
        while(getline(fin, title))
        {
            getline(fin, rN);
            fin.ignore();

            Movie temp;

            temp.setMovieTitle(title);
            rS = temp.randomRating();
            temp.addReview(rS, rN);
            movies_c.push_back(temp);
        }

        fin.close();
    }
    else
        cout << "Input file not found.\n";

    for (auto val : movies_c)
        val.displayReviews();

    return 0;
}