#ifndef FIRSTTASKTAB_H
#define FIRSTTASKTAB_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>


class FirstTaskTab : public QWidget{
     Q_OBJECT

public:
    FirstTaskTab(){
        taskCondition = new QLabel("Enter uint: ");
        answer = new QLabel("Answer: ");
        line = new QLineEdit;
        okButton = new QPushButton;
        okButton->setText("OK");
        okButton->setEnabled(false);


        connect(line,SIGNAL(textChanged(QString)),this,SLOT(EnableOkButton(QString)));
        connect(okButton,SIGNAL(clicked()),this,SLOT(FindDegree()));


        mainLayout = new QVBoxLayout;
        mainLayout->addWidget(taskCondition);
        mainLayout->addWidget(line);

        mainLayout->addWidget(answer);
        mainLayout->addWidget(okButton);
        setLayout(mainLayout);
    }


private:
    QVBoxLayout* mainLayout;
    QLabel* taskCondition;
    QLabel* answer;
    QLineEdit* line;
    QPushButton* okButton;
    unsigned int number;

private slots:
    void FindDegree() {
        QString str = line->text();
        bool ok;
        number = str.toUInt(&ok);
        if (!ok) {
            QMessageBox* msg = new QMessageBox(this);
            msg->setText("Invalid number");
            msg->show();
            msg->exec();
            line->clear();
            return;
        }
        unsigned int delta = number >> 1;
        unsigned int count = 0;
        while(delta > 1){
            count ++;
            delta >>= 1;
        }
        if (number != 1)
           count++;

        answer->setText("Answer: " + QString::number(count));
    }

    void EnableOkButton(QString str){
        okButton->setEnabled(!str.isEmpty());
    }

};


#endif // FIRSTTASKTAB_H
