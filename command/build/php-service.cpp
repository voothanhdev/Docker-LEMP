#include "include/commandCheck.h"

int main(int argc, char *argv[])
{
    phpService(buildCommand(argc, argv));

    return 0;
}