#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QHBoxLayout();
    leftLayout = new QVBoxLayout();
    leftButtonsLayout = new QHBoxLayout();

    this->setLayout(mainLayout);
    mainLayout->addLayout(leftLayout);

    menuBar = new QMenuBar();
    fileMenu = new QMenu(tr("&File"));
    exitAction = new QAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);
    fileMenu->addAction(exitAction);
    mainLayout->setMenuBar(menuBar);

    folderListWidget = new QListWidget();
    addFolderButton = new QPushButton(tr("Add folder"));
    removeFolderButton = new QPushButton(tr("Remove folder"));
    leftLayout->addWidget(folderListWidget);
    leftLayout->addLayout(leftButtonsLayout);
    leftButtonsLayout->addWidget(addFolderButton);
    leftButtonsLayout->addWidget(removeFolderButton);

    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(addFolderButton, SIGNAL(clicked()), this, SLOT(addFolderToList()));
    connect(removeFolderButton, SIGNAL(clicked()), this, SLOT(removeFolderFromList()));
}

Widget::~Widget()
{
}

void Widget::addFolderToList()
{
    QString selectedFolder = QFileDialog::getExistingDirectory();

    if(selectedFolder.isNull() == false)
    {
        if(folderListWidget->findItems(selectedFolder, Qt::MatchFixedString | Qt::MatchCaseSensitive).count() == 0)
        {
            folderListWidget->addItem(selectedFolder);
        }
    }
}

void Widget::removeFolderFromList()
{
    if(folderListWidget->currentRow() > -1)
    {
        delete folderListWidget->takeItem(folderListWidget->currentRow());
    }
}

