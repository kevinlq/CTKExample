#include <QApplication>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QDebug>

/* ctk widget lib*/
#include "ctkCollapsibleButton.h"
#include "ctkCheckablePushButton.h"
#include "ctkColorPickerButton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ctkCollapsibleButton *pCollappBtn = new ctkCollapsibleButton("collBtn");
    ctkCheckablePushButton *pBtn = new ctkCheckablePushButton("button");
    ctkColorPickerButton *pColorBtn = new ctkColorPickerButton("colorBtn");

    QHBoxLayout *pLayout = new QHBoxLayout;
    pLayout->addWidget(pCollappBtn);
    pLayout->addWidget(pBtn);
    pLayout->addWidget(pColorBtn);

    QVBoxLayout *pVLayout = new QVBoxLayout;
    pVLayout->addLayout(pLayout);

    QWidget widget;
    widget.resize(800,480);
    widget.setLayout(pVLayout);
    widget.show();

    return a.exec();
}
