#include <incam.h>

std::string comms = "pipe";

InCAM::InCAM() {
    prefix = "@%#%@";
    blank();
    pid = getpid();
    tmpfile = "/tmp/incam_" + std::to_string(pid) + "." + std::to_string(time(nullptr));
}

InCAM::~InCAM() {
    if (remove(tmpfile.c_str()) != 0) {
        // perror("无临时文件!");
    }
}

int InCAM::sendCmd(const std::string& cmd, const std::string& args = "") {
    blank();
    sendCommandToPipe(cmd, args);
}

int InCAM::sendCommandToPipe(const std::string& cmd, const std::string& args) {
    std::string command = prefix + cmd + (args.empty() ? "" : " ") + args + "\n";
    std::cout << command;
    std::cout.flush();
    return 0;
}

std::string InCAM::getReply() {
    std::string reply;
    std::getline(std::cin, reply);
    return reply;
}

void InCAM::blank() {
    STATUS = 0;
    READANS.clear();
    COMANS.clear();
    PAUSANS.clear();
    MOUSEANS.clear();
}

int InCAM::SU_ON() {
    return sendCmd("SU_ON");
}

int InCAM::SU_OFF() {
    return sendCmd("SU_OFF");
}

int InCAM::VON() {
    return sendCmd("VON");
}

int InCAM::VOF() {
    return sendCmd("VOF");
}

int InCAM::PAUSE(const std::string& msg) {
    sendCmd("PAUSE", msg);
    STATUS = std::stoi(getReply());
    READANS = getReply();
    PAUSANS = getReply();
    return STATUS;
}

int InCAM::COM(const std::string& args) {
    sendCmd("COM", args);
    STATUS = std::stoi(getReply());
    READANS = getReply();
    COMANS = READANS;
    return STATUS;
}

int InCAM::AUX(const std::string& args) {
    sendCmd("AUX", args);
    STATUS = std::stoi(getReply());
    READANS = getReply();
    COMANS = READANS;
    return STATUS;
}

std::list<std::string> InCAM::INFO(const std::string& args) {
    std::list<std::string> lines;
    COM("info,out_file=" + tmpfile + ",write_mode=replace,args=" + args);
    std::ifstream file(tmpfile);
    if (!file) {
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

std::list<std::string> InCAM::INFO_MM(const std::string& args) {
    std::list<std::string> lines;
    COM("info,out_file=" + tmpfile + ",write_mode=replace,units=mm,args=" + args);
    std::ifstream file(tmpfile);
    if (!file) {
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

boost::variant<int, double, std::string> InCAM::convertToNumber(const std::string& value) {
    try {
        // 尝试转换为整数
        size_t pos;
        int intValue = std::stoi(value, &pos);
        if (pos == value.size()) {
            return intValue;
        }
    } catch (...) {}

    try {
        // 尝试转换为浮点数
        size_t pos;
        double doubleValue = std::stod(value, &pos);
        if (pos == value.size()) {
            return doubleValue;
        }
    } catch (...) {}

    // 返回原字符串
    return value;
}

// // 解析infoList
// std::map<std::string, boost::variant<int, double, std::string, std::vector<std::string>>> 
// InCAM::parseInfo(const std::vector<std::string>& infoList) {
//     std::map<std::string, boost::variant<int, double, std::string, std::vector<std::string>>> parseDict;
// 
//     std::regex whitespaceRegex("^\\s+$");
// 
//     for (const auto& line : infoList) {
//         std::string trimmedLine = trim(line);
//         auto keywithval = split(trimmedLine, " = ", 2);
// 
//         if (keywithval.size() == 2) {
//             std::string key = trim(keywithval[0]).substr(4);
//             std::string val = keywithval[1];
//             auto allValList = split(val, "'");
//             std::vector<std::string> valList;
// 
//             if (allValList.size() > 0 && allValList[0] == "(") {
//                 allValList = std::vector<std::string>(allValList.begin() + 1, allValList.end() - 1);
//                 for (const auto& v : allValList) {
//                     if (v.empty() || std::regex_match(v, whitespaceRegex)) {
//                         continue;
//                     } else {
//                         valList.push_back(v);
//                     }
//                 }
//             } else if (allValList.size() > 0 && allValList[0] == "()") {
//                 valList.clear();
//             } else {
//                 if (allValList.size() == 1) {
//                     auto converted = convertToNumber(allValList[0]);
//                     parseDict[key] = converted;
//                 } else if (allValList.size() == 3) {
//                     auto converted = convertToNumber(allValList[1]);
//                     parseDict[key] = converted;
//                 }
//             }
// 
//             if (!valList.empty()) {
//                 parseDict[key] = valList;
//             }
//         }
//     }
// 
//     return parseDict;
// }
// 
// // 辅助函数：去除字符串首尾空格
// std::string InCAM::trim(const std::string& str) {
//     size_t first = str.find_first_not_of(" \t\n\r");
//     size_t last = str.find_last_not_of(" \t\n\r");
//     return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
// }
// 
// // 辅助函数：按分隔符拆分字符串
// std::vector<std::string> InCAM::split(const std::string& str, const std::string& delimiter, size_t maxSplit = 0) {
//     std::vector<std::string> tokens;
//     size_t start = 0, end;
//     size_t count = 0;
// 
//     while ((end = str.find(delimiter, start)) != std::string::npos) {
//         tokens.push_back(str.substr(start, end - start));
//         start = end + delimiter.length();
//         if (maxSplit && ++count >= maxSplit - 1) break;
//     }
//     tokens.push_back(str.substr(start));
//     return tokens;
// }
