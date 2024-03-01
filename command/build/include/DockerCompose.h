//
// Created by dangnd on 0005, December 5, 2023.
//

#ifndef LEMP_INIT_DOCO_H
#define LEMP_INIT_DOCO_H

#include "Help.h"
#include "CommandOption.h"
#include "message.h"
#include "NginxVhost.h"
#include "Common.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

const string         PROJECT_TYPE_PHP     = "php";
const string         PROJECT_TYPE_MAGENTO = "magento";
const string         PROJECT_TYPE_STATIC  = "static";
const string         PROJECT_TYPE_FORWARD = "forward";

const string         YES_NO_YES    = "y";
const string         YES_NO_NO     = "n";

const vector<string> PROJECT_TYPE_OPTIONS = {
    PROJECT_TYPE_PHP,
    PROJECT_TYPE_MAGENTO,
    PROJECT_TYPE_STATIC,
    PROJECT_TYPE_FORWARD
};
const vector<string> YES_NO_OPTION = {YES_NO_YES, YES_NO_NO};

class DockerCompose
{
    public:
        const string CODE = "init-doco";

        const string OPTION_INPUT         = "--input";
        const string OPTION_TYPE          = "--type";
        const string OPTION_PATH          = "--path";
        const string OPTION_VARNISH       = "--varnish";
        const string OPTION_SERVER_NAME   = "--server-name";
        const string OPTION_VARNISH_PORT  = "--varnish-port";
        const string OPTION_PROXY         = "--proxy";
        const string OPTION_PROXY_PORT    = "--proxy-port";
        const string OPTION_HTTPS         = "--https";
        const string OPTION_SSH           = "--ssh-tunnel";
        const string OPTION_PHP           = "--php";
        const string OPTION_MAIL          = "--mail";
        const string OPTION_DB            = "--database";
        const string OPTION_DB_NAME       = "--database-name";
        const string OPTION_DB_USER       = "--database-user";
        const string OPTION_DB_PASS       = "--database-password";
        const string OPTION_ELASTICSEARCH = "--elasticsearch";
        const string OPTION_RABBITMQ      = "--rabbitmq";
        const string OPTION_REDIS         = "--redis";

        const string ENV_TYPE          = "PROJECT_TYPE";
        const string ENV_PATH          = "PATH";
        const string ENV_SERVER_NAME   = "SERVER_NAME";
        const string ENV_VARNISH       = "VARNISH_IMAGE";
        const string ENV_VARNISH_PORT  = "VARNISH_PORT";
        const string ENV_PROXY         = "PROXY";
        const string ENV_PROXY_PORT    = "PROXY_PORT";
        const string ENV_HTTPS         = "HTTPS";
        const string ENV_SSH           = "SSH_TUNNEL";
        const string ENV_PHP           = "PHP_IMAGE";
        const string ENV_MAIL          = "EMAIL_IMAGE";
        const string ENV_DB            = "DB_IMAGE";
        const string ENV_DB_NAME       = "DB_NAME";
        const string ENV_DB_USER       = "DB_USER";
        const string ENV_DB_PASS       = "DB_PASS";
        const string ENV_ELASTICSEARCH = "ELASTICSEARCH_IMAGE";
        const string ENV_RABBITMQ      = "RABBITMQ_IMAGE";
        const string ENV_REDIS         = "REDIS_IMAGE";

        DockerCompose();

        DockerCompose(vector<string> argv);

        void showHelp();

        void showError(const string &message);

        map<string, CommandOption *> getHelpOptions();

        CommandOption *getHelpOption(string key);

        string getDefaultValue(const string &key);

        void validateOption(const string &key, string value);

        void create();

        void input();

        string inputOption(string key);

        bool hasInput();

        void printValue()
        {
            for (const auto &elem: this->values) {
                cout << elem.first << " : " << elem.second << endl;
            }
        }

    private:
        Help                         help = Help::getInstance(CODE, "Generate `Docker Compose` file.");
        map<string, CommandOption *> helpOptions;
        map<string, string>          optionDefaultValues;
        map<string, string>          values;
        vector<NginxVhost *>         vhosts;

        void init();

        void initOptionDefaultValues();

