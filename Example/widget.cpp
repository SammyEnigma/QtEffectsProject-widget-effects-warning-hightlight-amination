#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *highlightBut = new QPushButton("simple default highlight");
    highlightEffect = new Highlight_Effect(this);
    connect(highlightBut, SIGNAL(clicked(bool)), this, SLOT(highlightButClicked(bool)));
    layout->addWidget(highlightBut);

    QPushButton *pulseBut = new QPushButton("3 red pulse");
    pulseEffect = new Highlight_Effect(pulseBut, Qt::red, 800, 3);
    connect(pulseBut, SIGNAL(clicked(bool)), this, SLOT(pulseButClicked(bool)));
    layout->addWidget(pulseBut);

    /* QEffects HighLight class can only change the background color of those widgets whose
     * autoFillBackground property is set to true.
     * In the constructor, HighLight class exlicitly set autoFillBackground property of its
     * parent widget to true to enable itself to change the background color of it.
     *
     * Note: QEffects HighLight effect will not be applied to a widget if it has a style
     * sheet with a valid background OR a border-image!
     *
     * See the below warning from Qt:
     * https://doc.qt.io/qt-5/qwidget.html#autoFillBackground-prop
     * Warning: Use autoFillBackground property with caution in conjunction with Qt Style
     * Sheets. When a widget has a style sheet with a valid background or a border-image,
     * this property is automatically disabled.
     */
    QPushButton *notWorkingBut = new QPushButton("3 red pulse");
    notWorkingBut->setStyleSheet("background: green;");
    anotherPulseEffect = new Highlight_Effect(notWorkingBut, Qt::red, 800, 3);
    connect(notWorkingBut, SIGNAL(clicked(bool)), this, SLOT(notWorkingBut(bool)));
    layout->addWidget(notWorkingBut);

    resize(300, 300);
    setLayout(layout);
    show();
}

Widget::~Widget()
{
    delete highlightEffect;
    delete pulseEffect;
    delete anotherPulseEffect;

    delete ui;
}

void Widget::highlightButClicked(bool)
{
    if (highlightEffect->isRunning())
        highlightEffect->stop();
    highlightEffect->start();
}

void Widget::pulseButClicked(bool)
{
    if (pulseEffect->isRunning())
        pulseEffect->stop();
    pulseEffect->start();
}

void Widget::notWorkingBut(bool)
{
    if (anotherPulseEffect->isRunning())
        anotherPulseEffect->stop();
    anotherPulseEffect->start();
}
