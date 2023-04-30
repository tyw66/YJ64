#include "database.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

Database* Database::m_self = NULL;
Database *Database::inst()
{
    if(!m_self){
        m_self = new Database();
    }
    return m_self;
}

void Database::read(const QString &fileName)
{
    QFile file(fileName);
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList info = line.split(' ', QString::SkipEmptyParts);
            if(info.size() == 5){

                QString up = info[2];           //上卦
                QString down = info[3];         //下卦
                int uid = up.toInt() * 8 + down.toInt();

                QString guaci = info[4];         //卦辞

                DiagramData d;
                d.uid = QString::number(uid);
                d.name = info[0] + "_" + info[1];
                d.guaci = guaci;
                m_data.insert(d.uid,d);
                qDebug() << d.uid << " " << d.name << d.guaci;
            }
        }
        file.close();
    }

}

QString Database::queryDiagramName(Diagram8 up, Diagram8 down)
{
    qDebug() << up << down;
    int uidTemp = (int)up * 8 + (int)down;
    QString uid = QString::number(uidTemp);
    if(m_data.contains(uid)){
        return m_data[uid].name;
    }
    else{
        return "";
    }
}

QString Database::queryDiagramIntro(Diagram8 up, Diagram8 down)
{
    qDebug() << up << down;
    int uidTemp = (int)up * 8 + (int)down;
    QString uid = QString::number(uidTemp);
    if(m_data.contains(uid)){
        return m_data[uid].guaci;
    }
    else{
        return "";
    }
}
