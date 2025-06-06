#include <incam.h>

int main() {
    InCAM f;

    // 获取用户名
    std::string user_name;
    f.COM("get_user_name");
    user_name = f.COMANS;
    f.PAUSE(user_name);

    // 获取料号名
    // std::string job;
    // job = std::getenv("JOB");
    // f.PAUSE(job);

    return 0;
}

