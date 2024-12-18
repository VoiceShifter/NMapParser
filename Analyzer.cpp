#include "Analyzer.hpp"
# include <sstream>


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
    // Worker = std::thread([&]{
    //     for (size_t Index{0}; Index < 200; ++Index)
    //     {
    //         Tokens[Index].reserve(5);;
    //     }
    // });
}

void Analyzer::SetFile() noexcept
{

}

void Analyzer::Analyze()
{
    std::string Buffer{};
    ShownLines.reserve(250);

    bool Switch{};
    for(size_t Index{};std::getline(pFile, Buffer);)
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

            ShownLines.append(Buffer.substr(7).c_str());
            char const * Delim = "( ) (*) \t | ";
            char * Token {std::strtok(const_cast<char*>(Buffer.c_str()), Delim)};
            Tokens.resize(Index + 1);
            for (;Token!=nullptr;)
            {
                qDebug() << Token;
                if (*Token == '_')
                {
                    Token=std::strtok(nullptr, Delim);
                    continue;
                }
                Tokens[Index].push_back(Token);
                Token=std::strtok(nullptr, Delim);
            }
            ++Index;

        }

    }
    qDebug() << Tokens.size() << " - Tokens size";
    emit ShownLinesChanged();
}

void Analyzer::mFilter(QString Filter)
{
    float lFilter;
    try {
        lFilter = std::stof(Filter.toStdString());
    } catch (...)
    {
        qDebug() << "Enter something normal";
        return;
    }
    ShownLines.clear();
    std::stringstream NewString{};
    for (size_t Index{}; Index < Tokens.size(); ++Index)
    {

        try {
            if(std::stof((Tokens[Index][1])) >= lFilter)
            {
                for (size_t iIndex{}; iIndex < Tokens[Index].size(); ++iIndex)
                    NewString << Tokens[Index][iIndex] << '\t';
                ShownLines.append(NewString.str().c_str());
                NewString.str("");
            }
        } catch (...)
        {
            for (const auto& Iterator : Tokens[Index])
                qDebug() << Iterator << " - broken line";
            qDebug() << Index << " - broken index";
            return;
        }


    }
    emit ShownLinesChanged();
}

void Analyzer::mReset()
{
    mFilter("0");
}
