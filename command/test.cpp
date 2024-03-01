//
// Created by dangnd on 0019, February 19, 2024.
//
#include "iostream"
#include "build/include/systemCommand.h"
#include "string"
#include <cstring>

using namespace std;

int main()
{
    cout << getServiceEnv("db", "MONGO_INITDB_ROOT_USERNAME");

    return 0;
}