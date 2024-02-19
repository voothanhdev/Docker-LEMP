#include "include/commandCheck.h"

int main(int argc, char *argv[])
{
    dockerCompose(buildCommand(argc, argv));

    return 0;
}