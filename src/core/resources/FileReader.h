//
// Created by deril on 9/9/24.
//

#ifndef FILEREADER_H
#define FILEREADER_H
#include <assert.h>
#include <filesystem>
#include <string>
#include <fstream>
#define RUNNING_IN_IDE

namespace Ursa::Resources {
    class FileReader {
    public:
        static std::string readFile(const std::string& path) {
#ifdef RUNNING_IN_IDE
            std::ifstream file("../" + path);
            assert(file.is_open());
            std::stringstream ss;
            ss << file.rdbuf();
#else
            std::ifstream file(path);
            assert(file.is_open() && "Cannot open file");
            ss << file.rdbuf();
#endif
            return ss.str();
        }

    };
}


#endif //FILEREADER_H
