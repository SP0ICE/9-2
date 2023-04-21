#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *m_timeLabel;
    QLabel *m_hourLabel;
    QLabel *m_minLabel;
    int m_seconds;
    QTimer *m_timer;

    void updateTimer();

};

#endif // MAINWINDOW_H

