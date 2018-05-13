#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "QGraphicsPixmapItem"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "qdebug.h"
#include "graphicsview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_image_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());

    if(!fileName.isEmpty())
    {
        QImage image(fileName);

        if(image.isNull())
        {
            QMessageBox::information(this,"Image Viewer","Error Displaying image");
            return;
        }

        QGraphicsPixmapItem * imagePix = new QGraphicsPixmapItem(QPixmap::fromImage(image));
         int imageWidth = imagePix->pixmap().width();
         int imageHeight = imagePix->pixmap().height();
         imagePix->setOffset(- imageWidth / 2, -imageHeight / 2);
         imagePix->setPos(0, 0);

         QGraphicsScene *scene = new QGraphicsScene();
         scene->setSceneRect(-imageWidth / 2, -imageHeight / 2, imageWidth, imageHeight);
         GraphicsView * gv = new GraphicsView(this);
         ui->gridLayout->addWidget(gv);
         gv->setScene(scene);

         qInfo()<<"width image " <<imageWidth; // 640
         qInfo()<<"height image " <<imageHeight; // 400
         qInfo()<<"width scene " <<scene->width(); // 640
         qInfo()<<"height scene " <<scene->width(); // 400
         gv->scene()->addItem(imagePix);
         gv->show();
    }
}
