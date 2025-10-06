//COMSC-210 | Lab 19 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//declaring the Movie class
class Movie
{
    //declaring the private class functions
    private:
        //declaring a private struct to store the information on specific class objects that will be added to a linked list
        struct reviewNode
        {
            double rating;
            vector<string> comments;
            reviewNode *next;
        };
        //declaring an initializing private class functions
        string title;
        reviewNode * head = nullptr;

    //declaring the public class functions that will be used to properly obtain and display data
    public:
        //void function that obtains the movie title from the text file and sets the title of the current class object to said string value
        void setMovieTitle(string t) {title = t;}
        //function that generates a random double value for the reviews of the movies
        double randomRating()
        {   
            //adjusting the output so that it displays only one decimal point
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(1);
            //randomizer that finds a random double variable within our given range as the typical rand() function can only find integers
            double r = 1.0 + (static_cast<double>(rand()) / RAND_MAX) * 4.0;

            //returns this rating
            return r;
        }

        //function that adds the reviews and ratings to a new node of the linked list
        void addReview(double rating, vector<string> comment) 
        {
            //declares a new node for the linked list
            reviewNode* newReview = new reviewNode;

            //if there is no head then make the new node the head and update the values of the node so that they match the new node
            if (!head)
            {
                head = newReview;
                newReview->next = nullptr;
                newReview->rating = rating;
                newReview->comments = comment;
            }
            //if there is already a head still set the new node the head and update the values of the node so that they match the new node
            else 
            {
                newReview->next = nullptr;
                newReview->rating = rating;
                newReview->comments = comment;
                head = newReview;
            }
        }
        //outputs all of the information that was gathered throughout the program including movie title, the movie rating, and the movie reviews
        void displayReviews()
        {
            //outputs the movie title
            cout << "Movie Title: " << title << endl;
            reviewNode* current = head;

            //while loop that checks if we are at the end of the linked list and if we are not, then outputs the information at the current node
            while (current != nullptr) 
            {
                //outputs the rating of the current node's film
                cout  << setw(13) << "Rating: " << current->rating << endl;
                //for loop that shows all of the reviews that were gathered into the vector
                for(int i = 0; i < current->comments.size(); i++)
                    cout  << setw(22) << "Review Comment: \"" << current->comments[i] << "\"" << endl;
                current = current->next;
            }
            cout << endl;

            deleteList();
        }

        //function that traverses the linked list and deletes each node individually until the entirety of the linked list is deleted
        void deleteList()
        {
            // deleting the linked list
            reviewNode *current = head;
            while (current) {
                head = current->next;
                delete current;
                current = head;
            }
            head = nullptr;
        }
};

int main()
{
    //this function ensures that our rand() function will generate different numbers each time it is called
    srand(time(0));
    
    //declaring the vectors for both the movie class objects and the reveiews for each individual movie
    vector <Movie> movies_c;
    vector <string> reviews;

    //opens the input file
    ifstream fin ("input.txt");
    
    //declaring the variables that we will be using to update our linked list
    string title;
    double rS;
    string rN;

    //while the file input is good, this loop will continue to run
    if(fin.good())
    {
        //while loop that begins by gathering the title of the movie
        while(getline(fin, title))
        {
            //while loop that continuously gathers the lines of review comments and adds them to the reviews vector
            while(getline(fin, rN))
            {
                if(rN.empty()) break;
                else
                {
                    reviews.push_back(rN);
                }
            }

            //declaring a temporary class object
            Movie temp;

            //calling on the class functions to set all of the information to what we gathered from the file
            temp.setMovieTitle(title);
            rS = temp.randomRating();
            temp.addReview(rS, reviews);
            movies_c.push_back(temp);

            //clears the reviews vector so that comments do not carry over into the next time this vector is used
            reviews.clear();
        }

        //closes the file input
        fin.close();
    }
    //if the file cannot be found or opened this message is outputted
    else
        cout << "Input file not found.\n";

    //traverses the vector so that the linked list can display its class objects
    for (auto val : movies_c)
        val.displayReviews();
        
    //clears the vector storing the movie class objects
    movies_c.clear();
    
    return 0;
}