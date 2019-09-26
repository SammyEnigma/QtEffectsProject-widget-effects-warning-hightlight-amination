#include "Highlight.hpp"

Highlight_Effect::Highlight_Effect(QWidget *w, QColor effectColor,
                                   int duration,
                                   int loopCount) : Base(w, duration, loopCount),
    effectColor(effectColor)
{
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
    w->setAutoFillBackground(true);
}

Highlight_Effect::~Highlight_Effect() {
}

void Highlight_Effect::setup() {
    QPalette palette = w->palette();
    QColor color = palette.color(w->backgroundRole());

    QPalette defaultPalette = QApplication::palette();
    restoreColor = defaultPalette.color(QPalette::Window);
}

void Highlight_Effect::nextStep(int value) {
    value = 255 - value;

    // manual alpha blending
    QColor newColor = effectColor;
    const double alpha = (double)value/255;
    const double alpha1 = 1 - alpha;
    newColor.setRed(alpha1 * restoreColor.red() + alpha * newColor.red());
    newColor.setGreen(alpha1 * restoreColor.green() + alpha * newColor.green());
    newColor.setBlue(alpha1 * restoreColor.blue() + alpha * newColor.blue());

    QPalette palette = w->palette();
    palette.setColor(w->backgroundRole(), newColor);
    w->setPalette(palette);
    w->repaint();
}

void Highlight_Effect::ensureCoherentState() {
    QPalette palette = w->palette();
    palette.setColor(w->backgroundRole(), restoreColor);
    w->setPalette(palette);
    w->repaint();
}
