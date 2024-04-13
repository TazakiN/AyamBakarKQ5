#include "writeFile.h"

bool validateDirectory(const string &dir)
{
    struct stat info;
    cout << "Checking directory: " << dir << endl;

    if (stat(dir.c_str(), &info) != 0)
    {
        return false;
    }
    else if (info.st_mode & S_IFDIR)
    {
        return true;
    }
    else
    {
        return false;
    }
}