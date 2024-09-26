/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 1 Part A.

Project 1 Part A: .
*/

#include <iostream>
#include <fstream>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];


void readWords(string file_name)
{
    ifstream fin(file_name);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string words, definitions, colons, pos, line;

    while (fin >> words >> pos >> colons) {

        getline(fin >> ws, definitions);
        g_words[g_word_count] = words;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = definitions;
        g_word_count++;
        
    }
    /*
    cout << g_word_count << endl;
    for (int i = 0; i < g_word_count; i++) {
        cout << g_definitions[i] << endl;
    } */
}

/*
int main()
{
    string file_new;
    cout << "Enter file: "; cin >> file_new;
    readWords(file_new);
    return 0;
} */