#ifndef ROUNDTIMEDISPLAY_H
#define ROUNDTIMEDISPLAY_H

#include <mainwindow.h>
#include <gamedatacontainer.h>

class MainWindow;
class GameDataContainer;

class RoundTimeDisplay : public QObject {
    Q_OBJECT

public:
    RoundTimeDisplay(QObject *parent);
    ~RoundTimeDisplay();

    void repaint();
    QTimer *timer;

private:
    MainWindow* mainWindow;
    GameDataContainer* gameDataContainer;
    int time;    

    void paint(int);
    QPixmap segmentDisplay(int seconds);
    QPixmap numericDisplay(int seconds);

    QColor getColor();

    GeneralSettings* settings;
    QColor color;

public slots:
    void setTimer(int seconds);

private slots:
    void intervalEvent();
    void reloadSettings();
};

#endif // ROUNDTIMEDISPLAY_H
