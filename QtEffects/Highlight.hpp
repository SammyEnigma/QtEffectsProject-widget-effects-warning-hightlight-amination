#ifndef HIGHLIGHT_EFFECT
#define HIGHLIGHT_EFFECT

#include "Base.hpp"

class Highlight_Effect : public Base {
    Q_OBJECT
public:
    Highlight_Effect(QWidget *w, QColor effectColor = Qt::yellow, int duration = 800, int loopCount = 1);
    ~Highlight_Effect();

public slots:
    void ensureCoherentState();
    void nextStep(int value);

protected:
    void setup();
    QColor restoreColor;
    const QColor effectColor;
};
#endif

