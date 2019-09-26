#include "Base.hpp"

Base::Base(QWidget *w, int duration, int loopCount) 
    : duration(duration), w(w){
    timeLine = new QTimeLine(duration);
    timeLine->setFrameRange(0, 255);
    timeLine->setLoopCount(loopCount);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(nextStep(int)));
    connect(timeLine, SIGNAL(finished()), this, SLOT(timelineFinished()));
}

Base::~Base() {
}

bool Base::isRunning() {
    return timeLine->state() == QTimeLine::Running;
}

void Base::timelineFinished() {
    ensureCoherentState();
    emit finished();
}

void Base::start() {
    setup();
    timeLine->start();
}

void Base::stop() {
    timeLine->stop();
    ensureCoherentState();
}
