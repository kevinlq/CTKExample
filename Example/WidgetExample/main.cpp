#include <QApplication>
#include <QStandardItemModel>

#include "Widget.h"
#include "ctkTreeComboBox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
