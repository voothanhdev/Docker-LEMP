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

        CommandOption* setDescription(string newData)
        {
            this->description = newData;

            return this;
        }

        CommandOption* setDefaultValue(string newData)
        {
            this->defaultValue = newData;

            return this;
        }

        CommandOption* setExampleValue(string newData)
        {
            this->exampleValue = newData;

            return this;
        }

        CommandOption* setValueKey(string newData)
        {
            this->valueKey = newData;

            return this;
        }

        CommandOption* setInputLabel(string newData)
        {
            this->inputLabel = newData;

            return this;
        }

        CommandOption* setValueOptions(vector<string> newData)
        {
            this->valueOptions = newData;

            return this;
        }

        CommandOption* setRequired(bool newData)
        {
            this->required = newData;

            return this;
        }

        CommandOption* setMultiple(bool newData)
        {
            this->multiple = newData;

            return this;
        }

        CommandOption* setNonValue(bool newData)
        {
            this->nonValue = newData;

            return this;
        }

        CommandOption* setValue(string* newData)
        {
            this->value = newData;

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

        string getValueKey()
        {
            return this->valueKey.empty() ? this->getName() : this->valueKey;
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
        string valueKey;
        string inputLabel;
        string* value;
        vector<string> valueOptions;
        bool required;
        bool multiple;
        bool nonValue;
};

#endif //LEMP_OPTION_H
