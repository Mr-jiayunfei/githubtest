#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestWidget.h"

class TestWidget : public QMainWindow
{
    Q_OBJECT

public:
    TestWidget(QWidget *parent = Q_NULLPTR);

private:
    Ui::TestWidgetClass ui;
};