        void initArguments(vector<string> arguments);

        void validateRequired();

        NginxVhost *inputVhost();
};

DockerCompose::DockerCompose()
{
    this->init();
}

DockerCompose::DockerCompose(vector<string> arguments)
{
    this->init();
    this->initArguments(arguments);
}

bool DockerCompose::hasInput()
{
    return this->values.find(OPTION_INPUT) != end(this->values);
}

void DockerCompose::init()
{
    this->initOptionDefaultValues();

    for (auto const &item: this->getHelpOptions()) {
        this->help.addOption(item.second);
    }
}

void DockerCompose::showHelp()
{
    this->help.print();

    exit(0);
}

void DockerCompose::showError(const string &message)
{
    showRed("Error: " + message, true);
    cout << endl;
    this->showHelp();
}

string DockerCompose::getDefaultValue(const string &key)
{
    if (this->optionDefaultValues.find(key) != end(this->optionDefaultValues)) {
        return this->optionDefaultValues.find(key)->second;
    }

    return "";
}

map<string, CommandOption *> DockerCompose::getHelpOptions()
{
    if (this->helpOptions.empty()) {
        this->helpOptions[OPTION_INPUT] = (new CommandOption({OPTION_INPUT, "-i"}))
                ->setDescription("Enter input step by step.")
                ->setNonValue(true)
                ->setDefaultValue("true");

        this->helpOptions[ENV_TYPE] = (new CommandOption({OPTION_TYPE, "-t"}))
                ->setValueKey(ENV_TYPE)
                ->setDescription("Project Type.")
                ->setInputLabel("Project Type")
                ->setRequired(true)
                ->setValueOptions(PROJECT_TYPE_OPTIONS);

        this->helpOptions[ENV_PATH] = (new CommandOption({OPTION_PATH, "-p"}))
                ->setValueKey(ENV_PATH)
                ->setDescription("Root Project Path.")
                ->setInputLabel("Root Project Path")
                ->setDefaultValue("CURRENT FOLDER");

        this->helpOptions[ENV_SERVER_NAME] = (new CommandOption({OPTION_SERVER_NAME}))
                ->setValueKey(ENV_SERVER_NAME)
                ->setDescription("vHost Server Name.")
                ->setInputLabel("vHost Server Name")
                ->setDefaultValue(this->getDefaultValue(ENV_SERVER_NAME));

        this->helpOptions[ENV_HTTPS] = (new CommandOption({OPTION_HTTPS}))
                ->setValueKey(ENV_HTTPS)
                ->setDescription("Use HTTPS.")
                ->setInputLabel("Use HTTPS")
                ->setValueOptions(YES_NO_OPTION)
                ->setDefaultValue(YES_NO_NO)
                ->setNonValue(true);

        this->helpOptions[ENV_SSH] = (new CommandOption({OPTION_SSH}))
                ->setValueKey(ENV_SSH)
                ->setDescription("Use SSH Tunnel.")
                ->setInputLabel("Use SSH Tunnel: ")
                ->setValueOptions(YES_NO_OPTION)
                ->setDefaultValue(YES_NO_NO)
                ->setNonValue(true);

        this->helpOptions[ENV_PROXY] = (new CommandOption({OPTION_PROXY}))
                ->setValueKey(ENV_PROXY)
                ->setDescription("Direct Proxy. Use for `forward` project.")
                ->setInputLabel("Direct Proxy")
                ->setDefaultValue(this->getDefaultValue(ENV_PROXY));

        this->helpOptions[ENV_PROXY_PORT] = (new CommandOption({OPTION_PROXY_PORT}))
                ->setValueKey(ENV_PROXY_PORT)
                ->setDescription("Proxy Port. Use for `forward` project")
                ->setInputLabel("Proxy Port")
                ->setDefaultValue(this->getDefaultValue(ENV_PROXY_PORT));

        this->helpOptions[ENV_VARNISH] = (new CommandOption({OPTION_VARNISH}))
                ->setValueKey(ENV_VARNISH)
                ->setDescription("Varnish Image.")
                ->setInputLabel("Varnish Image (Empty if not use): ")
                ->setExampleValue(this->getDefaultValue(ENV_VARNISH));

        this->helpOptions[ENV_VARNISH_PORT] = (new CommandOption({OPTION_VARNISH_PORT}))
                ->setValueKey(ENV_VARNISH_PORT)
                ->setDescription("Varnish Port.")
                ->setInputLabel("Varnish Port")
                ->setDefaultValue(this->getDefaultValue(ENV_VARNISH_PORT));

        this->helpOptions[ENV_PHP] = (new CommandOption({OPTION_PHP}))
                ->setValueKey(ENV_PHP)
                ->setDescription("PHP Image.")
                ->setInputLabel("PHP Image (Empty if not use)")
                ->setExampleValue(this->getDefaultValue(ENV_PHP));

        this->helpOptions[ENV_MAIL] = (new CommandOption({OPTION_MAIL}))
                ->setValueKey(ENV_MAIL)
                ->setDescription("Mail Service Image.")
                ->setInputLabel("Mail Service Image (Empty if not use)")
                ->setExampleValue(this->getDefaultValue(ENV_MAIL));

        this->helpOptions[ENV_DB] = (new CommandOption({OPTION_DB, "-db"}))
                ->setValueKey(ENV_DB)
                ->setDescription("Database Image.")
                ->setInputLabel("Database Image (Empty if not use)")
                ->setExampleValue(this->getDefaultValue(ENV_DB));

        this->helpOptions[ENV_DB_NAME] = (new CommandOption({OPTION_DB_NAME, "-dbn"}))
                ->setValueKey(ENV_DB_NAME)
                ->setDescription("Database Name.")
                ->setInputLabel("Database Name")
                ->setDefaultValue(this->getDefaultValue(ENV_DB_NAME));

        this->helpOptions[ENV_DB_USER] = (new CommandOption({OPTION_DB_USER, "-dbu"}))
                ->setValueKey(ENV_DB_USER)
                ->setDescription("Database User.")
                ->setInputLabel("Database User")
                ->setDefaultValue(this->getDefaultValue(ENV_DB_USER));

        this->helpOptions[ENV_DB_PASS] = (new CommandOption({OPTION_DB_PASS, "-dbp"}))
                ->setValueKey(ENV_DB_PASS)
                ->setDescription("Database User Password.")
                ->setInputLabel("Database User Password")
                ->setDefaultValue(this->getDefaultValue(ENV_DB_PASS));

        this->helpOptions[ENV_ELASTICSEARCH] = (new CommandOption({OPTION_ELASTICSEARCH, "-es"}))
                ->setValueKey(ENV_ELASTICSEARCH)
                ->setDescription("Elasticsearch Image.")
                ->setInputLabel("Elasticsearch Image")
                ->setExampleValue(this->getDefaultValue(ENV_ELASTICSEARCH));

        this->helpOptions[ENV_REDIS] = (new CommandOption({OPTION_REDIS}))
                ->setValueKey(ENV_REDIS)
                ->setDescription("Redis Image.")
                ->setInputLabel("Redis Image (Empty if not use)")
                ->setExampleValue(this->getDefaultValue(ENV_REDIS));

        this->helpOptions[ENV_RABBITMQ] = (new CommandOption({OPTION_RABBITMQ, "-rb"}))
                ->setValueKey(ENV_RABBITMQ)
                ->setDescription("RabbitMQ Image.")
                ->setInputLabel("RabbitMQ Image (Empty if not use)")
                ->setExampleValue(this->getDefaultValue(ENV_RABBITMQ));
    }

    return this->helpOptions;
}

