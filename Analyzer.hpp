# ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <QObject>
# include <QCommandLineParser>
# include <fstream>
# include <string>
# include <vector>
class Analyzer : public QObject
{
    Q_OBJECT
    QCommandLineParser pParser{};
    std::fstream pFile;
    QStringList pLines;
public:
    explicit Analyzer(QObject *parent = nullptr);
    void SetFile() noexcept;
    void Analyze();
    QStringList getPLines() const;
    void setPLines(const QStringList &newPLines);

signals:
    void pLinesChanged();
private:
    Q_PROPERTY(QStringList pLines READ getPLines WRITE setPLines NOTIFY pLinesChanged FINAL)
};

#endif // ANALYZER_HPP
