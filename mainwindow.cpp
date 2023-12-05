#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::upDate(){

    auto webView = ui->webEngineView;
    auto textEdit = ui->plainTextEdit;

    QObject::connect(textEdit, &QPlainTextEdit::textChanged, [textEdit, webView](){
        auto text = textEdit->toPlainText();
        webView->setHtml(text);
    });


}
