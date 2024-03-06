#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>

enum function { SQRT = 0, LG, LN, SIN, COS, TAN, ARCSIN, ARCCOS, ARCTAN  };
enum measure { LENGHT = 0, WEIGHT, POWER };
struct Units
{
    enum lenght { MM = 0, CM, DM, M, KM };
    enum weight { G = 0, DAG, HG, KG, };
    enum power { W = 0, KW, HP, SF, BTU };
};

bool error=false;
bool rad = false;
bool minuss = false;
bool condition = false;

void MainWindow::icons()
{
     ui->btnDeleteHistory->setIcon(QIcon(BASKET));
     ui->btnPi->setIcon(QIcon(PI));
     ui->btnE->setIcon(QIcon(EULER));
}

void MainWindow::variables()
{
     bracket=0;
}

void MainWindow::ShowPage(int index) {
     qDebug() << "show page request: " << index;
     ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::addButtons()
{
     buttons[0]=ui->btnZero;
     buttons[1]=ui->btnOne;
     buttons[2]=ui->btnTwo;
     buttons[3]=ui->btnThree;
     buttons[4]=ui->btnFour;
     buttons[5]=ui->btnFive;
     buttons[6]=ui->btnSix;
     buttons[7]=ui->btnSeven;
     buttons[8]=ui->btnEight;
     buttons[9]=ui->btnNine;

     buttonsConventer[0]=ui->btn2_Zero;
     buttonsConventer[1]=ui->btn2_One;
     buttonsConventer[2]=ui->btn2_Two;
     buttonsConventer[3]=ui->btn2_Three;
     buttonsConventer[4]=ui->btn2_Four;
     buttonsConventer[5]=ui->btn2_Five;
     buttonsConventer[6]=ui->btn2_Six;
     buttonsConventer[7]=ui->btn2_Seven;
     buttonsConventer[8]=ui->btn2_Eight;
     buttonsConventer[9]=ui->btn2_Nine;
}

void MainWindow::clickButtons(std::string number)
{
    addNumbers(number);
}

void MainWindow::clickButtonsConventer(std::string number)
{
    ui->line2_Edit->insert(QString::fromStdString(number));
    conventer();
}

void MainWindow::connectButtons()
{
     for(int i=0;i<SIZE;i++)
     {
         QObject::connect(buttons[i], &QPushButton::clicked, [i, this]() {
             clickButtons(std::to_string(i));
         });
     }
     for(int i=0;i<SIZE;i++)
     {
         QObject::connect(buttonsConventer[i], &QPushButton::clicked, [i, this]() {
             clickButtonsConventer(std::to_string(i));
         });
     }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentWidget(ui->page);
    ui->lineEdit->insert("0");
    icons();
    variables();
    addButtons();
    connectButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------NUMBERS---------------------

void MainWindow::on_buttonCalculator_clicked()
{
    ui->BoxList->clear();
   ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_buttonLenght_clicked()
{
     ui->BoxList->clear();
  ui->stackedWidget->setCurrentWidget(ui->page_2);
        ui->BoxList->setPlaceholderText("Lenght");
    ui->BoxList->addItem("milimeter");
    ui->BoxList->addItem("centimeter");
   ui->BoxList->addItem("decimeter");
    ui->BoxList->addItem("meter");
    ui->BoxList->addItem("kilometer");
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
    measure = LENGHT;

}


void MainWindow::on_buttnoWeight_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->page_2);
 ui->BoxList->clear();
        ui->BoxList->setPlaceholderText("Weight");
 ui->BoxList->addItem("gram");
 ui->BoxList->addItem("decagram");
 ui->BoxList->addItem("hectogram");
 ui->BoxList->addItem("kilogram");
 ui->line2_Edit->clear();
 ui->textEdit_2->clear();
measure = WEIGHT;

}


void MainWindow::on_buttonPower_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->page_2);
 ui->BoxList->clear();
        ui->BoxList->setPlaceholderText("Power");
 ui->BoxList->addItem("watt");
 ui->BoxList->addItem("kilowatt");
 ui->BoxList->addItem("kilojoule");
 ui->BoxList->addItem("horsepower");
 ui->BoxList->addItem("foot-pounds/minute");
 ui->BoxList->addItem("BTU/minute");
 ui->line2_Edit->clear();
 ui->textEdit_2->clear();
 measure = POWER;

}

