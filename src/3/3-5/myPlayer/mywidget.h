#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <Phonon>
class QLabel;
class MyPlaylist;
// 在3-4中添加的代码
class MyLrc;
// 在3-5中添加的代码
#include <QSystemTrayIcon>

namespace Ui {
    class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void updateTime(qint64 time);
    void setPaused();
    void skipBackward();
    void skipForward();
    void openFile();
    void setPlaylistShown();
    void setLrcShown();

    // 在3-2中添加的代码
    void stateChanged(Phonon::State newState, Phonon::State oldState);

    // 在3-3中添加的代码
    void sourceChanged(const Phonon::MediaSource &source);
    void aboutToFinish();
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
    void tableClicked(int row);
    void clearSources();

    // 在3-5中添加的代码
    void trayIconActivated(QSystemTrayIcon::ActivationReason activationReason);

// 在3-5中添加的代码
protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MyWidget *ui;
    void initPlayer();
    Phonon::MediaObject *mediaObject;
    QAction *playAction;
    QAction *stopAction;
    QAction *skipBackwardAction;
    QAction *skipForwardAction;
    QLabel *topLabel;
    QLabel *timeLabel;

    // 在3-3中添加的代码
    MyPlaylist *playlist;
    Phonon::MediaObject *metaInformationResolver;
    QList<Phonon::MediaSource> sources;
    void changeActionState();

    // 在3-4中添加的代码
    MyLrc *lrc;
    QMap<qint64, QString> lrcMap;
    void resolveLrc(const QString &sourceFileName);

    // 在3-5中添加的代码
    QSystemTrayIcon *trayIcon;
};

#endif // MYWIDGET_H
