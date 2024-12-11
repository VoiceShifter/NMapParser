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
signals:
};

#endif // ANALYZER_HPP
