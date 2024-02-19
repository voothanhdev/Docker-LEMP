//
// Created by dangnd on 0008, December 8, 2023.
//

#ifndef LEMP_COMMAND_H
#define LEMP_COMMAND_H

#include <utility>

#include "iostream"
#include "vector"
#include "iomanip"

#include "CommandOption.h"
#include "message.h"
#include "Common.h"

using namespace std;

class Command
{
    private:
        const int DESC_MAX_LENGTH = 60;

        vector<CommandOption *> options;
        string                  code;
        string                  describe;

        int getKeyMaxLength();

        int getDescribeMaxLength();

        static string generateOptionValues(CommandOption* option);
        Command(string code, string describe);
    public:
        const string OPTION_HELP = "--help";
        const string OPTION_HELP_SHORT = "-h";

        void setOptions(vector<CommandOption*> value);
        void addOption(CommandOption* value);
        void addOption(vector<CommandOption*> value);
        vector<CommandOption*> getOptions();
        void print();
        void mapValues(int argc, char *argv[]);
        void showError(const string& message);
        static Command getInstance(string code, string describe);
};

Command::Command(string code, string describe)
{
    this->code = std::move(code);
    this->describe = std::move(describe);
}

Command Command::getInstance(string code, string describe)
{
    return *new Command(code, describe);
}

void Command::setOptions(vector<CommandOption*> value)
{
    this->options = std::move(value);
}

void Command::addOption(CommandOption* value)
{
    this->options.push_back(value);
}

void Command::addOption(vector<CommandOption*> value)
{
    this->options.insert(this->options.end(), value.begin(), value.end());
}

vector<CommandOption*> Command::getOptions()
{
    return this->options;
}

void Command::print()
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
            showBold(" [" + Command::generateOptionValues(option) + "]");
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

int Command::getKeyMaxLength()
{
    int result = 0;

    for (CommandOption* option: this->options) {
        if (option->getStringNames().length() > result) {
            result = (int)option->getStringNames().length();
        }
    }

    return result;
}

int Command::getDescribeMaxLength()
{
    int result = 0;

    for (CommandOption* option: this->options) {
        if (option->getDescription().length() > result) {
            result = (int)option->getDescription().length();
        }
    }

    return min(result, DESC_MAX_LENGTH);
}

string Command::generateOptionValues(CommandOption* option)
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

void Command::mapValues(int argc, char **argv)
{
    vector<string> result;

    for (int i = 1; i < argc; i++)
    {
        string            arg      = argv[i];
        string::size_type splitPos = arg.find('=');

        string key, value;

        if (splitPos == string::npos) {
            key = arg;
        } else {
            key = arg.substr(0, splitPos);
            value = arg.substr(splitPos + 1);
        }

        if (key == OPTION_HELP || key == OPTION_HELP_SHORT) {
            this->print();
            exit(0);
        }

        for (CommandOption* option: this->options) {
            if (!option->checkKey(key)) {
                continue;
            }

            vector<string> validValues = option->getValueOptions();

            if (value.empty()) {
                value = option->getDefaultValue();
            }

            if (!validValues.empty() && find(validValues.begin(), validValues.end(), value) == validValues.end()) {
                this->showError("Option `" + key + "` invalid value.");
            }

            option->setValue(value);
        }
    }

    for (CommandOption* option: this->options) {
        if (option->isRequired() && option->getValue().empty()) {
            showError("Option `" + option->getName() + "` is required.");
        }
    }
}

void Command::showError(const string& message)
{
    showRed("Error: " + message, true);
    cout << endl;
    this->print();
    exit(0);
}

#endif //LEMP_COMMAND_H