CommandOption *DockerCompose::getHelpOption(string key)
{
    if (this->helpOptions.find(key) != end(this->helpOptions)) {
        return this->helpOptions.find(key)->second;
    }

    return NULL;
}

void DockerCompose::initOptionDefaultValues()
{
    this->optionDefaultValues[ENV_PHP]           = "voothanhdev/fpm:8.1";
    this->optionDefaultValues[ENV_HTTPS]         = "true";
    this->optionDefaultValues[ENV_SERVER_NAME]   = "local.io";
    this->optionDefaultValues[ENV_VARNISH]       = "voothanhdev/varnish";
    this->optionDefaultValues[ENV_VARNISH_PORT]  = "6081";
    this->optionDefaultValues[ENV_MAIL]          = "voothanhdev/mailhog";
    this->optionDefaultValues[ENV_DB]            = "mysql:8.0";
    this->optionDefaultValues[ENV_DB_NAME]       = "local";
    this->optionDefaultValues[ENV_DB_USER]       = "local";
    this->optionDefaultValues[ENV_DB_PASS]       = "local";
    this->optionDefaultValues[ENV_ELASTICSEARCH] = "elasticsearch:7.17.10";
    this->optionDefaultValues[ENV_RABBITMQ]      = "rabbitmq:3.8.4-management-alpine";
    this->optionDefaultValues[ENV_REDIS]         = "redis:7.0.4-alpine3.16";
}