void MainWindow::addNumbers(std::string & number)
{

 std::string operation = ui->lineEdit->text().toStdString();
 std::string signs="!)ep";

 if((operation.size()-1==0)&&(operation.c_str()[operation.size()-1]=='0'))
 {
     ui->lineEdit->backspace();
     ui->lineEdit->insert(QString::fromStdString(number));
 }
 else if (signs.find(operation.c_str()[operation.size()-1])== std::string::npos)
ui->lineEdit->insert(QString::fromStdString(number));
 else if (signs.find(operation.c_str()[operation.size()-1])!= std::string::npos)
 {
ui->lineEdit->insert("*");
ui->lineEdit->insert(QString::fromStdString(number));
 }
}


//----------------SIGNS---------------------

//PLUS, MINUS, MULTIPICATION, DIVISION, EXPONENT


void MainWindow::signChoice(std::string & signs)
{
 std::string operation = ui->lineEdit->text().toStdString();
 std::string mathematicSigns="*/+-.^";

 if((operation.c_str()[operation.size()-1]=='(')&&(signs=="+"||signs=="-"))
 {
ui->lineEdit->insert(QString::fromStdString(signs));
 }
 else if((operation.c_str()[operation.size()-2]=='(')&&(signs=="+"||signs=="-"))
 {
ui->lineEdit->backspace();
ui->lineEdit->insert(QString::fromStdString(signs));
 }


 if((mathematicSigns.find(operation.c_str()[operation.size()-1])== std::string::npos)&&(operation.c_str()[operation.size()-1]!='('))
 {
        ui->lineEdit->insert(QString::fromStdString(signs));
 }
 else if((mathematicSigns.find(operation.c_str()[operation.size()-1])!= std::string::npos)&&(operation.c_str()[operation.size()-2]!='('))
 {
        ui->lineEdit->backspace();
      ui->lineEdit->insert(QString::fromStdString(signs));
 }

}

void MainWindow::on_btnPlus_clicked()
{
 std::string signs = "+";
 signChoice(signs);
}


void MainWindow::on_btnMinus_clicked()
{
  std::string signs = "-";
  signChoice(signs);
}


void MainWindow::on_btnOne_2_clicked()
{
std::string signs = "*";
signChoice(signs);
}


void MainWindow::on_btnDivide_clicked()
{
std::string signs = "/";
signChoice(signs);
}


void MainWindow::on_pbtnExponent_clicked()
{
std::string signs = "^";
signChoice(signs);
}

void MainWindow::on_pbtnExponent2_clicked()
{
std::string operation = ui->lineEdit->text().toStdString();
 std::string numbers="01234567890ep!)";

 if(numbers.find(operation.c_str()[operation.size()-1])!= std::string::npos)
      ui->lineEdit->insert("^2");

}

//EXPONENT -1


void MainWindow::on_btnExponentMinus_clicked()
{
std::string operation=ui->lineEdit->text().toStdString();
std::string character="0123456789ep)";

if (character.find(operation.c_str()[operation.size()-1]) != std::string::npos)
{
      ui->lineEdit->insert("^(-1)") ;
}

}



//DOT

void MainWindow::on_btnDot_clicked()
{
std::string signs = ".";
signChoice(signs);
}

//DELETE BUTTONS

void MainWindow::on_btnAC_clicked()
{
ui->lineEdit->clear();
ui->lineEdit->insert("0");
bracket = 0;
}

