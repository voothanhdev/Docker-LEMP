//
// Created by Đình Đăng on 28/12/2023.
//

#ifndef LEMP_COMMANDCHECK_H
#define LEMP_COMMANDCHECK_H

#include "unistd.h"
#include "string"
#include "message.h"
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const string DOCKER_COMPOSE_CMD = "docker-compose";
const string PHP_SERVICE = "php";


bool isEmpty(char c)
{
    char charTrim[] = {' ', '\n', '\t', '\r'};

    return strchr(charTrim, c) != NULL;
}

string getResultCommand(string command, int size)
{
    string result = "";
    char buffer[size];
    FILE *fd = popen(command.c_str(), "r");

    if (NULL == fd)
    {
        return "";
    }

    for (int i = 0; i < size; i++) {
        buffer[i] = ' ';
    }

    fread(buffer, 100, 1, fd);

    for (int i = 0; i < size; i++)
    {
        if (buffer[i] == '\000'
            || (isEmpty(buffer[i]) && (result.empty() || i == 0 || i == size - 1 || isEmpty(buffer[i + 1])))
        ) {
            continue;
        }

        result += buffer[i];
    }

    pclose(fd);

    return result;
}

bool hasCommand(string command)
{
    int status = system(("hash " + command + " 2>/dev/null").c_str());

    if (status == 0) {
        return true;
    }

    showRed("`" + command + "` Command not found.");

    return false;
}

bool hasDockerCompose()
{
    return hasCommand(DOCKER_COMPOSE_CMD);
}

bool exec(string command)
{
    return system(command.c_str()) == 0;
}

bool dockerCompose(string options)
{
    if (!hasDockerCompose()) {
        return false;
    }

    string command = DOCKER_COMPOSE_CMD;

    if (!options.empty()) {
        command += " " + options;
    }

    return exec(command);
}

bool dockerCompose()
{
    return dockerCompose("");
}

bool phpService(string options)
{
    string mainOptions = "exec php";

    if (!options.empty()) {
        mainOptions += " " + options;
    }

    return dockerCompose(mainOptions);
}

string buildCommand(int argc, char *argv[])
{
    string result;

    for (int i = 1; i < argc; i++)
    {
        result.append(argv[i]).append(" ");
    }

    return result;
}

bool isDockerComposeService(string serviceName)
{
    string command = DOCKER_COMPOSE_CMD + " ps -q " + serviceName + " 2>/dev/null";

    return exec(command);
}

string getServiceEnv(string serviceName, string key)
{
    return getResultCommand(
        DOCKER_COMPOSE_CMD
        + " exec "
        + serviceName
        + " printenv | grep " + key + " | tr \"=\" \" \" | awk '{print $2}'"
        ,100
    );
}
#endif //LEMP_COMMANDCHECK_H
