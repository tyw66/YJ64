#include "diagram.h"
#include "database.h"
#include <QDebug>

Diagram::Diagram()
{
    //从上到下
    Yao *line1 = new Yao(-200,-170);
    Yao *line2 = new Yao(-200,-110);
    Yao *line3 = new Yao(-200,-50);
    Yao *line4 = new Yao(-200,10);
    Yao *line5 = new Yao(-200,70);
    Yao *line6 = new Yao(-200,130);

    m_yaos.push_back(line1);
    m_yaos.push_back(line2);
    m_yaos.push_back(line3);
    m_yaos.push_back(line4);
    m_yaos.push_back(line5);
    m_yaos.push_back(line6);

    for(int i = 0; i < m_yaos.size();i++){
        m_yaos[i]->setIndex(i);
        connect(m_yaos[i],SIGNAL(yaoChanged(int,bool)),
                this,SLOT(onYaoChanged(int,bool)));

        m_data.push_back(1);
    }

    change(Qian,Qian);
}

void Diagram::change(Diagram8 up, Diagram8 down)
{
    m_up = up;
    m_down = down;

    switch (up) {
    case Kun:{
        m_yaos[0]->setBroken(true);
        m_yaos[1]->setBroken(true);
        m_yaos[2]->setBroken(true);
        break;
    }
    case Gen:{
        m_yaos[0]->setBroken(false);
        m_yaos[1]->setBroken(true);
        m_yaos[2]->setBroken(true);
        break;
    }
    case Kan:{
        m_yaos[0]->setBroken(true);
        m_yaos[1]->setBroken(false);
        m_yaos[2]->setBroken(true);
        break;
    }
    case Xun:{
        m_yaos[0]->setBroken(false);
        m_yaos[1]->setBroken(false);
        m_yaos[2]->setBroken(true);
        break;
    }
    case Zhen:{
        m_yaos[0]->setBroken(true);
        m_yaos[1]->setBroken(true);
        m_yaos[2]->setBroken(false);
        break;
    }
    case Li:{
        m_yaos[0]->setBroken(false);
        m_yaos[1]->setBroken(true);
        m_yaos[2]->setBroken(false);
        break;
    }
    case Dui:{
        m_yaos[0]->setBroken(true);
        m_yaos[1]->setBroken(false);
        m_yaos[2]->setBroken(false);
        break;
    }
    case Qian:{
        m_yaos[0]->setBroken(false);
        m_yaos[1]->setBroken(false);
        m_yaos[2]->setBroken(false);
        break;
    }
    default:break;
    }

    switch (down) {
    case Kun:{
        m_yaos[3]->setBroken(false);
        m_yaos[4]->setBroken(true);
        m_yaos[5]->setBroken(true);
        break;
    }
    case Kan:{
        m_yaos[3]->setBroken(true);
        m_yaos[4]->setBroken(false);
        m_yaos[5]->setBroken(true);
        break;
    }
    case Xun:{
        m_yaos[3]->setBroken(false);
        m_yaos[4]->setBroken(false);
        m_yaos[5]->setBroken(true);
        break;
    }
    case Zhen:{
        m_yaos[3]->setBroken(true);
        m_yaos[4]->setBroken(true);
        m_yaos[5]->setBroken(false);
        break;
    }
    case Li:{
        m_yaos[3]->setBroken(false);
        m_yaos[4]->setBroken(true);
        m_yaos[5]->setBroken(false);
        break;
    }
    case Dui:{
        m_yaos[3]->setBroken(true);
        m_yaos[4]->setBroken(false);
        m_yaos[5]->setBroken(false);
        break;
    }
    case Qian:{
        m_yaos[3]->setBroken(false);
        m_yaos[4]->setBroken(false);
        m_yaos[5]->setBroken(false);
        break;
    }
    default:break;
    }
}

void Diagram::change(const QString &code)
{
    QStringList list = code.split(',',QString::SkipEmptyParts);
    if(list.size() != 6){
        return;
    }
    for(int i = 0; i < 6; ++i){
        bool broken = (list[i] == 0);
        m_data[i] = broken?0:1;
    }

    internalUpdate();
}

QString Diagram::name()
{
    QString name = Database::inst()->queryDiagramName(m_up,m_down);
    return name + "卦";
}

Yao* Diagram::getYao(int index)
{
    if(index < 0){
        index = 0;
    }
    else if(index > 5){
        index = 5;
    }
    return m_yaos[index];
}

void Diagram::onYaoChanged(int index, bool broken)
{
    m_data[index] = broken?0:1;
    internalUpdate();
    emit diagramChanged();
}

//用m_data更新m_up和m_down
void Diagram::internalUpdate()
{
    QString strUp,strDown;
    for(int i = 0; i < 3; ++i){
        strUp.append(QString::number(m_data[i]));
    }
    for(int i = 3; i < 6; ++i){
        strDown.append(QString::number(m_data[i]));
    }

    if(strUp == "000"){ m_up = Kun;}
    else if(strUp == "001"){m_up = Gen;}
    else if(strUp == "010"){m_up = Kan;}
    else if(strUp == "011"){m_up = Xun;}
    else if(strUp == "100"){m_up = Zhen;}
    else if(strUp == "101"){m_up = Li;}
    else if(strUp == "110"){m_up = Dui;}
    else if(strUp == "111"){m_up = Qian;}


    if(strDown == "000"){m_down = Kun;}
    else if(strDown == "001"){m_down = Gen;}
    else if(strDown == "010"){m_down = Kan;}
    else if(strDown == "011"){m_down = Xun;}
    else if(strDown == "100"){m_down = Zhen;}
    else if(strDown == "101"){m_down = Li;}
    else if(strDown == "110"){m_down = Dui;}
    else if(strDown == "111"){m_down = Qian;}

}




