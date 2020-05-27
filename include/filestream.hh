#ifndef FILESTREAM_HH
#define FILESTREAM_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono> //time measurements
#include <memory> //needs memory header for the testing unit (since the source test only imports this header)
namespace file
{
    class Filestream
    {
    private:
        std::ofstream out_file;
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        std::vector<int>
            file_integrity_checker;

    public:
        //construct the file-system using a predefined numebr of files, and predefined extention
        Filestream(const std::string &FILE_NAME, int N_O_FILES, const std::string &FILE_EXT);
        ~Filestream();
        void measureTime();
    };
} // namespace file

#endif // FILESTREAM_HH
