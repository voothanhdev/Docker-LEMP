//
// Created by dangnd on 0019, February 19, 2024.
//

#ifndef LEMP_MYSQLIMPORT_H
#define LEMP_MYSQLIMPORT_H

#include "Command.h"
#include "Common.h"
#include "systemCommand.h"
#include <filesystem>
#include <iostream>

using namespace std;

class MysqlImportCommand: public Command {
    public:
        const string CODE = "mysql-import";

        const string OPTION_FILE = "--file";
        const string OPTION_USER = "--user";
        const string OPTION_PASS = "--password";
        const string OPTION_DB = "--database";
        const string OPTION_DOCKER_COMPOSE_SERVICE = "--docker-compose-service";

        MysqlImportCommand(): Command() {}

        void exec()
        {
            cout << "file: " << this->file << endl;
            cout << "user: " << this->user << endl;
            cout << "pass: " << this->pass << endl;
            cout << "db: " << this->db << endl;
            cout << "service: " << this->service << endl;
        }
    protected:
        string file;
        string user;
        string pass;
        string db;
        string service;

        void initCommand()
        {
            this->code = CODE;
            this->describe = "Import Mysql Database via Docker compose.";
        }

        void initOptions()
        {
            string defaultService = "db";

            if (!isDockerComposeService(defaultService)) {
                defaultService = "";
            }

            this->options = {
                (new CommandOption({OPTION_FILE, "-f"}))
                    ->setDescription("SQL File Path.")
                    ->setRequired(true)
                    ->setValue(&file),
                (new CommandOption({OPTION_USER, "-u"}))
                    ->setDescription("Mysql User.")
                    ->setDefaultValue("root")
                    ->setValue(&user),
                (new CommandOption({OPTION_PASS, "-p"}))
                    ->setDescription("Mysql Password for User")
                    ->setDefaultValue(defaultService.empty() ? "" : "<Default password for root in compose file>")
                    ->setRequired(defaultService.empty())
                    ->setValue(&pass),
                (new CommandOption({OPTION_DB, "-d"}))
                    ->setDescription("Database name")
                    ->setDefaultValue(defaultService.empty() ? "" : "<Default database in compose file>")
                    ->setRequired(defaultService.empty())
                    ->setValue(&db),
                (new CommandOption({OPTION_DOCKER_COMPOSE_SERVICE, "-s"}))
                    ->setDescription("Docker Compose Database Service Name")
                    ->setDefaultValue(defaultService)
                    ->setRequired(defaultService.empty())
                    ->setValue(&service),
            };
        }

        void setOptionValue(const string &key, string value, bool isExit)
        {
            Command::setOptionValue(key, value, isExit);

            if (key == OPTION_FILE) {
                this->validateFile(isExit);
            }
        }

        void validateFile(bool isExit)
        {
            if (!fileExists(this->file)) {
                this->showError("`" + this->file + "` is not file.", isExit);
            }
        }

        void setOptionValuesByDefault(bool isExit)
        {
            for (CommandOption *option: this->getOptions()) {
                if (option->getName() == OPTION_PASS) {
                    continue;
                }

                if (!option->getDefaultValue().empty() && this->getValue(option->getValueKey()).empty()) {
                    this->values[option->getValueKey()] = option->getDefaultValue();
                }
            }

            if (this->getValue(OPTION_PASS).empty() && this->getValue(OPTION_USER) == "root")
            {
                
            }
        }
};
#endif //LEMP_MYSQLIMPORT_H
