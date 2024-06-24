#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isKeyword(const string& word, const string keywords[], int size) {
    for (int i = 0; i < size; i++) {
        if (word == keywords[i]) {
            return true;
        }
    }
    return false;
}

bool isOperator(const string& word, const string operators[], int size) {
    for (int i = 0; i < size; i++) {
        if (word == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isDelimiter(char ch, const char delimiters[], int size) {
    for (int i = 0; i < size; i++) {
        if (ch == delimiters[i]) {
            return true;
        }
    }
    return false;
}

bool isValidIdentifier(const string& word) {
    if (word.empty() || (!isalpha(word[0]) && word[0] != '_')) {
        return false;
    }
    for (char ch : word) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}

void labt3() {
    string txt;
    string keywords[] = {"char", "double", "int", "String", "cin", "cout", "main"};
    string operators[] = {"+", "-", "*", "/", "=", "<<", ">>"};
    char delimiters[] = {'(', ')', ';', '{', '}'};

    ifstream file("m.txt");
    if (!file.is_open()) {
        cout << "File cannot open!" << endl;
        return;
    }

    while (getline(file, txt)) {
        istringstream iss(txt);
        string word;
        while (iss >> word) {
            // Check if the word is a keyword
            if (isKeyword(word, keywords, 7)) {
                cout << "Keyword: " << word << endl;
            }
            // Check if the word is an operator
            else if (isOperator(word, operators, 7)) {
                cout << "Operator: " << word << endl;
            }
            // Check if the word contains delimiters
            else {
                string buffer;
                for (char ch : word) {
                    if (isDelimiter(ch, delimiters, 5)) {
                        if (!buffer.empty()) {
                            if (isValidIdentifier(buffer)) {
                                cout << "Valid Identifier: " << buffer << endl;
                            } else {
                                cout << "Invalid Identifier: " << buffer << endl;
                            }
                            buffer.clear();
                        }
                        cout << "Delimiter: " << ch << endl;
                    } else {
                        buffer += ch;
                    }
                }
                if (!buffer.empty()) {
                    if (isValidIdentifier(buffer)) {
                        cout << "Valid Identifier: " << buffer << endl;
                    } else {
                        cout << "Invalid Identifier: " << buffer << endl;
                    }
                }
            }
        }
    }

    file.close();
}

int main() {
    labt3();
    return 0;
}
