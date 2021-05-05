#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <FelgoApplication>
#include <QQmlContext>
#include <QString>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include <QTimer>

class AppWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString userinput_i READ userinput_i WRITE setUserinput_i NOTIFY userinput_iChanged)
    Q_PROPERTY(QString userinput_j READ userinput_j WRITE setUserinput_j NOTIFY userinput_jChanged)
    Q_PROPERTY(QString userinput_k READ userinput_k WRITE setUserinput_k NOTIFY userinput_kChanged)
    Q_PROPERTY(QString userinput_i_f READ userinput_i_f WRITE setUserinput_i_f NOTIFY userinput_i_fChanged)
    Q_PROPERTY(QString userinput_j_f READ userinput_j_f WRITE setUserinput_j_f NOTIFY userinput_j_fChanged)
    Q_PROPERTY(QString userinput_k_f READ userinput_k_f WRITE setUserinput_k_f NOTIFY userinput_k_fChanged)

public:
    explicit AppWrapper(QObject *parent = nullptr);

    FelgoApplication felgo;
    QQmlApplicationEngine mEngine;
    bool initializer();


    QString userinput_i();

    QString userinput_j();

    QString userinput_k();

    void setUserinput_i(const QString &userinput_i);

    void setUserinput_j(const QString &userinput_j);

    void setUserinput_k(const QString &userinput_k);


    QString userinput_i_f();

    QString userinput_j_f();

    QString userinput_k_f();

    void setUserinput_i_f(const QString &userinput_i_f);

    void setUserinput_j_f(const QString &userinput_j_f);

    void setUserinput_k_f(const QString &userinput_k_f);
    void loopresult();

    QStringList results {" "," "," "};

    QStringList resultvector();

    void resetModel();

    QPushButton *button = new QPushButton;

    Q_INVOKABLE void startCppTask();
    Q_INVOKABLE void stopapp();

public slots:
    void looper(QString &m_userinput_i, QString &m_userinput_j, QString &m_userinput_k);


signals:

    void userinput_iChanged();

    void userinput_jChanged();

    void userinput_kChanged();

    void userinput_i_fChanged();

    void userinput_j_fChanged();

    void userinput_k_fChanged();
private:
    QString m_userinput_i;
    QString m_userinput_j;
    QString m_userinput_k;


    QString m_userinput_i_f;
    QString m_userinput_j_f;
    QString m_userinput_k_f;
    QString m_values;


};

#endif // APPWRAPPER_H
