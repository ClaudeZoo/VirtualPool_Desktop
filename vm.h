#ifndef VM_H
#define VM_H
#include <QString>
#include <QProcess>
#include <QObject>

class VM: public QObject
{
    Q_OBJECT

public:
    VM(QString uuid)
    {
        QString vmInfo = runCmd(QStringList()<<"vboxmanage"<<"showvminfo"<<uuid);
        vmName = getRegex(vmInfo, *(new QRegExp("name=\"(.*)\"")), true);

    }

    ~VM();

    void getVMInfo(QString uuid);
    void getVMnetwork(QString uuid);
    QString getVMName()
    {
        return vmName;
    }
    int getVmMemory()
    {
        return memory;
    }

private:
    QProcess* cmdProcess;
    QString vmName, vmId, state, osType, diskType, nicType;
    QString boot[3];
    int cpuNum, memory, vram;
    double diskSize, diskSpace;
    int ip[4], netmask[4];

    QString runCmd(QStringList command) //调用cmd
    {

        QProcess* process = new QProcess();
        process->start("bash", command);
        QByteArray buffer;
        process->waitForFinished();
        buffer.append(process->readAll());
        return buffer;
    }

    QString getRegex(QString text, QRegExp reg, bool isSetMinimal) //获取正则匹配结果
    {
        if(isSetMinimal)
            reg.setMinimal(true);
        int pos = reg.indexIn(text);
        return reg.cap(1);
    }
};

#endif // VM_H
