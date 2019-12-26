
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class HighScore
{
private:
    int high_score;

public:
    HighScore() // loads the highscore from the file
    {
        char ch;
        std::string final;
        fstream fin("Highest.txt", fstream::in);
        while (fin >> noskipws >> ch)
        {
            final = final + ch;
        }
        stringstream geek(final);
        geek >> high_score;
    }

    int get_score()
    {
        return high_score;
    }
    void set_score(int score)
    {
        if (score > high_score) // if the current score is greater than highscore then update the highscore
        {
            ofstream myfile;
            myfile.open("Highest.txt");
            myfile << score;
            myfile.close();
        }
    }
    void Reset()
    {
        ofstream myfile;
        myfile.open("Highest.txt");
        myfile << 0;
        myfile.close();
    }
};
