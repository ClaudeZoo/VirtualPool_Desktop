#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtoolButton>
#include <QToolButton>
#include <QProcess>
#include <QtCore>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QList>
#include <QSpinBox>
#include <QSlider>
#include <QMap>
#include <QTextEdit>
#include <QDir>
#include "mylistwidget.h"
#include "vm.h"
#include "croundprocessbar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QToolButton* createToolButton(QIcon buttonIcon, QString buttonName);

signals:
    void outlogtext(QString ver);


private slots:


private:
    Ui::MainWindow *ui;
    QList<VM> VMs;
    QDir dir;
    QString currentItem, currentState;
    int currentMemory;
    const QString vboxDir = "C:\\\\Progra~1\\\\Oracle\\\\VirtualBox\\\\VBoxManage.exe";
    QString vmName, vmID;
    MyListWidget *listWidget;
    QToolButton *button_new, *button_start, *button_delete, *button_test, *button_login;
    QLabel *testLabel, *testLabel2, *testLabel3;

    QLineEdit *nameEdit, *ostypeEdit, *cpuEdit, *memoryEdit, *vramEdit, *bootEdit, *diskTypeEdit, *diskSpaceEdit, *networkEdit, *ipEdit, *netmaskEdit;
    QMap<QString, int> netTest;

    QSpinBox* memorySpinBox;
    QSlider* memorySlider;

    QProcess *myprocess;
    CRoundProcessBar *processBar;
};

#endif // MAINWINDOW_H
