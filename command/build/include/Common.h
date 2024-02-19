//
// Created by dangnd on 0015, December 15, 2023.
//

#ifndef LEMP_BUILDARGS_H
#define LEMP_BUILDARGS_H

#include "vector"
#include "string"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

vector<string> buildArgs(int argc, char *argv[])
{
    vector<string> result;

    for (int i = 1; i < argc; i++)
    {
        result.push_back(argv[i]);
    }

    return result;
}

string getCurrentDir()
{
    char cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));

    return cwd;
}

vector<string> splitSentence(string str, int max)
{
    vector<string> result;

    if (str.empty()) {
        result.emplace_back("");

        return result;
    }

    while (!str.empty()) {
        if (str.length() < max) {
            max = (int) str.length();
        }

        string line = str.substr(0, max);

        str = str.substr(max);

        if (line.back() != ' ' && !str.empty()) {
            if (str.at(0) != ' ') {
                while (line.back() != ' ') {
                    str = line.back() + str;
                    line.pop_back();
                }
            }
        }

        if (line.back() == ' ') {
            line.pop_back();
        }

        if (!str.empty()) {
            if (str.at(0) == ' ') {
                str.erase(str.begin());
            }
        }

        result.push_back(line);
    }

    return result;
}

void showInputOptions(vector<string> options, string defaultValue)
{
    if (options.empty()) {
        return;
    }

    string result = "{ ";
    showYellow("{");

    for (int i = 0; i < options.size(); i++)
    {
        showYellow(options[i], options[i] == defaultValue);

        if (i < options.size() - 1) {
            cout << "|";
        }
    }

    showYellow("}");
}

string getOptionInput(string title, bool isRequired, string defaultValue, vector<string> options)
{
    startInput:
    showBlue(title, true);

    if (!options.empty()) {
        cout << " ";
        showInputOptions(options, defaultValue);
    }

    cout << " : ";

    string result;

    getline(cin, result);

    if (isRequired && result.empty()) {
        showRed("This option is required.", true);
        cout << endl;
        goto startInput;
    }

    if (result.empty()) {
        return defaultValue;
    }

    if (!options.empty()
        && find(options.begin(), options.end(), result) == options.end()
        ) {
        showRed("Invalid value.");
        cout << endl;
        goto startInput;
    }

    return result;
}

#endif //LEMP_BUILDARGS_H
