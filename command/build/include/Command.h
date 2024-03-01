//
// Created by dangnd on 0008, December 8, 2023.
//

#ifndef LEMP_COMMAND_H
#define LEMP_COMMAND_H

#include <utility>

#include "iostream"
#include "vector"
#include "iomanip"
#include "map"

#include "CommandOption.h"
#include "message.h"
#include "Common.h"

using namespace std;

class Command
{
    public:
        const string OPTION_HELP = "--help";
        const string OPTION_HELP_SHORT = "-h";

        Command() {};

        void setOptions(vector<CommandOption*> value);
        void addOption(CommandOption* value);
        void addOption(vector<CommandOption*> value);
        void showHelp();
        void mapValues(int argc, char *argv[]);
        void showError(const string& message);
        void showError(const string& message, bool isExit);

        vector<CommandOption*> getOptions();

        virtual void init();
        virtual void init(vector<string> arguments);
        virtual void init(int argc, char **argv);
        virtual void exec() {}
    protected:
        const int DESC_MAX_LENGTH = 60;

        vector<CommandOption *> options;
        string                  code;
        string                  describe;
        map<string, string>     optionDefaultValues;
        map<string, string>     values;

        virtual void initArguments(vector<string> arguments);
        virtual void setOptionValue(const string &key, string value);
        virtual void setOptionValue(const string &key, string value, bool isExit);
        virtual void setOptionValuesByDefault();
        virtual void setOptionValuesByDefault(bool isExit);
        virtual void validateRequired();
        virtual void initCommand() {}
        virtual void initOptions() {}

        int getKeyMaxLength();
        int getDescribeMaxLength();
        CommandOption *getOption(const string &key);
        string getValue(const string &key);
        string generateOptionValues(CommandOption *option);
        string inputOption(CommandOption *option);
};

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

void Command::showHelp()
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
            showBold(" [" + this->generateOptionValues(option) + "]");
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
            this->showHelp();
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
    this->showError(message, true);
}

void Command::showError(const string& message, bool isExit)
{
    showRed("Error: " + message, true);
    cout << endl;

    if (isExit) {
        this->showHelp();
        exit(0);
    }
}

void Command::validateRequired()
{
    for (CommandOption *option: this->getOptions()) {
        if (!option->isRequired()) {
            continue;
        }

        if (this->values.find(option->getName()) == end(this->values)) {
            this->showError("Option `" + option->getName() + "` is required.");
        }
    }
}

void Command::setOptionValue(const string &key, string value)
{
    this->setOptionValue(key, value, true);
}

void Command::setOptionValue(const string &key, string value, bool isExit)
{
    if (key == OPTION_HELP || key == OPTION_HELP_SHORT) {
        this->showHelp();
    }

    for (CommandOption *option: this->getOptions()) {
        if (!option->checkKey(key)) {
            continue;
        }

        vector<string> validValues = option->getValueOptions();

        if (value.empty()) {
            return;
        }

        if (!validValues.empty() && find(validValues.begin(), validValues.end(), value) == validValues.end()) {
            this->showError("Option `" + key + "` invalid value.", isExit);
        }

        this->values[option->getValueKey()] = value;
        return;
    }

    this->showError("Option `" + key + "` doesn't exists.", isExit);
}

void Command::setOptionValuesByDefault()
{
    this->setOptionValuesByDefault(true);
}

void Command::setOptionValuesByDefault(bool isExit)
{
    for (CommandOption *option: this->getOptions()) {
        if (!option->getDefaultValue().empty() && this->getValue(option->getValueKey()).empty()) {
            this->values[option->getValueKey()] = option->getDefaultValue();
        }
    }
}

CommandOption *Command::getOption(const string &key)
{
    for (CommandOption *option: this->getOptions()) {
        if (option->getName() == key) {
            return option;
        }
    }

    return NULL;
}

string Command::getValue(const string &key)
{
    if (this->values.find(key) != end(this->values)) {
        return this->values.find(key)->second;
    }

    return "";
}

void Command::initArguments(vector<std::string> arguments)
{
    for (string arg: arguments) {
        string key, value;
        string::size_type splitPos = arg.find('=');

        if (splitPos == string::npos) {
            key = arg;
        } else {
            key = arg.substr(0, splitPos);
            value = arg.substr(splitPos + 1);
        }

        this->setOptionValue(key, value);
    }
}

void Command::init()
{
    this->initCommand();
    this->initOptions();
}

void Command::init(vector<std::string> arguments)
{
    this->init();
    this->initArguments(arguments);
}

void Command::init(int argc, char **argv)
{
    this->init();
    this->mapValues(argc, argv);
}

string Command::inputOption(CommandOption *option)
{
    startInput:
    showBlue(option->getInputLabel().empty() ? option->getDescription() : option->getInputLabel(), true);

    if (!option->getValueOptions().empty()) {
        cout << " ";
        showInputOptions(option->getValueOptions(), option->getDefaultValue());
    }

    cout << " : ";

    string result;

    getline(cin, result);

    if (option->isRequired() && result.empty()) {
        showRed("This option is required.", true);
        cout << endl;
        goto startInput;
    }

    if (result.empty()) {
        return option->getDefaultValue();
    }

    if (!option->getValueOptions().empty()
        && find(
            option->getValueOptions().begin(), option->getValueOptions().end(), result
        ) == option->getValueOptions().end()
    ) {
        showRed("Invalid value.");
        cout << endl;
        goto startInput;
    }

    return result;
}

#endif //LEMP_COMMAND_H
