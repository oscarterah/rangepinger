#include "appwrapper.h"
#include <QDebug>

AppWrapper::AppWrapper(QObject *parent) : QObject(parent)
{

}

bool AppWrapper::initializer()
{

    felgo.initialize(&mEngine);
    mEngine.rootContext()->setContextProperty("Wrapper", this);

    resetModel();

    mEngine.load(QUrl(QStringLiteral("qml/Main.qml")));

    if (mEngine.rootObjects().isEmpty()){
        return false;
    }else{
        return true;
    }

}


QString AppWrapper::userinput_i()
{
    return m_userinput_i;
}

QString AppWrapper::userinput_j()
{
    return m_userinput_j;
}

QString AppWrapper::userinput_k()
{
    return m_userinput_k;
}


void AppWrapper::setUserinput_i(const QString &userinput_i)
{
    if(userinput_i == m_userinput_i)
    {
        return;
    }

    m_userinput_i = userinput_i;

    emit userinput_iChanged();
}

void AppWrapper::setUserinput_j(const QString &userinput_j)
{

    if(userinput_j == m_userinput_j)
    {
        return;
    }

    m_userinput_j = userinput_j;


    emit userinput_jChanged();


}

void AppWrapper::setUserinput_k(const QString &userinput_k)
{


    if(userinput_k == m_userinput_k)
    {
        return;
    }

    m_userinput_k = userinput_k;

    emit userinput_kChanged();


}


QString AppWrapper::userinput_i_f()
{
    return m_userinput_i_f;
}

QString AppWrapper::userinput_j_f()
{
    return m_userinput_j_f;
}

QString AppWrapper::userinput_k_f()
{
    return m_userinput_k_f;
}


void AppWrapper::setUserinput_i_f(const QString &userinput_i_f)
{
    if(userinput_i_f == m_userinput_i_f)
    {
        return;
    }

    m_userinput_i_f = userinput_i_f;

    emit userinput_i_fChanged();
}

void AppWrapper::setUserinput_j_f(const QString &userinput_j_f)
{

    if(userinput_j_f == m_userinput_j_f)
    {
        return;
    }

    m_userinput_j_f = userinput_j_f;


    emit userinput_j_fChanged();


}

void AppWrapper::setUserinput_k_f(const QString &userinput_k_f)
{


    if(userinput_k_f == m_userinput_k_f)
    {
        return;
    }

    m_userinput_k_f = userinput_k_f;

    emit userinput_k_fChanged();


}

void AppWrapper::looper(QString &m_userinput_i, QString &m_userinput_j, QString &m_userinput_k)
{
    int stpi = m_userinput_i.toInt();
    int stpj = m_userinput_j.toInt();
    int stpk = m_userinput_k.toInt();


    int stpif = m_userinput_i_f.toInt();
    int stpjf = m_userinput_j_f.toInt();
    int stpkf = m_userinput_k_f.toInt();
    for(int i=stpif; i < stpi+1; i++)
    {
        for(int j=stpjf; j < stpj+1; j++)
        {
            for(int k=stpkf; k < stpk+1; k++)
            {
                m_values = "104."+QString::number(i)+"."+QString::number(j)+"."+QString::number(k);

                QString pinger = "ping -c1 -s1 -w 1 -i 0.1 "+m_values+" > /dev/null 2>&1";

                std::string pingerstr = pinger.toStdString();
                const char* p = pingerstr.c_str();

                int x = std::system(p);
                if (x==0){
                    results.append(m_values+" Success");

                }else{
                    results.append(m_values+" failed");

                }
            }
        }
    }
    resetModel();
}


void AppWrapper::loopresult()
{
    looper(m_userinput_i, m_userinput_j, m_userinput_k);
}
QStringList AppWrapper::resultvector()
{
    return results;
}


void AppWrapper::startCppTask() {

    loopresult();
}

void AppWrapper::stopapp(){
//    QObject::connect(mEngine, &QQmlApplicationEngine::quit, &QApplication::quit);
    qDebug()<<"stop";
}

void AppWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("myModel",QVariant::fromValue(results));
}
