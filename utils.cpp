// ? Checks if every file follows rules

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

unordered_set<fs::path> file_check_ignore_list = {"./utils.cpp"};
unordered_set<fs::path> file_check_extensions = {".cpp", ".ts"};

void file_checker(fs::path path)
{
    vector<string> errors;

    for (const auto &entry : fs::directory_iterator(path))
    {
        auto pathname = entry.path();

        if (!entry.is_directory() && file_check_extensions.find(pathname.extension()) != file_check_extensions.end())
        {

            if (file_check_ignore_list.find(pathname) != file_check_ignore_list.end())
            {
                continue;
            }

            auto filename = pathname.filename().generic_string();

            if (filename.find(".incomplete.") != string::npos)
            {
                continue;
            }

            ifstream file;

            file.open(pathname);

            string line;

            int line_count = 2;

            while (line_count--)
            {
                getline(file, line);

                line.resize(4);

                if (!(line == "// ?"))
                {

                    string error = pathname.generic_string() + " -> ";

                    if (line_count == 0)
                    {
                        error += "Link Missing";
                    }
                    else if (line_count == 1)
                    {
                        error += "Name Missing";
                    }
                    else
                    {
                        error += "Something went wrong";
                    }

                    errors.push_back(error);
                }
            }

            file.close();
        }
    }

    if (errors.empty())
    {
        cout << "No Errors" << endl;
    }
    else
    {
        for (auto err : errors)
        {
            cout << err << endl;
        }
    }
}

void remove_exe(fs::path path)
{
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (!entry.is_directory())
        {
        }
    }
}

int main()
{
    file_checker("./");
}