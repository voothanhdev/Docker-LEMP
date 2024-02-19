//
// Created by dangnd on 0005, December 5, 2023.
//

#ifndef LEMP_OPTION_H
#define LEMP_OPTION_H

#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "Common.h"

using namespace std;

class CommandOption
{
    public:
        CommandOption(vector<string> names)
        {
           this->names = names;
        }

        CommandOption* setDescription(string value)
        {
            this->description = value;

            return this;
        }

        CommandOption* setDefaultValue(string value)
        {
            this->defaultValue = value;

            return this;
        }

        CommandOption* setExampleValue(string value)
        {
            this->exampleValue = value;

            return this;
        }

        CommandOption* setEnvKey(string value)
        {
            this->envKey = value;

            return this;
        }

        CommandOption* setInputLabel(string value)
        {
            this->inputLabel = value;

            return this;
        }

        CommandOption* setValueOptions(vector<string> value)
        {
            this->valueOptions = value;

            return this;
        }

        CommandOption* setRequired(bool value)
        {
            this->required = value;

            return this;
        }

        CommandOption* setMultiple(bool value)
        {
            this->multiple = value;

            return this;
        }

        CommandOption* setNonValue(bool value)
        {
            this->nonValue = value;

            return this;
        }

        CommandOption* setValue(string* value)
        {
            this->value = value;

            return this;
        }

        CommandOption* setValue(string value)
        {
            *this->value = value;

            return this;
        }

        vector<string> getNames()
        {
            return this->names;
        }

        string getDescription()
        {
            return this->description;
        }

        string getDefaultValue()
        {
            return this->defaultValue;
        }

        string getExampleValue()
        {
            return this->exampleValue;
        }

        string getEnvKey()
        {
            return this->envKey;
        }

        string getInputLabel()
        {
            return this->inputLabel;
        }

        vector<string> getValueOptions()
        {
            return this->valueOptions;
        }

        bool isRequired()
        {
            return this->required;
        }

        bool isMultiple()
        {
            return this->multiple;
        }

        bool isNonValue()
        {
            return this->nonValue;
        }

        string getName()
        {
            return this->names.front();
        }

        string getValue()
        {
            return *this->value;
        }

        string getStringNames()
        {
            vector<string> keys = this->getNames();
            string result = keys.front();

            keys.erase(keys.begin());

            for (string name: keys)
            {
                result.append(", ").append(name);
            }

            return result;
        }

        string getStringValueOptions()
        {
            if (this->valueOptions.empty()) {
                return "";
            }

            string result = "{ ";

            for (string name: this->valueOptions)
            {
                result.append(name + " | ");
            }

            result = result.substr(0, result.length() - 2);

            result.append(" }");

            return result;
        }

        bool checkKey(string key)
        {
            for (string name: this->getNames()) {
                if (name == key) {
                    return true;
                }
            }

            return false;
        }
    private:
        vector<string> names;
        string description;
        string defaultValue;
        string exampleValue;
        string envKey;
        string inputLabel;
        string* value;
        vector<string> valueOptions;
        bool required;
        bool multiple;
        bool nonValue;
};

#endif //LEMP_OPTION_H
