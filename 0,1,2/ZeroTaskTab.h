#ifndef ZEROTASKTAB_H
#define ZEROTASKTAB_H

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>

class ZeroTaskTab : public QWidget{
     Q_OBJECT

public:
    ZeroTaskTab(){
        taskCondition = new QLabel("Enter uint16_t: ");
        answer = new QLabel("Answer: ");
        swapPositionsLabel = new QLabel("Swap positions: ");
        line = new QLineEdit;
        spinBox1 = new QSpinBox;
        spinBox2 = new QSpinBox;
        okButton = new QPushButton;
        okButton->setText("OK");
        okButton->setEnabled(false);


        connect(line,SIGNAL(textChanged(QString)),this,SLOT(EnableOkButton(QString)));
        connect(okButton,SIGNAL(clicked()),this,SLOT(SwapBytes()));


        mainLayout = new QVBoxLayout;
        mainLayout->addWidget(taskCondition);
        mainLayout->addWidget(line);
        mainLayout->addWidget(swapPositionsLabel);
        spinLayout = new QHBoxLayout;
        spinLayout->addWidget(spinBox1);
        spinLayout->addWidget(spinBox2);
        mainLayout->addLayout(spinLayout);
        mainLayout->addWidget(answer);
        mainLayout->addWidget(okButton);
        setLayout(mainLayout);
    }


private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* spinLayout;
    QLabel* taskCondition;
    QLabel* swapPositionsLabel;
    QLabel* answer;
    QLineEdit* line;
    QSpinBox* spinBox1;
    QSpinBox* spinBox2;
    QPushButton* okButton;
    uint16_t number;

private slots:
    void SwapBytes() {
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

        int pos1 = spinBox1->value();
        int pos2 = spinBox2->value();

        int byte1 = (number >> pos1) & 1;
        int byte2 = (number >> pos2) & 1;

        if (byte1 != byte2) {
            number ^= 1 << pos1;
            number ^= 1 << pos2;
        }
        answer->setText("Answer: " + QString::number(number));
    }

    void EnableOkButton(QString str){
        okButton->setEnabled(!str.isEmpty());
    }

};


#endif // ZEROTASKTAB_H
