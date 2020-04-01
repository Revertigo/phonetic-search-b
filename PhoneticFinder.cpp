#include "PhoneticFinder.hpp"
#include <string>
#include <sstream> 
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

#define ABC_SIZE 26
#define ALIGN_ASCII 'a' //How much to reduce from 'a' char to get it's offset from start

namespace phonetic
{
    static void init_vectors(vector<vector<char>>  & letters);
    static int check_single_token(vector<vector<char>>  & letters ,string token, string word);
    static bool check_mistake(vector<char> exchange_vec, char curr);
    static void handle_word_not_found(string target);


    static void handle_word_not_found(string target, string word)
    {
        if(target == "")
        {
            //Let's format an output message !
            ostringstream oss;
            oss << "No such word " << word << endl;
            string output = oss.str();
            throw invalid_argument(output);
        }
    }

    static bool check_mistake(vector<char> exchange_vec, char curr)
    {
        //Check if there is a potential character that could match the current character from the token
        bool found_char = false;
        if(!exchange_vec.empty())
        {
            for(int j = 0; j < exchange_vec.size(); j++)
            {
                if(exchange_vec.at(j) == curr)
                {
                    found_char = true;
                    break;
                }
            }
        }

        return found_char;
    }

    static int check_single_token(vector<vector<char>>  & letters ,string token, string word)
    {
        int counter_match_letters = 0;
        //Lower case the token to search
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        bool found_char = true;
        for(int i = 0; i < word.length() && found_char; i++)
        {
            char curr_ch = word.at(i);

            //Only if the letters are equals, or there is other char that typed wrong(v instead of w etc) we increment counter
            if(curr_ch == token.at(i) || check_mistake(letters.at(curr_ch - ALIGN_ASCII), token.at(i)))
            {
                //Check if there is a potential to find a char which equals to token.at(i)
                counter_match_letters++;
            }
            else//If they are equals, moves to the next letter
            {
                found_char = false;
            }
        }

        return counter_match_letters;
    }

    //Initialize vector with all possible chars mistake exchange. Yea, call by reference... whatttt ?!?! what ?!?!?
    static void init_vectors(vector<vector<char>>  & letters)
    {
        vector<char> exchange_vw {'v', 'w'};
        vector<char> exchange_pbf {'p', 'b', 'f'};
        vector<char> exchange_gj {'g', 'j'};
        vector<char> exchange_ckq {'c', 'k', 'q'};
        vector<char> exchange_sz {'s', 'z'};
        vector<char> exchange_dt {'d', 't'};
        vector<char> exchange_ou {'o', 'u'};
        vector<char> exchange_iy {'i', 'y'};

        //Copy assignment operator(takes a lvalue as an argument, while move constructor takes rvalue)
        letters['v' - ALIGN_ASCII] = exchange_vw;
        letters['w' - ALIGN_ASCII] = exchange_vw;

        letters['p' - ALIGN_ASCII] = exchange_pbf;
        letters['b' - ALIGN_ASCII] = exchange_pbf;
        letters['f' - ALIGN_ASCII] = exchange_pbf;

        letters['g' - ALIGN_ASCII] = exchange_gj;
        letters['j' - ALIGN_ASCII] = exchange_gj;

        letters['c' - ALIGN_ASCII] = exchange_ckq;
        letters['k' - ALIGN_ASCII] = exchange_ckq;
        letters['q' - ALIGN_ASCII] = exchange_ckq;

        letters['s' - ALIGN_ASCII] = exchange_sz;
        letters['z' - ALIGN_ASCII] = exchange_sz;

        letters['d' - ALIGN_ASCII] = exchange_dt;
        letters['t' - ALIGN_ASCII] = exchange_dt;

        letters['o' - ALIGN_ASCII] = exchange_ou;
        letters['u' - ALIGN_ASCII] = exchange_ou;

        letters['i' - ALIGN_ASCII] = exchange_iy;
        letters['y' - ALIGN_ASCII] = exchange_iy;
    }
    
    string find(string text, string word)
    {
        vector<vector<char>> letters(ABC_SIZE);//For all abc letters
        init_vectors(letters);
        istringstream iss(text);//Initialize istreamstring for split
        string token;
        string target = "";

        //Lower case the word to search
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        while(iss >> token && target == "")
        {
            //Strings needs to be in the same length in order to be candidate
            if(token.length() == word.length())
            {
                //Check whether the word could be the searched token
                int counter_match_letters = check_single_token(letters, token, word);

                if(counter_match_letters == token.length())
                {
                    //We have a match ! this is the word we were looking for
                    target = token;
                }
            }
        }

        handle_word_not_found(target, word);
        return target;
    }
}