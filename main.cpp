#include <iostream>
#include <fstream>
#include <map>
#include <string>


#include "functional.h"

int main(){
    std::fstream input;
    input.open("input.txt");



    if(!input.is_open())
    {
        std::cout << "File is not open/found" << std::endl;
    }


    std::ofstream result;
    result.open("out.json");

    if(!result.is_open())
    {
        std::cout << "File is not open/found" << std::endl;
    }

    std::map <std::string, int> res_map;

    std::string tmp_str;
    while (input >> tmp_str)
    {
        get_names(res_map , tmp_str);
    }

//    make_chngs(input);
    
    input.close();

    std::remove("input.txt");
    std::rename("temp.txt", "input.txt");

    std::fstream pr_input;
    pr_input.open("input.txt");

    if(!pr_input.is_open())
    {
        std::cout << "File is not open/found" << std::endl;
    }

    std::string new_tmp;
    result << "{ \n\"Text\" : \"";
        while(std::getline(pr_input, new_tmp)){
            result << new_tmp;
        }
    result << "\" ,\n\"ProperNouns\": { \n";


    for(auto it = res_map.begin(); ++it != res_map.end();)
    {
        if(it == std::prev(res_map.end())){
            result << "\""  << it->first << "\"" <<  " : \"" << it->second << " \"  \n";
            break;
        }
        result << "\""  << it->first << "\"" <<  " : \"" << it->second << " \"  ,\n";
    }

    result << "} \n} ";
    

    result.close();
    pr_input.close();
}