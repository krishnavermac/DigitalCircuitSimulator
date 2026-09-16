#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

class QPushButton;
class QLabel;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int inputA = 0;
    int inputB = 0;
    int carryIn = 0;

    QLabel* sumLabel;
    QLabel* carryLabel;

    QPushButton* buttonA;
    QPushButton* buttonB;
    QPushButton* buttonCarry;

    void simulate();
    void updateUI();
};

#endif