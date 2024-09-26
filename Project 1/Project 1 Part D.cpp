/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 1 Part D.

Project 1 Part D: Hang man game.
*/

#include <iostream>
#include <stdlib.h>
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

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(string word)
{
    string spaces;
    for (int j = 0; j < word.length(); j++) {
        spaces += "_";
    }
    return spaces;
}

int getTries(int difficulty)
{
    if (difficulty == 0) {
        return 9;
    }
    else if (difficulty == 1) {
        return 7;
    }
    else if (difficulty == 2) {
        return 5;
    }
    
    return 0;
}

void printAttempts(int tries, int difficulty)
{
    int a = tries;
    int b = getTries(difficulty);

    for (int i = 0; i < b; i++) {
        if (i < a) {
            cout << "O";
        }   
        else {
            cout << "X";
        }

    }

}

bool revealLetter(string word, char letter, string &current)
{
    bool subject = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            subject = true;
            current[i] = letter;
        }
    }

    cout << current << endl;
    return subject;
}

void gameLoop() 
{
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}
