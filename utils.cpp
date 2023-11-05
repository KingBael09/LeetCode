// ? Checks if every file follows rules

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

unordered_set<fs::path> path_check_ignore_list = {"./utils.cpp"};

void path_checker(fs::path path)
{
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (!entry.is_directory() && (entry.path().extension() == ".cpp" || entry.path().extension() == ".ts"))
        {
            auto path = entry.path();

            if (path_check_ignore_list.find(path) != path_check_ignore_list.end())
            {
                continue;
            }

            auto filename = path.filename().generic_string();

            if (filename.find(".incomplete.") != string::npos)
            {
                continue;
            }

            ifstream file;

            file.open(path);

            string line;

            int line_count = 2;

            while (line_count--)
            {
                getline(file, line);

                line.resize(4);

                if (!(line == "// ?"))
                {
                    cout << path.generic_string() << " -> ";
                    if (line_count == 0)
                    {
                        cout << "Link Missing" << endl;
                    }
                    else if (line_count == 1)
                    {
                        cout << "Name Missing" << endl;
                    }
                    else
                    {
                        cout << "Something went wrong" << endl;
                    }
                }
            }

            file.close();
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
    path_checker("./");
}