void MainWindow::on_btnDeleteSign_clicked()
{
std::string sign=ui->lineEdit->text().toStdString();
//STRING FOR DELETE ALL WORDS (FOR EXAMPLE SIN,COS,TAN)
std::string signs="acegilnopqrst";


if (sign.c_str()[sign.size() - 1] == '(')
{
      bracket--;
      sign.erase(sign.size() - 1);
      ui->lineEdit->backspace();
      if (signs.find(sign.c_str()[sign.size()-1]) != std::string::npos)
          while(sign!="")
          {
              if (signs.find(sign.c_str()[sign.size()-1]) == std::string::npos)
                  break;
              if (signs.find(sign.c_str()[sign.size()-1]) != std::string::npos)
              {
                  sign.erase(sign.size() - 1);
                  ui->lineEdit->backspace();
              }
              if (sign=="")
              {
                  ui->lineEdit->clear();
                  ui->lineEdit->insert("0");
                  break;
              }
          }
}
else
{
      ui->lineEdit->backspace();
      if(ui->lineEdit->text()=="")
          ui->lineEdit->insert("0");
}
}

//FACTORIAL

void MainWindow::on_btnFactorial_clicked()
{
std::string operation=ui->lineEdit->text().toStdString();
std::string characters="0123456789)!";

if(characters.find(operation.c_str()[operation.size()-1])!= std::string::npos)
{
      if(operation.size()>=5)
      {
          int number=0;
          for(int i=operation.size()-1; i>operation.size()-6; i--)
          {
              if(operation.c_str()[i]=='!')
                  number++;
          }
          if(number<5)
              ui->lineEdit->insert("!");
      }
      else
      ui->lineEdit->insert("!");
}

}

//BRACKETS

void MainWindow::on_btnOpenBracket_clicked()
{
std::string operation=ui->lineEdit->text().toStdString();
std::string character="acegilnopqrst";
std::string signs="*/+-^(";
std::string numbers="0123456789!ep)";


if(numbers.find(operation.c_str()[operation.size()-1])!= std::string::npos)
{
      ui->lineEdit->insert("*");
      ui->lineEdit->insert("(");
      bracket++;
}
else if(signs.find(operation.c_str()[operation.size()-1])!= std::string::npos)
{
      ui->lineEdit->insert("(");
      bracket++;
}

}

void MainWindow::on_btnCloseBracket_clicked()
{
std::string operation=ui->lineEdit->text().toStdString();
std::string signs="+-*/.^(";
if((bracket>0)&&(signs.find(operation.c_str()[operation.size()-1])== std::string::npos))
{
     ui->lineEdit->insert(")");
      bracket--;
}
}

//FUNCTIONS

void MainWindow::mathematicFunctions(std::string & function)
{
std::string operation=ui->lineEdit->text().toStdString();
std::string numbers="0123456789!ep)";
std::string signs="+-*/^(";

if(numbers.find(operation.c_str()[operation.size()-1])!= std::string::npos)
{
      ui->lineEdit->insert("*");
      ui->lineEdit->insert(QString::fromStdString(function));
      bracket++;
}
else if(signs.find(operation.c_str()[operation.size()-1])!= std::string::npos)
{
      ui->lineEdit->insert(QString::fromStdString(function));
      bracket++;
}

}

void MainWindow::on_btnSin_clicked()
{
std::string function="sin(";
mathematicFunctions(function);
}

void MainWindow::on_btnCos_clicked()
{
std::string function="cos(";
mathematicFunctions(function);
}

void MainWindow::on_btnTan_clicked()
{
std::string function="tan(";
mathematicFunctions(function);
}

void MainWindow::on_btnLog_clicked()
{
std::string function="log(";
mathematicFunctions(function);
}

void MainWindow::on_btnLn_clicked()
{
std::string function="ln(";
mathematicFunctions(function);
}

void MainWindow::on_btnSqrt_clicked()
{
std::string function="sqrt(";
mathematicFunctions(function);
}

void MainWindow::on_btnArcSin_clicked()
{
std::string function="arcsin(";
mathematicFunctions(function);
}

