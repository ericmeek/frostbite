#ifndef LICHCONNECT_H
#define LICHCONNECT_H

#include <QDialog>

#include <mainwindow.h>

namespace Ui {
class LichConnect;
}

class LichConnect : public QDialog
{
    Q_OBJECT

public:
    explicit LichConnect(QWidget *parent = 0);
    ~LichConnect();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LichConnect *ui;

    MainWindow* mainWindow;

    void init();
    void showEvent(QShowEvent *);

signals:
    void connectToLich(QString, QString);
};

#endif // LICHCONNECT_H
