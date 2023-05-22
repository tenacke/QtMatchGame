#include "mainwindow.h"
#include "./ui_mainwindow.h"


using namespace std;

int counter = 0;
int score = 0;
int state = 0;
int remaining = 50;
bool isActive = true;
QPushButton *openButton;

QString names[30] = {"Bahadır Gezer", "Can Özturan", "Gökçe Uludoğan", "Ö. Talip Akalın", "Emre Uğur",
                     "Utku Bozdoğan", "Suzan Ece Ada", "Tuna Tuğcu", "Yiğit Yıldırım", "Alper Şen",
                     "Emre Bilgili", "Alper Ahmetoğlu", "F. Başak Aydemir", "H. Birkan Yılmaz", "Özlem D. İncel",
                     "Bahadır Gezer", "Can Özturan", "Gökçe Uludoğan", "Ö. Talip Akalın", "Emre Uğur",
                     "Utku Bozdoğan", "Suzan Ece Ada", "Tuna Tuğcu", "Yiğit Yıldırım", "Alper Şen",
                     "Emre Bilgili", "Alper Ahmetoğlu", "F. Başak Aydemir", "H. Birkan Yılmaz", "Özlem D. İncel"};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buttons = new QButtonGroup(this);
    buttons->addButton(ui->pushButton1, 0);
    buttons->addButton(ui->pushButton1_2, 1);
    buttons->addButton(ui->pushButton1_3, 2);
    buttons->addButton(ui->pushButton1_4, 3);
    buttons->addButton(ui->pushButton1_5, 4);
    buttons->addButton(ui->pushButton1_6, 5);
    buttons->addButton(ui->pushButton1_7, 6);
    buttons->addButton(ui->pushButton1_8, 7);
    buttons->addButton(ui->pushButton1_9, 8);
    buttons->addButton(ui->pushButton1_10, 9);
    buttons->addButton(ui->pushButton1_11, 10);
    buttons->addButton(ui->pushButton1_12, 11);
    buttons->addButton(ui->pushButton1_13, 12);
    buttons->addButton(ui->pushButton1_14, 13);
    buttons->addButton(ui->pushButton1_15, 14);
    buttons->addButton(ui->pushButton1_16, 15);
    buttons->addButton(ui->pushButton1_17, 16);
    buttons->addButton(ui->pushButton1_18, 17);
    buttons->addButton(ui->pushButton1_19, 18);
    buttons->addButton(ui->pushButton1_20, 19);
    buttons->addButton(ui->pushButton1_21, 20);
    buttons->addButton(ui->pushButton1_22, 21);
    buttons->addButton(ui->pushButton1_23, 22);
    buttons->addButton(ui->pushButton1_24, 23);
    buttons->addButton(ui->pushButton1_25, 24);
    buttons->addButton(ui->pushButton1_26, 25);
    buttons->addButton(ui->pushButton1_27, 26);
    buttons->addButton(ui->pushButton1_28, 27);
    buttons->addButton(ui->pushButton1_29, 28);
    buttons->addButton(ui->pushButton1_30, 29);

    for (auto button : buttons->buttons()) {
        button->setStyleSheet("background-color: white;");
        button->setVisible(true);
        button->setText("");
        button->setEnabled(true);
    }

    connect(buttons, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), this, &MainWindow::onButtonsClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonsClicked(QAbstractButton *button)
{
    if (!isActive) return;
    QPushButton *myButton = qobject_cast<QPushButton*>(button); // Get the clicked button
    myButton->setEnabled(false);
    myButton->setStyleSheet("QPushButton:disabled { color: black; background-color: white;}");
    if (state == 0) {
        openButton = myButton;
        myButton->setText(names[buttons->id(myButton)]);
        if (myButton->text() == "Ö. Talip Akalın") {
            myButton->setStyleSheet("color: black; background-color: #ffc400;");
            myButton->setEnabled(true);
        }
        state = 1;
    }
    else {
        myButton->setText(names[buttons->id(myButton)]);

        if (myButton != openButton) {
            isActive = false;
            QTimer::singleShot(700, [=]() {
            if (openButton->text() == myButton->text()) {
                ui->label->setText("SCORE: "+ QString::number(++score));
                counter++;
                myButton->setText("");
                openButton->setText("");
                myButton->hide();
                openButton->hide();
            }
            else {
                myButton->setText("");
                openButton->setText("");
                myButton->setEnabled(true);
                openButton->setEnabled(true);
                myButton->setStyleSheet("background-color: white;");
                openButton->setStyleSheet("background-color: white;");

            }
            ui->label_2->setText("NUMBER OF TRIES REMAINING: "+ QString::number(--remaining));
            if (remaining == 0) {
                for (auto button : buttons->buttons()) {
                    button->setVisible(false);
                }
                ui->label_3->setText("Game Over");
            }
            if (counter == 15) {
                ui->label_3->setText("CONGRATULATIONS!!!!");
            }
            state = 0;
            isActive = true;
        });
        } else if (openButton->text() == "Ö. Talip Akalın") {
            ui->label->setText("SCORE: "+ QString::number(++score));
            myButton->setStyleSheet(" color: black; background-color: #ffc400;");
            myButton->setEnabled(true);
        }
    }
}

void MainWindow::on_newGame_clicked()
{   counter = 0;
    state = 0;
    score = 0;
    ui->label->setText("SCORE: 0");

    remaining = 50;
    ui->label_2->setText("NUMBER OF TRIES REMAINING: 50");

    ui->label_3->setText("");

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(names), std::end(names), g);

    for (auto button : buttons->buttons()) {
        button->setStyleSheet("background-color: white;");
        button->setVisible(true);
        button->setText("");
        button->setEnabled(true);
    }
}
