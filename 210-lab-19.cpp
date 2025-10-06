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
            srand(time(0));
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
        void displayReviews(string title, double rating, string comment)
        {
            cout << "Movie: " << title << endl;
            reviewNode* current = head;

            while (current != nullptr) 
            {
                cout << "  Rating: " << current->rating << ", Review Comments: \"" << current->comments << "\"" << endl;
                current = current->next;
            }
            cout << std::endl;
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
    vector <Movie> movies_c;
    
    ifstream fin ("input.txt");
    
    string title;
    double rS;
    string rN;

    if(fin.good())
    {
        while(getline(fin, title))
        {
            Movie temp;

            rS = temp.randomRating();
        }
        
    }

    

    return 0;
}