#ifndef USER_HPP
#define USER_HPP

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = 0);

signals:

public slots:

};

#endif // USER_HPP
