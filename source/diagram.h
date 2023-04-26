#ifndef DEFINES_H
#define DEFINES_H
#include <QString>
#include "yao.h"

/**
 * @brief 八卦
 */
enum Diagram8{
    Kun  = 0,   //坤|地-0
    Gen  = 1,   //艮|山-1
    Kan  = 2,   //坎|水-2
    Xun  = 3,   //巽|风-3
    Zhen = 4,   //震|雷-4
    Li   = 5,   //离|火-5
    Dui  = 6,   //兑|泽-6
    Qian = 7,   //乾|天-7
};

//enum Diagram8{
//    Kun  = 0x000,   //坤|地-0
//    Gen  = 0x001,   //艮|山-1
//    Kan  = 0x010,   //坎|水-2
//    Xun  = 0x011,   //巽|风-3
//    Zhen = 0x100,   //震|雷-4
//    Li   = 0x101,   //离|火-5
//    Dui  = 0x110,   //兑|泽-6
//    Qian = 0x111,   //乾|天-7
//};
/**
 * @brief 64卦
 */
class Diagram : public QObject{
    Q_OBJECT
public:
    explicit Diagram();

    void change(Diagram8 up, Diagram8 down);
    void change(const QString& code);
    QString name();

    Yao *getYao(int index);

private slots:
    void onYaoChanged(int index, bool broken);


private:
    void internalUpdate();

signals:
    void diagramChanged();

private:
    Diagram8 m_up;
    Diagram8 m_down;

    QVector<int> m_data;//1-阳 0-阴

    QVector<Yao*> m_yaos;
};


#endif // DEFINES_H
