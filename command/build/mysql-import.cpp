#include "include/systemCommand.h"
#include "include/Command.h"
#include "string"
#include "map"
#include "include/MysqlImport.h"

using namespace std;

Command generateHelp();

int main(int argc, char *argv[])
{
    MysqlImportCommand *command = new MysqlImportCommand();

    command->init(argc, argv);

    command->exec();

    return 0;
}
