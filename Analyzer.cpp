#include "Analyzer.hpp"

Analyzer::Analyzer(QObject *parent)
    : QObject{parent}
{


}

void Analyzer::SetFile() noexcept
{
    pParser.addPositionalArgument("Filename", "Name of the file for analyzing");
    pFile.open(pParser.value("Filename").toStdString(), std::ios_base::in);
}

void Analyzer::Analyze()
{
    std::string Buffer{};
    pLines.reserve(250);
    for(;std::getline(pFile, Buffer);)
    {
        pLines.append(Buffer.c_str());
    }

}
