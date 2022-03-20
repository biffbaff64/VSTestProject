#ifndef __RESOURCE_PATH_H
#define __RESOURCE_PATH_H

#include <string>

namespace GDX
{
    class WorkingDirectory
    {
    public:
        WorkingDirectory();

        inline const std::string& Get()
        {
            return path;
        }

    private:
        std::string path;
    };
}

#endif // __RESOURCE_PATH_H
