#ifndef COUNTER_H
#define COUNTER_H

#include <QMainWindow>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class Counter; }
QT_END_NAMESPACE

class Counter : public QMainWindow
{
    Q_OBJECT

public:
    Counter(QWidget *parent = nullptr);
    ~Counter();

private slots:
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_clearButton_clicked();
    void on_dateTimeButton_clicked();

    void on_lcdNumber_overflow();

private:
    Ui::Counter *ui;
    int counterValue;
};

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);

private slots:
    void updateTimeDisplay();

private:
    QTimer *m_timer;
    QLCDNumber *m_lcdNumber;
};


#endif // COUNTER_H
