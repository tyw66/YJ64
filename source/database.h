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
    void readBasic(const QString& fileName);
    void readYaoci(const QString& fileName);

    QString queryDiagramName(Diagram8 up, Diagram8 down);  //查询名称
    QString queryDiagramIntro(Diagram8 up, Diagram8 down); //查询卦辞
    QString queryDiagramYao(Diagram8 up, Diagram8 down, int index);//查询爻辞


private:
    Database(){}
    static Database* m_self;

    QMap<QString,DiagramData> m_data;


};

#endif // DATABASE_H
