/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 1 Part A.

Project 1 Part A: .
*/

#include <iostream>
#include <fstream>
#include <string>

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
    
    cout << g_word_count << endl;
    for (int i = 0; i < g_word_count; i++) {
        cout << g_words[i] << endl;
    }
}

int getIndex(string anotherword)
{
    for (int j = 0; j < g_word_count; j++) {
        if (g_words[j] == anotherword) {
            return j;
        }
    }
    return -1;
}

string getDefinition(string anotherword2)
{
    for (int j = 0; j < g_word_count; j++) {
        if (g_words[j] == anotherword2) {
            return g_definitions[j];
        }
    }
    return "NOT_FOUND";
}

string getPOS(string anotherword3)
{
    for (int j = 0; j < g_word_count; j++) {
        if (g_words[j] == anotherword3) {
            return g_pos[j];
        }
    }
    return "NOT_FOUND";
}

int countPrefix(string prefix)
{
    int h = 0;
    for (int j = 0; j < g_word_count; j++) {
        if (g_words[j].rfind(prefix, 0) == 0) {
            h++;
        }
    }
    return h;
}

bool addWord(string word, string definition, string pos) 
{
    if (getIndex(word) == -1) {

        g_words[g_word_count] = word;
        g_definitions[g_word_count] = definition;
        g_pos[g_word_count] = pos;
        g_word_count++;

        return true;
    }
    else if (g_word_count == g_MAX_WORDS) {
        return false;
    }
    else {
        return false;
    }
}

bool editWord(string word, string definition, string pos)
{
    if (getIndex(word) == -1) {
        return false;
    }
    else {
        int a = getIndex(word);
        g_words[a] = word;
        g_definitions[a] = definition;
        g_pos[a] = pos;
        return true;
    }
}

bool removeWord(string word)
{
    if (getIndex(word) == -1) {
        return false;
    }
    else {
        for (int b = getIndex(word); b < g_word_count; b++) {
            g_words[b] = g_words[b+1];
            g_definitions[b] = g_definitions[b+1];
            g_pos[b] = g_pos[b+1]; 
        }
        g_word_count = g_word_count - 1;
        return true;
    }
}

/*
int main()
{
    readWords("Project_Words.txt");

    string new_word, new_def, new_pos;
    cout << "Enter word: "; cin >> new_word;
    cout << "Enter Def: "; cin >> 
    cout << "Enter Pos: "; getline(cin, new_pos);


    addWord(new_word, new_def, new_pos);
    for (int i = 0; i < g_word_count; i++) {
        cout << g_words[i] << " " << g_definitions[i] << " " << g_pos[i] << endl;
    }
    
    return 0;
} */