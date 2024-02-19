//
// Created by dangnd on 0008, December 8, 2023.
//

#ifndef LEMP_HELP_H
#define LEMP_HELP_H

#include <utility>

#include "iostream"
#include "vector"
#include "iomanip"

#include "CommandOption.h"
#include "message.h"
#include "Common.h"

using namespace std;

class Help
{
    private:
        const int DESC_MAX_LENGTH = 60;

        vector<CommandOption*> options;
        string             code;
        string             describe;

        int getKeyMaxLength();

        int getDescribeMaxLength();

        static string generateOptionValues(CommandOption* option);
        Help(string code, string describe);
    public:
        const string OPTION_HELP = "--help";
        const string OPTION_HELP_SHORT = "-h";

        void setOptions(vector<CommandOption*> value);
        void addOption(CommandOption* value);
        void addOption(vector<CommandOption*> value);
        vector<CommandOption*> getOptions();
        void print();
        static Help getInstance(string code, string describe);
};

Help::Help(string code, string describe)
{
    this->code = std::move(code);
    this->describe = std::move(describe);
}

Help Help::getInstance(string code, string describe)
{
    return *new Help(code, describe);
}

void Help::setOptions(vector<CommandOption*> value)
{
    this->options = std::move(value);
}

void Help::addOption(CommandOption* value)
{
    this->options.push_back(value);
}

void Help::addOption(vector<CommandOption*> value)
{
    this->options.insert(this->options.end(), value.begin(), value.end());
}

vector<CommandOption*> Help::getOptions()
{
    return this->options;
}

void Help::print()
{
    int maxKey  = this->getKeyMaxLength();
    int maxDesc = this->getDescribeMaxLength();
    vector<string> descriptionSplit;

    showBlue("Usage", true);
    showBlue(": " + this->describe);

    if (this->options.empty()) {
        cout << endl << "\t" + this->code;
        return;
    }

    string usage = this->code;
    bool hasOptionalOption = false;

    for (CommandOption* option: this->options) {
        if (!option->isRequired()) {
            hasOptionalOption = true;
            continue;
        }

        usage += " " + option->getName() + "=[value]";
    }

    if (hasOptionalOption) {
        usage += " [<option>]";
    }

    cout << endl << "\t" + usage;

    this->addOption((new CommandOption({"--help", "-h"}))->setDescription("Display this help message"));

    cout << endl;
    showBold("Options");
    cout << ":" << endl;

    for (CommandOption* option: this->options) {
        descriptionSplit = splitSentence(option->getDescription(), maxDesc);

        cout << "\t" << generateColorCode(Color::BOLD) << generateColorCode(Color::BLUE)
            << setw(maxKey) << left << setfill(' ') << option->getStringNames()
            << generateColorCode(Color::RESET);

        cout << "\t" << setw(maxDesc) << left << setfill(' ') << descriptionSplit.front();
        descriptionSplit.erase(descriptionSplit.begin());

        if (!option->getValueOptions().empty()) {
            showBold(" [" + Help::generateOptionValues(option) + "]");
        }

        if (!option->getExampleValue().empty()) {
            showBold(" [Ex: " + option->getExampleValue() + ']');
        }

        if (!option->getDefaultValue().empty()) {
            showBold(" [Default: " + option->getDefaultValue() + ']');
        }

        if (option->isNonValue()) {
            showBold(" [Non-Value]");
        }

        if (option->isRequired()) {
            showYellow(" [required]", true);
        }

        if (option->isMultiple()) {
            showYellow(" [multiple]", true);
        }

        for (const string& descriptionPart: descriptionSplit) {
            cout << "\t" << string(maxKey, ' ') << "\t" << descriptionPart << endl;
        }

        cout << endl;
    }
}

int Help::getKeyMaxLength()
{
    int result = 0;

    for (CommandOption* option: this->options) {
        if (option->getStringNames().length() > result) {
            result = (int)option->getStringNames().length();
        }
    }

    return result;
}

int Help::getDescribeMaxLength()
{
    int result = 0;

    for (CommandOption* option: this->options) {
        if (option->getDescription().length() > result) {
            result = (int)option->getDescription().length();
        }
    }

    return min(result, DESC_MAX_LENGTH);
}

string Help::generateOptionValues(CommandOption* option)
{
    string result;

    for (const string& value: option->getValueOptions()) {
        result += value + '|';
    }

    if (option->getValueOptions().size() > 1) {
        return result.substr(0, result.length() - 1);
    }

    return result;
}

#endif //LEMP_HELP_H
