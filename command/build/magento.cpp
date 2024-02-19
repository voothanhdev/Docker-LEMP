#include "include/commandCheck.h"
#include "string"

using namespace std;

int main(int argc, char *argv[])
{
    string command = "bin/magento";
    string options = buildCommand(argc, argv);

    if (!options.empty()) {
        command += " " + options;
    }

    phpService(command);

    return 0;
}