void MainWindow::on_btnArcCos_clicked()
{
std::string function="arccos(";
mathematicFunctions(function);
}

void MainWindow::on_btnArcTan_clicked()
{
std::string function="arctan(";
mathematicFunctions(function);
}

//PI AND EULER'S NUMBER




void MainWindow::on_btnPi_clicked()
{
std::string function="p";
mathematicFunctions(function);
}

void MainWindow::on_btnE_clicked()
{
std::string function="e";
mathematicFunctions(function);
}

//EQUAL

std::string & MainWindow::changing_Pi_and_E(std::string& operation)
{
    std::string mE = "2,718282";
    std::string p = "3.141593";
    for (int i = 0; i < operation.size(); i++)
    {
        switch (operation.c_str()[i])
        {
        case 'e': {operation.erase(i, 1); operation.insert(i, mE); break; }
        case 'p': {operation.erase(i, 1); operation.insert(i, p); break; }
        }
    }
    return operation;
}

void MainWindow::advancedContinued(float & variable, int & calculation)
{
    switch (calculation)
    {
    case SQRT: {if (minuss == true) error = true; variable = std::sqrt(variable); break; }
    case LG: {variable = log10(variable); break; }
    case LN: {if (minuss == true) error = true; variable = log(variable); break; }
    case SIN:
    {
        if (rad == false)
        {
            variable = sin(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = sin(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    case COS:
    {
        if (rad == false)
            variable = cos(variable * (M_PI / 180));
        else
            variable = cos(variable);
        break;
    }
    case TAN:
    {
        if (rad == false)
        {
            variable = tan(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = tan(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    case ARCSIN:
    {
        if (variable < -1.0)
            error = true;
        if(variable > 1.0)
            error = true;
        if (rad == false)
            variable = asin(variable) * 180 / M_PI;
        if (minuss == true) variable -= variable * 2;
        break;
    }
    case ARCCOS:
    {
        if (variable < -1.0)
            error = true;
        if(variable > 1.0)
            error = true;
        if (rad == false)
            variable = acos(variable) * 180 / M_PI;
        if (minuss == true) variable -= variable * 2;
        break;
    }
    case ARCTAN:
    {
        if (rad == true)
        {
            variable = sin(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = sin(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    }
}

void MainWindow::advanced(std::string& operation, std::string& text, int & lenght, bool& function,int & stringSize,int & calculation)
{
    float variable = 0;
    int firstSign = operation.find(text);
    stringSize = operation.find(text) + lenght;
    if (operation[operation.find(text) + lenght + 1] == '-')
    {
        minuss = true;
        operation.erase(lenght + 1, 1);
    }
    std::string neww = "";
    while (function != false)
    {
        stringSize++;
        neww += operation[stringSize];
        lenght++;
        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize > operation.size() - 1))
        {
            variable = (std::stoi(neww));
            advancedContinued(variable,calculation);
            operation.erase(firstSign, lenght);
            operation.insert(firstSign, std::to_string(variable));
            function = false;
            stringSize = 0;
        }
        else if (operation.c_str()[stringSize] == '.')
        {
            variable = std::stoi(neww);
            neww = "";
            int size = -1;
            while (function != false)
            {
                stringSize++;
                size++;
                neww += operation[stringSize];
                lenght++;
                if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize > operation.size() - 1))
                {
                    variable += (std::stoi(neww) / pow(10, size));
                    advancedContinued(variable, calculation);
                    operation.erase(firstSign, lenght);
                    operation.insert(firstSign, std::to_string(variable));
                    function = false;
                    stringSize = 0;
                }
            }
        }
    }

}

unsigned long long MainWindow::factorialCalculated(int n, int number)
{
    if (n == 0 || n == 1) { return 1; }
    else
    {
        if (n < number) return n * factorialCalculated(n + 1 - n,number);
        return n * factorialCalculated(n - number,number);
    }
}

void MainWindow::factorials(std::string& operation, std::string& text, int& lenght, int& number, bool& function, int& stringSize)
{
    unsigned long long variable = 0;
    stringSize = operation.find(text) + number;
    std::string temporaryString = "";
    while (function != false)
    {
        stringSize--;
        temporaryString += operation[stringSize];
        lenght++;
        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize == 0))
        {
            if (stringSize != 0)
            {
                stringSize++;
                lenght--;
            }
            reverse(temporaryString.begin(), temporaryString.end());
            variable = (std::stoi(temporaryString));
            variable = factorialCalculated(variable,number+1);
            operation.erase(stringSize, lenght);
            operation.insert(stringSize, std::to_string((int)variable));
            stringSize = 0;
            function = false;
        }
    }

}

std::string MainWindow::calculation(const char* x)
{
    using namespace std;
    std::string operation = x;
    std::vector< long double >numbers;//NUMBERS
    std::vector< char >signs; //SIGNS
    std::vector< char >secondSigns; //SIGNS WITHOUT POWER
    std::vector<char>lastSigns; //SIGNS WITHOUT MULTIPLICATION AND DIVISION
    std::vector< long double >potega; //RESULT OF POWER
    std::vector< long double >mnozenie;//NUMBERS WITHOUT POWER
    std::vector< long double >dodawanie;//NUMBERS WITHOUT MULTIPLICATION AND DIVISION
    int stringSize = 0;
    double result = 0;
    bool function = true;

    while (stringSize < operation.size())
    {
        if (operation.find("!!!!!") != std::string::npos)
        {
            std::string text = "!!!!!";
            int number = 4;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!!!") != std::string::npos)
        {
            std::string text = "!!!!";
            int number = 3;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!!") != std::string::npos)
        {
            std::string text = "!!!";
            int number = 2;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!") != std::string::npos)
        {
            std::string text = "!!";
            int number = 1;
            int lenght = 1;
            factorials(operation,text, lenght,number, function, stringSize);
        }

        if (operation.find("!") != std::string::npos)
        {
            std::string text = "!";
            int number = 0;
            int variable = 0;
            int lenght = 1;

            factorials(operation,text,lenght,number, function, stringSize);
        }

        if (operation.find("sqrt") != std::string::npos)
        {
            std::string text = "sqrt";
            int lenght = 3;
            int calculation = SQRT;
            advanced(operation,text,lenght, function,stringSize,calculation);
        }
        if (operation.find("lg") != std::string::npos)
        {
            std::string text = "lg";
            int lenght = 1;
            int calculation = LG;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("ln") != std::string::npos)
        {
            std::string text = "ln";
            int lenght = 1;
            int calculation = LN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arcsin") != std::string::npos)
        {
            std::string text = "arcsin";
            int lenght = 5;
            int calculation = ARCSIN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arccon") != std::string::npos)
        {
            std::string text = "arccos";
            int lenght = 5;
            int calculation = ARCCOS;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arctan") != std::string::npos)
        {
            std::string text = "arctan";
            int lenght = 5;
            int calculation = ARCTAN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("sin") != std::string::npos)
        {
            std::string text = "sin";
            int lenght = 2;
            int calculation = SIN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("cos") != std::string::npos)
        {
            std::string text = "cos";
            int lenght = 2;
            int calculation = COS;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("tan") != std::string::npos)
        {
            std::string text = "tan";
            int lenght = 2;
            int calculation = TAN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }

        stringSize++;
        function = true;
    }
    int change = 0;
    stringSize = 0;
    if (operation[0] == '-')
    {
        std::string change = "0";
        change += operation;
        operation = change;
    }
    while (operation != "")
    {
        if (stringSize == operation.size() - 1)
        {
            numbers.push_back(std::stoi(operation));
            break;
        }
        stringSize++;

        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (operation.c_str()[stringSize] == '.'))
        {
            if (operation.c_str()[stringSize] == '.')
            {
                numbers.push_back(std::stoi(operation));
                for (int y = 0; y <= stringSize; y++)
                {
                    operation.erase(operation.begin());
                }
                stringSize = 0;
                int liczba = 0;
                while (operation != "")
                {
                    stringSize++;
                    liczba++;
                    if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize >= operation.size() - 1))
                    {

                        if (stringSize != operation.size() - 1)
                            signs.push_back(operation.c_str()[stringSize]);
                        else
                            liczba++;

                        if ((numbers[numbers.size() - 1] < 0) || (condition == true))
                            numbers[numbers.size() - 1] -= (std::stoi(operation) / pow(10, liczba));
                        else if ((numbers[numbers.size() - 1] >= 0) && (condition == false))
                            numbers[numbers.size() - 1] += (std::stoi(operation) / pow(10, liczba));

                        for (int y = 0; y <= stringSize; y++)
                        {
                            operation.erase(operation.begin());
                        }
                        stringSize = 0;
                        condition = false;
                        break;
                    }
                }
            }
            else
            {
                signs.push_back(operation.c_str()[stringSize]);
                numbers.push_back(std::stoi(operation)) ;
                for (int y = 0; y <= stringSize; y++)
                {
                    operation.erase(operation.begin());
                }
                if (operation.c_str()[0] == '-')
                    condition = true;
                stringSize = 0;
            }
        }
    }
    signs.push_back('+');


    //CALCULATING POWERS


    for (int i = numbers.size() - 1; i >= 0; i--)
    {

        if (signs[i] == '^')
        {
            potega.push_back(numbers[i + 1]);
            while (signs[i] == '^')
            {
                potega[potega.size() - 1] = pow(numbers[i], potega[potega.size() - 1]);
                if (i > 0)
                    i--;
                else
                    break;
            }
        }
    }

    //NUMBERS IN THE NEW TABLE

    int j = potega.size() - 1;


    for (int i = 0; i < numbers.size(); i++)
    {
        if (signs[i] == '^')
        {
            mnozenie.push_back(potega[j]);
            j--;
            while (signs[i] == '^')
                i++;
        }
        else
            mnozenie.push_back(numbers[i]);
    }

    //SIGNS IN THE NEW TABLE

    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] != '^')
            secondSigns.push_back(signs[i]);
    }

    //CALCULATION MULTIPLICATION,DIVIDEMENT AND NUMBERS IN THE NEW TABLE

    int y = 0;

    for (int i = 0; i < mnozenie.size(); i++)
    {
        if ((i == 0) && (secondSigns[i] != '*') && (secondSigns[i] != '/'))
        {
            dodawanie.push_back(mnozenie[i]);
            y++;
        }
        if (secondSigns[i] == '*')
        {
            dodawanie.push_back(mnozenie[i] * mnozenie[i + 1]);
            i++;
            while (secondSigns[i] == '*')
            {
                dodawanie[y] *= mnozenie[i + 1];
                i++;
            }
            y++;
        }
        else if (secondSigns[i] == '/')
        {
            dodawanie.push_back(mnozenie[i] / mnozenie[i + 1]);
            i++;
            while (secondSigns[i] == '/')
            {
                dodawanie[y] /= mnozenie[i + 1];
                i++;
            }
            y++;
        }
        else if ((i > 0) && (secondSigns[i] != '*') && (secondSigns[i] != '/') && (secondSigns[i - 1] != '*') && (secondSigns[i - 1] != '/'))
        {
            dodawanie.push_back(mnozenie[i]);
            y++;
        }
    }

    //SIGNS IN THE NEW TABLE

    for (int i = 0; i < secondSigns.size(); i++)
    {
        if (secondSigns[i] == '+')
            lastSigns.push_back('+');
        else if (secondSigns[i] == '-')
            lastSigns.push_back('-');
    }

    //LAST CALCULATION

    result = dodawanie[0];

    for (int i = 0; i < dodawanie.size() - 1; i++)
    {
        if (lastSigns[i] == '+')
            result += dodawanie[i + 1];
        else
            result -= dodawanie[i + 1];
    }

    if ((int)result - result == 0)
        return operation = std::to_string((int)result);
    else
        return operation = std::to_string(result);

}

std::string MainWindow::brackets(std::string& operation)
{
    int currentSign = 0;
    bool bracketExists = false;

    //REMOVE BRACKETS

    while (currentSign < operation.size())
    {
        if (operation.c_str()[currentSign] == '(')
        {
            bracketExists = true;
            int firstSign = currentSign + 1;
            int sizeSigns = 0;
            while (operation.c_str()[currentSign] != ')')
            {
                currentSign++;
                sizeSigns++;
                if (operation.c_str()[currentSign] == '(')
                {
                    firstSign = currentSign + 1;
                    sizeSigns = 0;
                }
            }
            char* y = new char[operation.size()] {};
            operation.copy(y, sizeSigns - 1, firstSign);
            operation.replace(firstSign - 1, sizeSigns + 1, calculation(y));
        }
        if (currentSign < operation.size())
            currentSign++;
        if ((currentSign >= operation.size()) && (bracketExists == true))
        {
            bracketExists = false;
            currentSign = 0;
        }
    }
    return operation;
}

//EQUAL BUTTON

void MainWindow::on_btnEqual_clicked()
{
    std::string signs="+-*/^.";
operation = ui->lineEdit->text().toStdString();

    if(signs.find(operation.c_str()[operation.size()-1])!= std::string::npos)
    {
        operation.erase(operation.size()-1);
        ui->lineEdit->backspace();
    }

    char* result = new char[operation.size() + 1] {};
    changing_Pi_and_E(operation);
    brackets(operation).copy(result, operation.size(), 0);
    calculation(result);
    if (error == true)
    {
        ui->textEdit->setPlainText("ERROR");
        ui->lineEdit->clear();
        ui->lineEdit->insert("0");
        error=false;
    }
    else
    {
        ui->textEdit->setText(ui->lineEdit->text()+" Result: "+QString::fromStdString(calculation(result)));
        ui->textHistory->insertPlainText(QString::fromStdString(operation)+" = "+QString::fromStdString(calculation(result))+"\n");
        condition = false;
        minuss = false;
    }

}

void MainWindow::on_btnRadDeg_clicked()
{
  if(ui->btnRadDeg->text()=="deg")
  {
       ui->btnRadDeg->setText("rad");
      rad=true;
  }
  else if(ui->btnRadDeg->text()=="rad")
  {
      ui->btnRadDeg->setText("deg");
      rad=false;
  }
}


void MainWindow::on_btnDeleteHistory_clicked()
{
  ui->textHistory->clear();
}

//--------------------------------------CONVENTER-----------------------------------------------------------

void MainWindow::conventer()
{
  Units unit;
  float number=std::stoi(ui->line2_Edit->text().toStdString());
  std:: string result;
  if(measure == LENGHT)
  {
      switch(units)
      {
      case unit.MM:
      {
        result=std::to_string(number)+" mm\n"+
                 std::to_string(number/10)+" cm\n"+
                 std::to_string(number/100)+" dm\n"+
                 std::to_string(number/1000)+" m\n"+
                 std::to_string(number/1000000)+" km\n";
        break;
      }
      case unit.CM:
      {
        result=std::to_string(number)+" cm\n"+
                 std::to_string(number/10)+" mm\n"+
                 std::to_string(number/100)+" dm\n"+
                 std::to_string(number/1000)+" m\n"+
                 std::to_string(number/1000000)+" km";
        break;
      }
      case unit.DM:
      {
        result=std::to_string(number)+" dm\n"+
                 std::to_string(number*100)+" mm\n"+
                 std::to_string(number/10)+" cm\n"+
                 std::to_string(number/10)+" m\n"+
                 std::to_string(number/10000)+" km";
        break;
      }
      case unit.M:
      {
        result=std::to_string(number)+" m\n"+
                 std::to_string(number*1000)+" mm\n"+
                 std::to_string(number/100)+" cm\n"+
                 std::to_string(number/10)+" dm\n"+
                 std::to_string(number/1000)+" km";
        break;
      }
      case unit.KM:
      {
        result=std::to_string(number)+" km\n"+
                 std::to_string(number*1000000)+" mm\n"+
                 std::to_string(number/100000)+" cm\n"+
                 std::to_string(number/10000)+" dm\n"+
                 std::to_string(number/1000)+" m";
        break;
      }
      }

  }
  else if(measure == WEIGHT)
  {
      switch(units)
      {
      case unit.G:
      {
        result=std::to_string(number)+" g\n"+
                 std::to_string(number/10)+" dac\n"+
                 std::to_string(number/100)+" hg\n"+
                 std::to_string(number/1000)+" kg";
        break;
      }
      case unit.DAG:
      {
        result=std::to_string(number)+" dac\n"+
                 std::to_string(number*10)+" g\n"+
                 std::to_string(number/10)+" hg\n"+
                 std::to_string(number/100)+" kg";
        break;
      }
      case unit.HG:
      {
        result=std::to_string(number)+" hg\n"+
                 std::to_string(number*100)+" g\n"+
                 std::to_string(number*10)+" dac\n"+
                 std::to_string(number/10)+" kg";
        break;
      }
      case unit.KG:
      {
        result=std::to_string(number)+" kg\n"+
                 std::to_string(number*1000)+" g\n"+
                 std::to_string(number*100)+" dac\n"+
                 std::to_string(number*10)+"hg";
        break;
      }
      }
  }
  else if(measure == POWER)
  {
      switch(units)
      {
      case unit.W:
      {
        result=std::to_string(number)+" W\n"+
                 std::to_string(number/1000)+" kW\n"+
                 std::to_string(number/1000*1.34)+" HP\n"+
                 std::to_string(number*44.25373)+" [ft•lb/(min•ft^2)]\n"+
              std::to_string(number*0.056869)+" BTU";
        break;
      }
      case unit.KW:
      {
        result=std::to_string(number)+" kW\n"+
                 std::to_string(number*1000)+" W\n"+
                 std::to_string(number*1.34)+" HP\n"+
                 std::to_string(number*44253.73)+" [ft•lb/(min•ft^2)]\n"+
                std::to_string(number*56.86902)+" BTU";
        break;
      }
      case unit.HP:
      {
        result=std::to_string(number)+" HP\n"+
                 std::to_string(number*745.6999)+" W\n"+
                 std::to_string(number*0.7457)+" kW\n"+
                 std::to_string(number*33000)+" [ft•lb/(min•ft^2)]\n"+
              std::to_string(number*42.40722)+" BTU";
        break;
      }
      case unit.SF:
      {
        result=std::to_string(number)+" [ft•lb/(min•ft^2)]\n"+
                std::to_string(number*0.022597)+" W\n"+
                 std::to_string(number*0.000022597)+" kW\n"+
                 std::to_string(number*0.000030303)+" HP\n"+
                 std::to_string(number*0.00128507)+" BTU";
        break;
      }
      case unit.BTU:
      {
        result=std::to_string(number)+" BTU\n"+
                 std::to_string(number*17.58427)+" W\n"+
                 std::to_string(number*0.0175843)+" kW\n"+
                 std::to_string(number*0.0235809)+" HP\n"+
                 std::to_string(number*778.1694)+" [ft•lb/(min•ft^2)]";
        break;
      }
      }
  }
  ui->textEdit_2->setText(QString::fromStdString(result));
}


void MainWindow::on_BoxList_activated(int index)
{
    units= index;
           if(ui->line2_Edit->text()!="")
      conventer();
}

void MainWindow::on_btn2_DeleteSign_clicked()
{
    ui->line2_Edit->backspace();
           if(ui->line2_Edit->text()!="")
      conventer();
           else
     ui->textEdit_2->clear();
}


void MainWindow::on_btn2_AC_clicked()
{
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
}

