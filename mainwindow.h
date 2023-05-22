#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QTimer>
#include <random>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void onButtonsClicked(QAbstractButton *button);

    void on_newGame_clicked();

private:
    QButtonGroup *buttons;
    QButtonGroup *buttongroup;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
