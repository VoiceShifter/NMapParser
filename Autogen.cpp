# include "Analyzer.hpp"

QStringList Analyzer::getPLines() const
{
    return pLines;
}

void Analyzer::setPLines(const QStringList &newPLines)
{
    if (pLines == newPLines)
        return;
    pLines = newPLines;
    emit pLinesChanged();
}
