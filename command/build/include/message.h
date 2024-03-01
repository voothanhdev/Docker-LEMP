//
// Created by dangnd on 0005, December 5, 2023.
//

#ifndef LEMP_MESSAGE_H
#define LEMP_MESSAGE_H

#include <string>
#include <iostream>

using namespace std;

const string MSG_RED="\033[31m";
const string MSG_GREEN="\033[32m";
const string MSG_YELLOW="\033[33m";
const string MSG_BLUE="\033[34m";
const string MSG_BOLD="\033[1m";
const string MSG_RESET="\033[0m";

enum Color {
    RED=31,
    GREEN=32,
    YELLOW=33,
    BLUE=34,
    BOLD=1,
    RESET=0
};

string generateColorCode(Color color)
{
    return "\033[" + to_string(color) + 'm';
}

void showBold(const string& message)
{
    cout << generateColorCode(Color::BOLD) << message << generateColorCode(Color::RESET);
}

void showColorMessage(const string& message, Color color, bool isBold)
{
    cout << (isBold ? generateColorCode(Color::BOLD) : "")
        << generateColorCode(color)
        << message
        << generateColorCode(Color::RESET);
}

void showRed(const string& message, bool isBold)
{
    showColorMessage(message, Color::RED, isBold);
}

void showRed(const string& message)
{
    showRed(message, false);
}

void showYellow(const string& message, bool isBold)
{
    showColorMessage(message, Color::YELLOW, isBold);
}

void showYellow(const string& message)
{
    showYellow(message, false);
}

void showBlue(const string& message, bool isBold)
{
    showColorMessage(message, Color::BLUE, isBold);
}

void showBlue(const string& message)
{
    showBlue(message, false);
}

void showGreen(const string& message, bool isBold)
{
    showColorMessage(message, Color::GREEN, isBold);
}

void showGreen(const string& message)
{
    showGreen(message, false);
}

#endif //LEMP_MESSAGE_H
