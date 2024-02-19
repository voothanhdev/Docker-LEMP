#include "include/commandCheck.h"
#include "string"

int main(int argc, char *argv[])
{
    std::string command = "m2";
    std::string options = buildCommand(argc, argv);

    if (!options.empty()) {
        command += " " + options;
    }

    phpService(command);

    return 0;
}