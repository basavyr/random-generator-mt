#include "../include/filestream.hh"
#include "../include/container.hh"

inline void line() { std::cout << '\n'; }

//checks if the file is empty or not
//? peek function and type traits works like a charm
bool Empty_File(std::ifstream &file)
{
    //using the peak function
    return file.peek() == std::ifstream::traits_type::eof(); //checks the the content is the same as the type of EOF
}

static void WriteContainers(std::ofstream &file)
{
    std::vector<int> standard_container;  //use just for testing purpose! dimension of container is predefined by the container class itself
    std::vector<double> custom_container; //use for the normal constructor in the container namespace
    auto x = std::make_unique<container::Containers>(custom_container, 100000, 1.0, 0.0, 9999.0);
    x->PrintContainerToFile(file, custom_container);
}

file::Filestream::Filestream(const std::string &file_name, int n_files, const std::string &file_ext)
{
    for (auto file_id = n_files; file_id > 0; file_id--)
    {
        //creates the path file as a string for using in the file checker and file generator part
        auto id_filepath = "../output/" + file_name + std::to_string(file_id) + file_ext;
        // auto id_filepath = file_name + std::to_string(file_id) + file_ext; //?use the current working directory to create the files.
        out_file.open(id_filepath);

        //################
        //TODO - This is the place to do the operations (with regards to containers and actual numbers)
        WriteContainers(out_file); //? the actual writing implementation
        //################
        out_file.close(); //!close the file after the containers are created and emplaced into the right files

        std::ifstream input_file(id_filepath);
        // auto checker = static_cast<int>(Empty_File(input_file));
        // (!checker) && file_integrity_checker.emplace_back(1); //file is not empty
        // (checker) && file_integrity_checker.emplace_back(0);  //file is empty
        if (Empty_File(input_file)) //! returns 1 if the file is empty
        {
            // std::cout << Empty_File(input_file);
            file_integrity_checker.emplace_back(0); //the empty file returns true if the content is set equal to EOL
        }
        else
        {
            // std::cout << Empty_File(input_file);
            file_integrity_checker.emplace_back(1);
        }
    }
}

file::Filestream::~Filestream()
{
    const std::string ok_msg = "The files were succsessfully generated!\n";
    const std::string err_Msg = "The file generation failed!!!\n";
    const std::string ok_msg2 = "Exiting the file-class...\n";
    if (std::all_of(file_integrity_checker.begin(), file_integrity_checker.end(), [](int i) { return i > 0; }))
    {
        std::cout << ok_msg;
    }
    else
    {
        std::cout << err_Msg;
    }
    std::cout << ok_msg2;
}