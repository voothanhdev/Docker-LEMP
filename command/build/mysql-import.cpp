#include "include/commandCheck.h"
#include "include/Command.h"
#include "string"
#include "map"

using namespace std;

const string OPTION_FILE = "--file";
const string OPTION_USER = "--user";
const string OPTION_PASS = "--password";
const string OPTION_DB = "--database";
const string OPTION_DOCKER_COMPOSE_SERVICE = "--docker-compose-service";

const string CODE = "mysql-import";

string file;
string user;
string pass;
string db;
string service;

Command generateHelp();

int main(int argc, char *argv[])
{
    Command command = generateHelp();

    command.mapValues(argc, argv);

    return 0;
}

Command generateHelp()
{
    Command command = Command::getInstance(CODE,"Import mysql database with docker-compose.");

    command.addOption(
        (new CommandOption({OPTION_FILE, "-f"}))
            ->setDescription("SQL File Path.")
            ->setRequired(true)
            ->setValue(&file)
    );

    command.addOption(
        (new CommandOption({OPTION_USER, "-u"}))
            ->setDescription("Mysql User.")
            ->setDefaultValue("root")
            ->setValue(&user)
    );

    command.addOption(
        (new CommandOption({OPTION_PASS, "-p"}))
            ->setDescription("Mysql Password for User")
            ->setDefaultValue("<Default password for root in compose>")
            ->setValue(&pass)
    );

    command.addOption(
        (new CommandOption({OPTION_DB, "-d"}))
            ->setDescription("Database name")
            ->setDefaultValue("<Default database in compose>")
            ->setValue(&db)
    );

    command.addOption(
        (new CommandOption({OPTION_DOCKER_COMPOSE_SERVICE, "-s"}))
            ->setDescription("Docker Compose Database Service Name")
            ->setDefaultValue("db")
            ->setValue(&service)
    );

    return command;
}