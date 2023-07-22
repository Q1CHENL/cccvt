#include <algorithm>
#include <iostream>
#include <string>

#include "opencc.h"

bool cmd_option_exists(char** begin, char** end, const std::string& option);

std::string helper_msg = R"(
Usage:
cccvt [-h] <要转换的字 Text to convert> [Options]

Options:
--t2s      转换<要转换的字>为简体(默认为简到繁)
           Convert <Text to convert> chinese to simplified chinese
           (Default is simplified to traditional)
)";

int main(int argc, char** argv) {
    std::string json("s2t.json");
    if (cmd_option_exists(argv, argv + argc, "-h")) {
        std::cout << helper_msg << std::endl;
        return 0;
    }
    if (cmd_option_exists(argv, argv + argc, "--t2s")) {
        json = "t2s.json";
    }

    const opencc::SimpleConverter cvt(json);
    std::string input(argv[1]);
    std::string converted = cvt.Convert(input);
    std::cout << converted << std::endl;
    return 0;
}

bool cmd_option_exists(char** begin, char** end, const std::string& option) {
    return std::find(begin, end, option) != end;
}