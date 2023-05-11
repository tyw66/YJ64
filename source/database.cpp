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

void Database::readBasic(const QString &fileName)
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

void Database::readYaoci(const QString &fileName)
{
    QFile file(fileName);
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            //【line格式】01  乾   7   7  潜龙勿用。|见龙在田，利见大人。|君子....
            QString line = in.readLine();
            QStringList info = line.split(' ', QString::SkipEmptyParts);
            if(info.size() == 5){
                QString up = info[2];           //上卦
                QString down = info[3];         //下卦
                QString uid = QString::number(up.toInt() * 8 + down.toInt());

                QStringList yaociList = info[4].split('|', QString::SkipEmptyParts);
                if(yaociList.size() == 6){
                    DiagramData d = m_data[uid];
                    d.yaoci[0] = yaociList[0];
                    d.yaoci[1] = yaociList[1];
                    d.yaoci[2] = yaociList[2];
                    d.yaoci[3] = yaociList[3];
                    d.yaoci[4] = yaociList[4];
                    d.yaoci[5] = yaociList[5];
                    m_data.insert(d.uid,d);
                    qDebug() << d.name << d.yaoci;
                }
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
//    qDebug() << up << down;
    int uidTemp = (int)up * 8 + (int)down;
    QString uid = QString::number(uidTemp);
    if(m_data.contains(uid)){
        return m_data[uid].guaci;
    }
    else{
        return "";
    }
}

QString Database::queryDiagramYao(Diagram8 up, Diagram8 down, int index)
{
//    qDebug() << up << down;
    int uidTemp = (int)up * 8 + (int)down;
    QString uid = QString::number(uidTemp);
    if(m_data.contains(uid)){
        return m_data[uid].yaoci[index];
    }
    else{
        return "";
    }
}
