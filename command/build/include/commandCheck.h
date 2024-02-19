//
// Created by Đình Đăng on 28/12/2023.
//

#ifndef LEMP_COMMANDCHECK_H
#define LEMP_COMMANDCHECK_H

#include "unistd.h"
#include "string"
#include "message.h"
#include <cstdlib>

const std::string DOCKER_COMPOSE_CMD = "docker-compose";
const std::string PHP_SERVICE = "php";

bool hasCommand(std::string command)
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

bool exec(std::string command)
{
    return !!system(command.c_str());
}

bool dockerCompose(std::string options)
{
    if (!hasDockerCompose()) {
        return false;
    }

    std::string command = DOCKER_COMPOSE_CMD;

    if (!options.empty()) {
        command += " " + options;
    }

    return exec(command);
}

bool dockerCompose()
{
    return dockerCompose("");
}

bool phpService(std::string options)
{
    std::string mainOptions = "exec php";

    if (!options.empty()) {
        mainOptions += " " + options;
    }

    return dockerCompose(mainOptions);
}

std::string buildCommand(int argc, char *argv[])
{
    std::string result;

    for (int i = 1; i < argc; i++)
    {
        result.append(argv[i]).append(" ");
    }

    return result;
}

#endif //LEMP_COMMANDCHECK_H
