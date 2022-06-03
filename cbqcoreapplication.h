#ifndef CBQCOREAPPLICATION_H
#define CBQCOREAPPLICATION_H

#include <QCoreApplication>
#include "conbarcode.h"


class CBQCoreApplication : public QCoreApplication
{
public:
    CBQCoreApplication(int&,char**&);
    ConBarcode* cbc;

public slots:
    void onBarcodeRead();

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // CBQCOREAPPLICATION_H
