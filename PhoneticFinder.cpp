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
    //Initialize vector with all possible chars mistake exchange. Yea, call by reference... whatttt ?!?! what ?!?!?
    static inline void init_vectors(vector<vector<char>>  & letters)
    {
        //I have no choice but to inline it or otherwise all vectors will be popout of stack at the end of the function.
        vector<char> exchange_vw {'v', 'w'};
        vector<char> exchange_pbf {'p', 'b', 'f'};
        vector<char> exchange_gj {'g', 'j'};
        vector<char> exchange_ckq {'c', 'k', 'q'};
        vector<char> exchange_sz {'s', 'z'};
        vector<char> exchange_dt {'d', 't'};
        vector<char> exchange_ou {'o', 'u'};
        vector<char> exchange_iy {'i', 'y'};

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
    }
    
    string find(string text, string word)
    {
        vector<vector<char>> letters(ABC_SIZE);//For all abc letters
        init_vectors(letters);
        istringstream iss(text);//Initialize streamstring like split
        string token;
        string target = "";

        //Lower case the word to search
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        while(iss >> token)
        {
            //Strings needs to be in the same length in order to be candidate
            if(token.length() == word.length())
            {
                //Because we don't want to destroy the original word lower cased word
                string temp_word(word);

                int counter_match_letters = 0;
                //Check wether the word could have bin the searched token
                for(int i = 0; i < temp_word.length(); i++)
                {
                    char curr_ch = temp_word.at(i);
                    //Check if there is a potential wrong character
                    if(curr_ch != token.at(i))
                    {
                        auto exchange_vec = letters.at(curr_ch);
                        bool found_char = false;
                        if(!exchange_vec.empty())
                        {
                            for(int j = 0; j < exchange_vec.size(); j++)
                            {
                                if(exchange_vec.at(j) == token.at(i))
                                {
                                    found_char = true;
                                    counter_match_letters++;
                                    break;
                                }
                            }
                        }

                        //If it's true, that means this is not the word we are searching for
                        if(!found_char)
                        {
                            break;
                        }
                    }
                    else//If they are equals, moves to the next letter
                    {
                        counter_match_letters++;
                    }
                }


                if(counter_match_letters == token.length())
                {
                    //We have a match !
                    target = token;
                }

            }
        }

        if(target == "")
        {
            //Let's format an output message !
            ostringstream oss;
            oss << "No such word " << word << endl;
            string output = oss.str();
            throw invalid_argument(output);
        }

        return target;
    }
}