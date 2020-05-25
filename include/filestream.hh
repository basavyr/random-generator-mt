#ifndef FILESTREAM_HH
#define FILESTREAM_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<memory> //needs memory header for the testing unit (since the source test only imports this header)
namespace file
{
    class Filestream
    {
    private:
        std::ofstream out_file;
        std::vector<int> file_integrity_checker;

    public:
        //construct the file-system using a predefined numebr of files, and predefined extention
        Filestream(const std::string &FILE_NAME, int N_O_FILES, const std::string &FILE_EXT);
        ~Filestream();
    };
} // namespace file

#endif // FILESTREAM_HH
