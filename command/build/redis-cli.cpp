#include "include/commandCheck.h"

using namespace std;

int main(int argc, char *argv[])
{
    string command = "exec redis redis-cli";
    string options = buildCommand(argc, argv);

    if (!options.empty()) {
        command += " " + options;
    }

    dockerCompose(command);

    return 0;
}