void DockerCompose::validateOption(const string &key, string value)
{
    if (key == this->help.OPTION_HELP || key == this->help.OPTION_HELP_SHORT) {
        this->showHelp();
    }

    for (auto const &item: this->getHelpOptions()) {
        CommandOption *option = item.second;

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

        this->values[option->getValueKey().empty() ? option->getName() : option->getValueKey()] = value;
        return;
    }

    this->showError("Option `" + key + "` doesn't exists.");
}

void DockerCompose::initArguments(vector<string> arguments)
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

        this->validateOption(key, value);
    }
}

void DockerCompose::validateRequired()
{
    for (auto const &item: this->getHelpOptions()) {
        CommandOption *option = item.second;

        if (!option->isRequired()) {
            continue;
        }

        if (this->values.find(option->getName()) == end(this->values)) {
            this->showError("Option `" + option->getName() + "` is required.");
        }
    }
}

void DockerCompose::input()
{
    this->inputOption(ENV_PATH);

    vhostStep:
    this->vhosts.push_back(this->inputVhost());

    if (YES_NO_YES == getOptionInput("Add more nginx vhost", false, YES_NO_NO, YES_NO_OPTION)) {
        goto vhostStep;
    }

    this->inputOption(ENV_SSH);
    this->inputOption(ENV_PHP);
    this->inputOption(ENV_MAIL);

    this->inputOption(ENV_DB);
    if (!this->values[ENV_DB].empty()) {
        this->inputOption(ENV_DB_NAME);
        this->inputOption(ENV_DB_USER);
        this->inputOption(ENV_DB_PASS);
    }

    this->inputOption(ENV_ELASTICSEARCH);
    this->inputOption(ENV_REDIS);
    this->inputOption(ENV_RABBITMQ);
}

string DockerCompose::inputOption(string key)
{
    string result;
    CommandOption *option = this->getHelpOption(key);

    if (option != NULL) {
        this->values[key] = getOptionInput(
            option->getInputLabel(),
            option->isRequired(),
            option->getDefaultValue(),
            option->getValueOptions()
        );

        result = this->values[key];
    }

    return result;
}

NginxVhost *DockerCompose::inputVhost()
{
    NginxVhost *vhost = new NginxVhost();

    vhost->setProjectType(this->inputOption(ENV_TYPE));
    vhost->setFolder(this->inputOption(ENV_PATH));
    vhost->setServerName(this->inputOption(ENV_SERVER_NAME));
    vhost->setHttps(this->inputOption(ENV_HTTPS) == YES_NO_YES);

    if (vhost->getProjectType() == PROJECT_TYPE_FORWARD) {
        vhost->setProxy(this->inputOption(ENV_PROXY));
        vhost->setProxyPort(this->inputOption(ENV_PROXY_PORT));
    } else {
        vhost->setVarnish(this->inputOption(ENV_VARNISH));

        if (!vhost->getVarnish().empty()) {
            vhost->setVarnishPort(this->inputOption(ENV_VARNISH_PORT));
        }
    }

    return vhost;
}

void DockerCompose::create()
{
    if (this->hasInput()) {
        this->input();
    } else {
        this->validateRequired();
    }

    ofstream fOut;

    fOut.open(this->values[ENV_PATH] + "/docker-compose.yml");
}

#endif //LEMP_INIT_DOCO_H
