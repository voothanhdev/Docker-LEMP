#include "include/commandCheck.h"
#include "string"
#include "include/Help.h"

using namespace std;

Help generateHelp();

const string CODE = "docker-container-clean";

const string EXCLUDE_OPTION = "--exclude";
const string ALL_OPTION     = "--all";

int main(int argc, char *argv[])
{
    Help help = generateHelp();
    vector<string> arguments = buildArgs(argc, argv);

    return 0;
}

Help generateHelp()
{
    Help result = Help::getInstance(CODE, "Clean Docker Container. Default only scan not active container.");

    result.addOption(
        {
            (new CommandOption({ALL_OPTION, "-a"}))
                ->setDescription("Scan all container (active + not active container)")
                ->setNonValue(true)
            , (new CommandOption({EXCLUDE_OPTION, "-e"}))
            ->setDescription("Prefix of Container will not remove.")
            ->setMultiple(true)
        }
    );

    return result;
}