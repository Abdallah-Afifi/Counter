#include "counter.h"
#include "ui_counter.h"
#include <QDateTime>
#include <QTimer>
#include <QLCDNumber>


Counter::Counter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Counter)
{
    ui->setupUi(this);
    counterValue = 0;
    ui->counterLabel->setText(QString::number(counterValue));
}

Counter::~Counter()
{
    delete ui;
}

void Counter::on_plusButton_clicked()
{
    counterValue++;
    ui->counterLabel->setText(QString::number(counterValue));
}

void Counter::on_minusButton_clicked()
{
    counterValue--;
    ui->counterLabel->setText(QString::number(counterValue));
}

void Counter::on_clearButton_clicked()
{
    counterValue = 0;
    ui->counterLabel->setText(QString::number(counterValue));
}

void Counter::on_dateTimeButton_clicked()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeLabel->setText(currentDateTimeString);
}

void Counter::on_lcdNumber_overflow()
{

}
void MyWidget::updateTimeDisplay()
{
    QDateTime now = QDateTime::currentDateTime();
    m_lcdNumber->display(now.toString("hh:mm:ss"));
}
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    m_lcdNumber = new QLCDNumber(this);
    m_lcdNumber->setDigitCount(8); // Display format: hh:mm:ss
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MyWidget::updateTimeDisplay);
    m_timer->start(1000); // Update every 1 second
}

