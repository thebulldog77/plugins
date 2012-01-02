#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = 0);

signals:

public slots:

};

#endif // BACKEND_HPP
