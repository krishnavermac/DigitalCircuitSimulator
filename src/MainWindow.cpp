#include "MainWindow.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <QFont>

MainWindow::MainWindow() {

    setWindowTitle("Digital Circuit Simulator");
    resize(800, 500);

    buttonA = new QPushButton("A : 0", this);
    buttonB = new QPushButton("B : 0", this);
    buttonCarry = new QPushButton("Cin : 0", this);

    sumLabel = new QLabel("SUM : 0", this);
    carryLabel = new QLabel("CARRY OUT : 0", this);

    buttonA->setGeometry(50, 120, 120, 50);
    buttonB->setGeometry(50, 220, 120, 50);
    buttonCarry->setGeometry(50, 320, 120, 50);

    sumLabel->setGeometry(620, 150, 150, 50);
    carryLabel->setGeometry(620, 300, 150, 50);

    QFont buttonFont;
    buttonFont.setPointSize(16);

    buttonA->setFont(buttonFont);
    buttonB->setFont(buttonFont);
    buttonCarry->setFont(buttonFont);

    QFont outputFont;
    outputFont.setPointSize(16);
    outputFont.setBold(true);

    sumLabel->setFont(outputFont);
    carryLabel->setFont(outputFont);

    buttonA->setStyleSheet(
        "QPushButton { padding: 10px; }"
    );

    buttonB->setStyleSheet(
        "QPushButton { padding: 10px; }"
    );

    buttonCarry->setStyleSheet(
        "QPushButton { padding: 10px; }"
    );

    connect(buttonA, &QPushButton::clicked, this, [this]() {

        inputA = !inputA;

        updateUI();
        simulate();
        update();
    });

    connect(buttonB, &QPushButton::clicked, this, [this]() {

        inputB = !inputB;

        updateUI();
        simulate();
        update();
    });

    connect(buttonCarry, &QPushButton::clicked, this, [this]() {

        carryIn = !carryIn;

        updateUI();
        simulate();
        update();
    });

    simulate();
    updateUI();
}

void MainWindow::simulate() {

    int sum =
        inputA ^
        inputB ^
        carryIn;

    int carry =
        (inputA & inputB) |
        (inputB & carryIn) |
        (inputA & carryIn);

    sumLabel->setText(
        "SUM : " + QString::number(sum)
    );

    carryLabel->setText(
        "CARRY OUT : " + QString::number(carry)
    );
}

void MainWindow::updateUI() {

    buttonA->setText(
        "A : " + QString::number(inputA)
    );

    buttonB->setText(
        "B : " + QString::number(inputB)
    );

    buttonCarry->setText(
        "Cin : " + QString::number(carryIn)
    );
}

void MainWindow::paintEvent(QPaintEvent* event) {

    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    QFont titleFont;
    titleFont.setPointSize(24);
    titleFont.setBold(true);

    painter.setFont(titleFont);

    painter.drawText(
        250,
        50,
        "Digital Circuit Simulator"
    );

    QFont gateFont;
    gateFont.setPointSize(20);
    gateFont.setBold(true);

    painter.setFont(gateFont);

    painter.drawText(
        340,
        170,
        "FULL ADDER"
    );

    painter.drawRect(
        300,
        110,
        250,
        280
    );

    QFont labelFont;
    labelFont.setPointSize(14);

    painter.setFont(labelFont);

    painter.drawText(
        185,
        145,
        "A"
    );

    painter.drawText(
        185,
        245,
        "B"
    );

    painter.drawText(
        175,
        345,
        "Cin"
    );

    painter.drawText(
        565,
        175,
        "SUM"
    );

    painter.drawText(
        565,
        325,
        "CARRY"
    );

    QPen wirePen;
    wirePen.setWidth(3);

    painter.setPen(wirePen);

    painter.drawLine(
        170,
        145,
        300,
        145
    );

    painter.drawLine(
        170,
        245,
        300,
        245
    );

    painter.drawLine(
        170,
        345,
        300,
        345
    );

    painter.drawLine(
        550,
        175,
        620,
        175
    );

    painter.drawLine(
        550,
        325,
        620,
        325
    );

    QFont stateFont;
    stateFont.setPointSize(13);
    stateFont.setBold(true);

    painter.setFont(stateFont);

    painter.drawText(
        215,
        135,
        QString::number(inputA)
    );

    painter.drawText(
        215,
        235,
        QString::number(inputB)
    );

    painter.drawText(
        215,
        335,
        QString::number(carryIn)
    );

    painter.drawText(
        580,
        165,
        QString::number(
            inputA ^ inputB ^ carryIn
        )
    );

    painter.drawText(
        580,
        315,
        QString::number(
            (inputA & inputB) |
            (inputB & carryIn) |
            (inputA & carryIn)
        )
    );
}