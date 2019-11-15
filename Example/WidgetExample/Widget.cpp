#include "Widget.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStandardItemModel>

#include <QDebug>

/* ctk widget lib*/
#include "ctkCollapsibleButton.h"
#include "ctkCheckablePushButton.h"
#include "ctkColorPickerButton.h"

#include "ctkComboBox.h"
#include "ctkTreeComboBox.h"

#include "ctkButtonGroup.h"
#include "ctkColorDialog.h"


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    ctkCollapsibleButton *pCollappBtn = new ctkCollapsibleButton("collBtn");
    ctkCheckablePushButton *pBtn = new ctkCheckablePushButton("button");
    ctkColorPickerButton *pColorBtn = new ctkColorPickerButton("colorBtn");

    QHBoxLayout *pButtonLayout = new QHBoxLayout;
    pButtonLayout->addWidget(pCollappBtn);
    pButtonLayout->addWidget(pBtn);
    pButtonLayout->addWidget(pColorBtn);
    pButtonLayout->addStretch();

    QVBoxLayout *pVLayout = new QVBoxLayout;
    pVLayout->addLayout(pButtonLayout);

    this->setLayout(pVLayout);

    this->resize(500,480);
}
