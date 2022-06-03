#include <QDebug>
#include "cbqcoreapplication.h"

CBQCoreApplication::CBQCoreApplication(int &c, char** &v): QCoreApplication(c,v)
{
    cbc = new ConBarcode();

    if ( c > 1 )
         cbc->setPortName( QLatin1String( v[1] ) );
    else cbc->setPortName( QLatin1String("/dev/ttyS0") );

    //connect(cbc, SIGNAL(readComplete()), SLOT(onBarcodeRead()));

    startTimer(3e3);
}

void CBQCoreApplication::onBarcodeRead()
{
    qDebug() << cbc->text();
}


void CBQCoreApplication::timerEvent(QTimerEvent *event)
{
    if ( cbc->isOpen() )
         qDebug() << cbc->text();
    else qDebug() << "Barcoder is disconnected";
}
