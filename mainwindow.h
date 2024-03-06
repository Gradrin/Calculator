#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define M_PI 3.14159265358979323846

#include<QPushButton>
#include <QMainWindow>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <iomanip>
#include"resources.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::string & changing_Pi_and_E(std::string& operation);
    void advancedContinued(float & variable, int & calculation);
    void advanced(std::string& operation, std::string& text, int & lenght, bool& function,int & stringSize,int & calculation);
    unsigned long long factorialCalculated(int n, int number);
    void factorials(std::string& operation, std::string& text, int& lenght, int& number, bool& function, int& stringSize);
    std::string calculation(const char* x);
    std::string brackets(std::string& operation);

private slots:

    //Constructor
    void variables();
    void icons();
    void ShowPage(int index);
    void addButtons();

    void clickButtons(std::string number);
    void clickButtonsConventer(std::string number);
    void connectButtons();

    //Buttons ConventerType

    void on_buttonCalculator_clicked();
    void on_buttonLenght_clicked();
    void on_buttnoWeight_clicked();
    void on_buttonPower_clicked();

    void addNumbers(std::string & number);



    //PLUS, MINUS, MULTIPICATION, DIVISION, EXPONENT
    void signChoice(std::string & signs);

    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

    void on_btnOne_2_clicked();

    void on_btnDivide_clicked();

    void on_pbtnExponent_clicked();

    void on_btnExponentMinus_clicked();

    void on_pbtnExponent2_clicked();

    void on_btnEqual_clicked();



    void on_btnAC_clicked();

    void on_btnDeleteSign_clicked();

    void on_btnDot_clicked();

    void on_btnFactorial_clicked();




    void on_btnOpenBracket_clicked();

    void on_btnCloseBracket_clicked();

    //FUNCTIONS VOIDS
    void mathematicFunctions(std::string & function);

    void on_btnSin_clicked();

    void on_btnCos_clicked();

    void on_btnTan_clicked();

    void on_btnLog_clicked();

    void on_btnLn_clicked();

    void on_btnSqrt_clicked();

    void on_btnArcSin_clicked();

    void on_btnArcCos_clicked();

    void on_btnArcTan_clicked();

    //PI AND EULER'S NUMBER

    void on_btnPi_clicked();

    void on_btnE_clicked();


    void on_btnRadDeg_clicked();

    //CONTENER

    void conventer();

    void on_BoxList_activated(int index);

    void on_btn2_DeleteSign_clicked();

    void on_btn2_AC_clicked();

    void on_btnDeleteHistory_clicked();

private:
    Ui::MainWindow *ui;
    //int number;

    std::string number;
    std::string operation;
    std::string equal;

    std::vector< int >numbers;

    enum sizeButton {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SIZE};


    QPushButton* buttons[SIZE];
    QPushButton* buttonsConventer[SIZE];

    int bracket;
    int measure;
    int units;

};
#endif // MAINWINDOW_H
