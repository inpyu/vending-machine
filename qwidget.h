#ifndef QWIDGET_H
#define QWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Qwidget; }
QT_END_NAMESPACE

class Qwidget : public QWidget
{
    Q_OBJECT

public:
    Qwidget(QWidget *parent = nullptr);
    ~Qwidget();

private:
    Ui::Qwidget *ui;
};
#endif // QWIDGET_H
