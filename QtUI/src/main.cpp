#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Title");
    window.resize(500, 500);

    QPushButton button("Button", &window);
    button.setFixedSize(100, 100);

    window.show();
    return app.exec();
}

