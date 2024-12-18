# include "Analyzer.hpp"

QStringList Analyzer::getShownLines() const
{
    return ShownLines;
}



void Analyzer::setShownLines(const QStringList &newShownLines)
{
    if (ShownLines == newShownLines)
        return;
    ShownLines = newShownLines;
    emit ShownLinesChanged();
}
