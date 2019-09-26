#ifndef BASE
#define BASE

#include <QtCore>
#include <QtWidgets>

class Base : public QObject {
    Q_OBJECT
public:
    Base(QWidget *w, int duration = 800, int loopCount = 1);
    ~Base();
    void start();
    void stop();
    bool isRunning();

signals:
    void finished();

public slots:
    virtual void nextStep(int value) = 0;
    virtual void ensureCoherentState() = 0;
    void timelineFinished();

protected:
    virtual void setup() = 0;

    QTimeLine *timeLine;
    int duration;
    QWidget *w;
};
#endif

