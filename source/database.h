#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QObject>
#include <QMap>

#include "diagram.h"

struct DiagramData{
    QString uid;
    QString name;
    QString guaci;
    QString yaoci[6];
};

class Database
{
public:
    static Database* inst();
    void read(const QString& fileName);

    QString queryDiagramName(Diagram8 up, Diagram8 down);


private:
    Database(){}
    static Database* m_self;

    QMap<QString,DiagramData> m_data;


};

#endif // DATABASE_H
