#include "mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), m_seconds(0)
{
    setWindowTitle("Timer Example");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Elapsed Time:", centralWidget);
    layout->addWidget(label);

    m_timeLabel = new QLabel("0", centralWidget);
    m_timeLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    layout->addWidget(m_timeLabel);

    QLabel *hourLabel = new QLabel("Hour:", centralWidget);
    layout->addWidget(hourLabel);

    m_hourLabel = new QLabel("0", centralWidget);
    m_hourLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    layout->addWidget(m_hourLabel);

    QLabel *minLabel = new QLabel("Min:", centralWidget);
    layout->addWidget(minLabel);

    m_minLabel = new QLabel("0", centralWidget);
    m_minLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    layout->addWidget(m_minLabel);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    m_timer->start(1000); // 1 second interval
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateTimer() {
    m_seconds++;
    int hours = m_seconds / 3600;
    int minutes = (m_seconds % 3600) / 60;
    int seconds = m_seconds % 60;
    m_timeLabel->setText(QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    m_hourLabel->setText(QString::number(hours));
    m_minLabel->setText(QString::number(minutes));
}
