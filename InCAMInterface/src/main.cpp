#include <incam.h>

int main() {
    InCAM f;

    // 获取用户名
    std::string user_name;
    f.COM("get_user_name");
    user_name = f.COMANS;
    f.PAUSE(user_name);

    // 获取display
    std::string display;
    display = std::getenv("DISPLAY");
    f.PAUSE(display);

    std::list<std::string> l = f.INFO_MM("-t layer -e 08epj9702da-zq/panel/drillo -d FEATURES");

    for (auto &s : l) {
        std::cout << s << std::endl;
    }

    return 0;
}

