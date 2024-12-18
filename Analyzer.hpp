# ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <QObject>
# include <QCommandLineParser>
# include <fstream>
# include <string>
# include <vector>
# include <thread>
class Analyzer : public QObject
{
    Q_OBJECT
    QCommandLineParser pParser{};
    std::fstream pFile;
    QStringList ShownLines;
public:
    explicit Analyzer(QObject *parent = nullptr);
    void SetFile() noexcept;
    void Analyze();
    void setShownLines(const QStringList &newShownLines);
    std::thread Worker{};

    std::vector<std::vector<std::string>> Tokens{};
    QStringList getShownLines() const;


    Q_INVOKABLE void mFilter(QString Filter);
    Q_INVOKABLE void mReset();
signals:
    void ShownLinesChanged();
private:
    Q_PROPERTY(QStringList pLines READ getShownLines WRITE setShownLines NOTIFY ShownLinesChanged FINAL)
};

#endif // ANALYZER_HPP
