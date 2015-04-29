#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylistwidget.h"
#include "vm.h"
#include <stdlib.h>
#include <string>
#include <QListWidget>
#include <QLayout>
#include <QProcess>
#include <QDebug>
#include <QWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextBrowser>
#include <QGroupBox>
#include <QSize>
#include <QIcon>
#include <QPixmap>
#include <QBitmap>
#include <QStyle>
#include <QFormLayout>
#include <QVector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/images/VirtualPool.png"));
    testLabel = new QLabel();
    testLabel2 = new QLabel();
    testLabel3 = new QLabel();
    button_new = createToolButton(QIcon(":/new/prefix1/images/new.png"), tr("新建"));
    button_start = createToolButton(QIcon(":/new/prefix1/images/right.png"), tr("启动"));
    button_delete = createToolButton(QIcon(":/new/prefix1/images/delete.png"), tr("删除"));
    button_login = createToolButton(QIcon(":/new/prefix1/images/login.png"), tr("远程登录"));
    button_test = createToolButton(QIcon(":/new/prefix1/images/network.png"), tr("网络体检"));

    QGroupBox *vmInfo = new QGroupBox(tr("配置信息"));
    QGroupBox *vmList = new QGroupBox(tr("虚拟机池"));
    processBar = new CRoundProcessBar(this);

    nameEdit = new QLineEdit();
    ostypeEdit = new QLineEdit();
    cpuEdit = new QLineEdit();
    memoryEdit = new QLineEdit();
    vramEdit = new QLineEdit();
    bootEdit = new QLineEdit();
    diskTypeEdit = new QLineEdit();
    diskSpaceEdit = new QLineEdit();
    networkEdit = new QLineEdit();
    ipEdit = new QLineEdit();
    netmaskEdit = new QLineEdit();
    testEdit = new QLineEdit();

    memorySpinBox = new QSpinBox();
    memorySlider = new QSlider(Qt::Horizontal);
    memorySlider->setTickPosition(QSlider::TicksBelow);
    memorySlider->setTickInterval(100);

    /* 以下为layout部分 */

    QHBoxLayout *headLayout = new QHBoxLayout;
    QVBoxLayout *resultLayout = new QVBoxLayout;

    headLayout->addWidget(button_new);
    headLayout->addWidget(button_start);
    headLayout->addWidget(button_delete);
    headLayout->addWidget(button_login);
    headLayout->addWidget(button_test);
    headLayout->addWidget(processBar);
    headLayout->addLayout(resultLayout);

    resultLayout->addWidget(testLabel);
    resultLayout->addWidget(testLabel2);
    resultLayout->addWidget(testLabel3);
    resultLayout->setSpacing(0);

    headLayout->setAlignment(Qt::AlignLeft);

    QHBoxLayout* memoryLayout = new QHBoxLayout;
    QLabel* memoryLabel = new QLabel(tr("内存"));
    memoryLabel->setMinimumWidth(78);
    memoryLayout->addWidget(memoryLabel);
    memoryLayout->addWidget(memorySpinBox);
    memoryLayout->addWidget(memorySlider);

    QFormLayout *infoLayout = new QFormLayout;
    vmInfo->setLayout(infoLayout);
    infoLayout->addRow(tr("名称"), nameEdit);
    infoLayout->addRow(tr("操作系统"), ostypeEdit);
    infoLayout->addRow(tr("CPU核数"), cpuEdit);
    infoLayout->addRow(memoryLayout);
    infoLayout->addRow(tr("虚拟磁盘格式"), diskTypeEdit);
    infoLayout->addRow(tr("磁盘剩余容量"), diskSpaceEdit);
    infoLayout->addRow(tr("网络连接方式"), networkEdit);
    infoLayout->addRow(tr("IP地址"), ipEdit);
    infoLayout->addRow(tr("子网掩码"), netmaskEdit);
    infoLayout->addRow(tr("显存"), vramEdit);
    infoLayout->addRow(tr("启动顺序"), bootEdit);
    processBar->setScanValue("0");


    infoLayout->setVerticalSpacing(15);

    QVBoxLayout *vms = new QVBoxLayout;
    vms->addWidget(listWidget);
    vmList->setLayout(vms);
    vmList->setMaximumWidth(200);
    QHBoxLayout *bodyLayout = new QHBoxLayout;
    bodyLayout->addWidget(vmList);
    bodyLayout->addWidget(vmInfo);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(headLayout);
    mainLayout->addLayout(bodyLayout);

    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

//    if(listWidget->count() > 0)
//        on_item_clicked(listWidget->item(0));
    /* UI部分 */
    this->setStyleSheet("QLineEdit{background: rgb(240,240,240);selection-background-color: darkgrey; padding:0px; margin:0px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QToolButton* MainWindow::createToolButton(QIcon buttonIcon, QString buttonName) //初始化顶部按钮
{
    QToolButton* toolButton;
    toolButton = new QToolButton(this);
    toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolButton->setIcon(buttonIcon);
    toolButton->setIconSize(QSize(50,50));
    toolButton->setText(buttonName);
    toolButton->setMinimumWidth(65);
    toolButton->setAutoRaise(true);
    return toolButton;
}
