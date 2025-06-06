#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <list>
#include <regex>
#include <stdexcept>
#include <boost/variant.hpp>

class InCAM {
public:
    std::string prefix;
    std::string tmpfile;
    std::string remote;
    std::string comms;
    pid_t pid;

    int STATUS;
    std::string READANS;
    std::string COMANS;
    std::string PAUSANS;
    std::string MOUSEANS;

    InCAM();

    ~InCAM();

    int sendCmd(const std::string& cmd, const std::string& args);

    int sendCommandToPipe(const std::string& cmd, const std::string& args);

    std::string getReply();

    void blank();

    int SU_ON();

    int SU_OFF();

    int VON();

    int VOF();

    int PAUSE(const std::string& msg);

    int COM(const std::string& args);

    int AUX(const std::string& args);

    std::list<std::string> INFO(const std::string& args);

    std::list<std::string> INFO_MM(const std::string& args);

    boost::variant<int, double, std::string> convertToNumber(const std::string& value);
    
    // std::map<std::string, boost::variant<int, double, std::string, std::vector<std::string>>> parseInfo(const std::vector<std::string>& infoList);
    // 
    // std::string trim(const std::string& str);
    // 
    // std::vector<std::string> split(const std::string& str, const std::string& delimiter, size_t maxSplit);

};


