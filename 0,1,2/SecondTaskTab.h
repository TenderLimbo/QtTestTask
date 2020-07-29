#ifndef SECONDTASKTAB_H
#define SECONDTASKTAB_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


class SecondTaskTab : public QWidget{
     Q_OBJECT

public:
    SecondTaskTab(){
        ipLabel = new QLabel("Enter ip: ");
        maskLabel = new QLabel("Enter mask: ");
        answer = new QLabel("Answer: ");
        ipLine = new QLineEdit;
        maskLine = new QLineEdit;
        okButton = new QPushButton;
        okButton->setText("OK");
        okButton->setEnabled(false);


        connect(ipLine,SIGNAL(textChanged(QString)),this,SLOT(EnableOkButton()));
        connect(maskLine,SIGNAL(textChanged(QString)),this,SLOT(EnableOkButton()));
        connect(okButton,SIGNAL(clicked()),this,SLOT(FindBroadcastAddress()));

        mainLayout = new QVBoxLayout;
        ipLayout = new QHBoxLayout;
        ipLayout->addWidget(ipLabel);
        ipLayout->addWidget(ipLine);
        maskLayout = new QHBoxLayout;
        maskLayout->addWidget(maskLabel);
        maskLayout->addWidget(maskLine);
        mainLayout->addLayout(ipLayout);
        mainLayout->addLayout(maskLayout);
        mainLayout->addWidget(answer);
        mainLayout->addWidget(okButton);
        setLayout(mainLayout);
    }


private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* ipLayout;
    QHBoxLayout* maskLayout;
    QLabel* ipLabel;
    QLabel* maskLabel;
    QLabel* answer;
    QLineEdit* ipLine;
    QLineEdit* maskLine;
    QPushButton* okButton;
    uint32_t ip;
    uint32_t mask;



private slots:
    void FindBroadcastAddress () {
        bool okIp,okMask;
        ip = ipLine->text().toUInt(&okIp);
        mask = maskLine->text().toUInt(&okMask);

        uint32_t delta = mask << 1;
        while (delta != 0) {
            if ((delta & (1 << 31)) == 0){
                okMask = false;
                break;
            }
            delta <<= 1;
        }

        if (!okIp || !okMask){
           QMessageBox* msg = new QMessageBox(this);
           msg->setText("Negative number or invalid mask");
           msg->show();
           msg->exec();
           if (!okIp)
             ipLine->clear();
           else
             maskLine->clear();
           return;
        }

        uint32_t broadcast = ip | (~mask);
        answer->setText("Answer: " + QString::number(broadcast));
    }

    void EnableOkButton(){
        okButton->setEnabled(!ipLine->text().isEmpty() && !maskLine->text().isEmpty());
    }

};



#endif // SECONDTASKTAB_H
