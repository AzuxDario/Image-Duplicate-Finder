#ifndef WIDGET_H
#define WIDGET_H

#include <QAction>
#include <QApplication>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *leftButtonsLayout;

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *exitAction;

    QListWidget *folderListWidget;
    QPushButton *addFolderButton;
    QPushButton *removeFolderButton;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void addFolderToList();
    void removeFolderFromList();
};
#endif // WIDGET_H
