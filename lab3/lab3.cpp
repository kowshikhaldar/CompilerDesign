#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void labt3()
{
    string txt;
    string keywords[] = {"char", "double", "int", "String", "cin", "cout", "main"};
    char operators[] = {'+', '-', '*', '/', '=', '%'};
    char delimiters[] = {'(', ')', ';', '{', '}', ' '};

    ifstream file("m.txt");
    if (!file.is_open())
    {
        cout << "File cannot open!" << endl;
    }
    while (getline(file, txt))
    {
        istringstream iss(txt);

        // cout << txt << endl;
        do
        {
            string word;
            iss >> word;

            cout << "Identifier:" << word << endl;

            for (int i = 0; i < word.length(); i++)
            {
                bool opflag = false;
                bool deliflag = false;
                for (int j = 0; j < 6; j++)
                {

                    if (word[i] == operators[j])
                    {
                        opflag = true;
                        cout << "Operator:" << operators[j] << endl;
                    }
                    if (word[i] == delimiters[j])
                    {
                        deliflag = true;
                        cout << "Delimiter:" << delimiters[j] << endl;
                    }
                }
                if (isdigit(word[i]))
                {
                    cout << "Integer:" << word[i] << endl;
                }

            }

        } while (iss);
    }

    file.close();
}

void test()
{
    string aa = "This is a no";
    string res;
    for (int i = 0; i < aa.length(); i++)
    {
        if (aa[i] != ' ')
        {
            res = res + aa[i];
        }
    }
    cout << res;
}

int main()
{
    //  cout << "Hi";
    labt3();
    // test();
}