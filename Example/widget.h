#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "Highlight.hpp"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    Highlight_Effect *highlightEffect;
    Highlight_Effect *pulseEffect;
    Highlight_Effect *anotherPulseEffect;

private slots:
    void highlightButClicked(bool);
    void pulseButClicked(bool);
    void notWorkingBut(bool);
};

#endif // WIDGET_H
