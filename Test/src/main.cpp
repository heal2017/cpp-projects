#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

int main(void) {
    {
        int num;

        // const char *num_type;
        string num_type;

        cout << "输入一个整数:";
        cin >> num;

        cout << "==========for===========\n";
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) {
                num_type = "偶数";
            } else {
                num_type = "奇数";
            }
            cout << i << "\t" << num_type << "\n";
        }

        cout << "===========while==========\n";
        int i = 1;
        while (i <= num) {
            if (i % 2 == 0) {
                num_type = "偶数";
            } else {
                num_type = "奇数";
            }
            cout << i << "\t" << num_type << "\n";
            i++;
        }
    }

    {
        cout << "===========pointer==========\n";
        int val = 1024;
        int &ref_val = val;
        int *p = &val;

        ref_val = 8;
        *p = 9;
        cout << "数值:" << ref_val  << " " << val  << " " << *p             << endl;
        cout << "地址:" << &ref_val << " " << &val << " " << p << " " << &p << endl;
    }

    {
        cout << "===========const==========\n";
        const double const_var = 2.99;
        const int &const_ref_var = const_var;
        const double *const_p = &const_var;
        cout << const_var << " " << const_ref_var << " " << *const_p << endl;
    }

    {
        cout << "===========const==========\n";
        double const_var = 3.14;
        const double &const_ref_var = const_var;
        const double *const_p = &const_var;
        const_var = 3.15;
        cout << const_var << " " << const_ref_var << " " << *const_p << endl;
    }

    {
        cout << "===========constexpr==========\n";
        // var1指向的变量是常量
        const int *var1 = nullptr;
        // var2是常量指针
        constexpr int *var2 = nullptr;
        cout << var1 << " " << var2 << endl;
    }

    {
        cout << "===========typedef==========\n";
        const char *str1 = "1";
        typedef char *pstring;
        const pstring str2 = "2";
        cout << str1 << " " << str2 << endl;
    }

    {
        cout << "===========auto==========\n";
        auto i = 0;
        auto j = 0.123;
        auto k = "Hello";
        cout << typeid(i).name() << endl;
        cout << typeid(j).name() << endl;
        cout << typeid(k).name() << endl;
    }

    {
        cout << "===========decltype==========\n";
        int i = 0;
        decltype(i) j = 5;
        int k = 5;
        cout << typeid(i).name() << endl;
        cout << typeid(j).name() << endl;
        cout << typeid(k).name() << endl;
    }

    {
        cout << "===========struct==========\n";
        struct People {
            string name;
            int age;
        };
        struct People pp1, pp2;
        pp1.name = "Wicky";
        cout << pp1.name << endl;
    }

    {
        cout << "===========string==========\n";
        string line;
        cout << "输入字符,返回长度:";
        while (getline(cin, line)) {
            if (!line.empty()) {
                cout << "size: " << line.size() << endl;
                break;
            }
        }
    }

    {
        cout << "===========string==========\n";
        string st1(5, 'o'), st2(5, '0');
        cout << st1 << " " << st2 << endl;
        cout << st1 + st2 << endl;
    }

    {
        cout << "===========string==========\n";
        string str = "hello world！";
        for (auto &c : str) {
            c = toupper(c);
        }
        cout << str << endl;
    }

    {
        cout << "===========string==========\n";
        string str = "hello world！";
        if (!str.empty()) {
            str[0] = toupper(str[0]);
        }
        cout << str << endl;
    }

    {
        cout << "===========vector==========\n";
        vector<string> ivec = {"one", "date", "video", "diode"};
        ivec.push_back("traffic");
        ivec[0] = "two";
        for (auto &s : ivec) {
            s[0] = toupper(s[0]);
            cout << s << endl;
        }
        cout << "Size: " << ivec.size() << endl;
    }

    {
        cout << "===========迭代器==========\n";
        string str = "nice to meet you!";
        if (str.begin() != str.end()) {
            auto it = str.begin();
            *it = toupper(*it);
        }
        cout << str << endl;
    }

    return 0;
}

