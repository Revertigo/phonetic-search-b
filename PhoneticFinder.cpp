#include "PhoneticFinder.hpp"
#include <string>
#include <sstream> 
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

#define ABC_SIZE 26
#define ALIGN_ASCII 97 //How much to reduce from a char to get it's offset from start

namespace phonetic
{
    string find(string text, string word)
    {
        vector<char> exchange_vw {'v', 'w'};
        vector<char> exchange_pbf {'p', 'b', 'f'};
        vector<char> exchange_gj {'g', 'j'};
        vector<char> exchange_ckq {'c', 'k', 'q'};
        vector<char> exchange_sz {'s', 'z'};
        vector<char> exchange_dt {'d', 't'};
        vector<char> exchange_ou {'o', 'u'};
        vector<char> exchange_iy {'i', 'y'};
        
        vector<vector<char>> letters(ABC_SIZE);//For all abc letters
        letters.insert(letters.begin() + 'v' - ALIGN_ASCII, exchange_vw);
        letters.insert(letters.begin() + 'w' - ALIGN_ASCII, exchange_vw);

        letters.insert(letters.begin() + 'p' - ALIGN_ASCII, exchange_pbf);
        letters.insert(letters.begin() + 'b' - ALIGN_ASCII, exchange_pbf);
        letters.insert(letters.begin() + 'f' - ALIGN_ASCII, exchange_pbf);

        letters.insert(letters.begin() + 'g' - ALIGN_ASCII, exchange_gj);
        letters.insert(letters.begin() + 'j' - ALIGN_ASCII, exchange_gj);

        letters.insert(letters.begin() + 'p' - ALIGN_ASCII, exchange_pbf);
        letters.insert(letters.begin() + 'b' - ALIGN_ASCII, exchange_pbf);
        letters.insert(letters.begin() + 'f' - ALIGN_ASCII, exchange_pbf);

        letters.insert(letters.begin() + 's' - ALIGN_ASCII, exchange_sz);
        letters.insert(letters.begin() + 'z' - ALIGN_ASCII, exchange_sz);
        
        letters.insert(letters.begin() + 'd' - ALIGN_ASCII, exchange_dt);
        letters.insert(letters.begin() + 't' - ALIGN_ASCII, exchange_dt);

        letters.insert(letters.begin() + 'o' - ALIGN_ASCII, exchange_ou);
        letters.insert(letters.begin() + 'u' - ALIGN_ASCII, exchange_ou);

        letters.insert(letters.begin() + 'i' - ALIGN_ASCII, exchange_iy);
        letters.insert(letters.begin() + 'y' - ALIGN_ASCII, exchange_iy);

        istringstream iss(text);//Initialize streamstring like split
        string token;
        string target = "";

        float max_match_percent = 0.0;
        //Lower case the word to search
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        while(iss >> token)
        {
            //Strings needs to be in the same length in order to be candidate
            if(token.length() == word.length())
            {
                float temp_match_percent = 0.0;
                int count_match = 0;
                string lc_token(token);//Because we don't want to destroy the original token
                //lower case token string
                transform(lc_token.begin(), lc_token.end(), lc_token.begin(), ::tolower);
                for(int i = 0; i < lc_token.length(); i++)
                {
                    if(lc_token.at(i) == word.at(i))
                    {
                        count_match++;
                    }
                }

                temp_match_percent = ((float)((count_match)) / lc_token.length()) * 100.0;
                if(temp_match_percent > max_match_percent)
                {
                    target = token;
                    max_match_percent = temp_match_percent;
                }
            }
        }

        // if(max_match_percent < THRESHOLD)
        // {
        //     //Let's format an output message !
        //     ostringstream oss;
        //     oss << "No such word " << word << endl;
        //     string output = oss.str();
        //     throw invalid_argument(output);
        // }

        return target;
    }
}