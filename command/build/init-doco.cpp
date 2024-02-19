#include <vector>
#include "include/DockerCompose.h"
#include "include/Common.h"

using namespace std;

int main(int argc, char *argv[])
{
    DockerCompose compose = *new DockerCompose(buildArgs(argc, argv));

    compose.create();

    return 0;
}

