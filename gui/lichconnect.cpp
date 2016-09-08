#include "lichconnect.h"
#include "ui_lichconnect.h"

LichConnect::LichConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LichConnect)
{
    ui->setupUi(this);

    mainWindow = (MainWindow*)qobject_cast<QObject *>(parent);

    connect(this, SIGNAL(connectToLich(QString, QString)),
            mainWindow->getTcpClient(),
            SLOT(connectToLich(QString, QString)));
}

LichConnect::~LichConnect()
{
    delete ui;
}

void LichConnect::showEvent(QShowEvent* event) {
    QDialog::showEvent(event);

    this->init();
}

void LichConnect::init() {
    ui->lichHostEdit->setText("localhost");
    ui->lichPortEdit->setText(QString::fromLatin1("8000"));
}

void LichConnect::on_buttonBox_accepted()
{
    QDialog::accept();

    emit connectToLich(ui->lichHostEdit->text(),
                       ui->lichPortEdit->text());
}
