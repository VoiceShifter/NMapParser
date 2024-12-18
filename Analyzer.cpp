#include "Analyzer.hpp"



Analyzer::Analyzer(QObject *parent)
    : QObject{parent}
{
    const QStringList Arguments = QCoreApplication::arguments();
    qDebug()<< Arguments[1].toStdString();
    pFile.open(Arguments[1].toStdString(), std::ios::in);
    if (!pFile)
    {
        qDebug() << "Cant open file\n";
    }
    else
    {
        qDebug() << "Opened file\n";
        Analyze();
    }
}

void Analyzer::SetFile() noexcept
{

}

void Analyzer::Analyze()
{
    std::string Buffer{};
    pLines.reserve(250);
    bool Switch{};
    for(;std::getline(pFile, Buffer);)
    {
        if (Buffer.substr(0, 7) == "|   cpe")
        {
            Switch = 1;
            continue;
        }
        else if (Buffer[0] != '|')
        {
            Switch = 0;
            continue;
        }
        if (Switch)
        {
            pLines.append(Buffer.substr(7).c_str());
            qDebug() << Buffer << '\n';
        }
    }
    emit pLinesChanged();
}
