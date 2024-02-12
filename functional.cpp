#include "functional.h"

void dl_extra(std::string& str)
{
    if(str[str.size() - 1] < 97 || str[str.size() - 1] > 122){
        str.erase(str.size() - 1);
    }
}

void get_names(std::map<std::string, int>& res_map, const std::string& line) {
    std::ofstream tmp("temp.txt", std::ios::app); 

    if (!tmp.is_open()) {
        std::cerr << "Failed to open temporary file!" << std::endl;
        return;
    }

    std::stringstream ss(line);
    std::string tmp_word;
    while (ss >> tmp_word) {
        if (std::isupper(tmp_word[0])) {
            dl_extra(tmp_word);
            ++res_map[tmp_word];
            tmp_word = "X";
        }
        tmp << tmp_word << " ";
    }
    tmp << std::endl; 
    tmp.close();
}


