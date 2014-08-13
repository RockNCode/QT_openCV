#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "effects.h"
#include <stdio.h>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QVBoxLayout>

using namespace cv;

int img_status=0;
int bw_threshold =120;
bool play_status = false;
QString sourceReference = "/home/mgarcia/Videos/bigBuckBunnyFullHD_NoAudio.mp4";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slider_bw->setDisabled(true);
    ui->filename->setText(sourceReference);

    //Create a group for exclusive behavior on radios
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(ui->rb_normal);
    vbox->addWidget(ui->rb_grayscale);
    vbox->addWidget(ui->rb_bw);
    vbox->addWidget(ui->rb_hblur);
    vbox->addWidget(ui->rb_gblur);
    vbox->addStretch(1);
    ui->groupBox->setLayout(vbox);
    setLayout(vbox);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    VideoCapture captRefrnc(sourceReference.toStdString());
    char c;
    int delay = 35;
    int frameNum = -1;          // Frame counter

    if (play_status == false){
        play_status = true;
        ui->pushButton->setText("Stop");
    }else{
        play_status = false;
        ui->pushButton->setText("Play");
    }

    if (!captRefrnc.isOpened())
    {
        //cout  << "Could not open reference " << sourceReference << endl;
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error has occured !");
        messageBox.setFixedSize(500,200);
        //return -1;
    }

    const char* WIN_RF = "Video";

    // Windows
    namedWindow(WIN_RF, CV_WINDOW_AUTOSIZE);

    Mat frameReference;
    Mat dst_image;

    for(;;) //Show the image captured in the window and repeat
    {
        captRefrnc >> frameReference;


        if (frameReference.empty() )
        {
            ui->pushButton->setText("Play");
            QMessageBox messageBox;
            messageBox.critical(0,"Error","video is over!");
            messageBox.setFixedSize(500,200);
            break;
        }

        ++frameNum;
        switch(img_status){
            case 0:
                delay = 35;
                imshow(WIN_RF, frameReference);
            break;
            case 1:                
                convert_to_grayscale(frameReference,dst_image,&delay);
                imshow(WIN_RF, dst_image);
            break;
            case 2:
                convert_to_bw(frameReference,&delay);
                imshow(WIN_RF, frameReference);
            break;
            case 3:
                homogeneous_blur(frameReference,dst_image);
                delay = 35;
                imshow(WIN_RF, dst_image);
            case 4:
                gaussian_blur(frameReference,dst_image);
                delay = 35;
                imshow(WIN_RF, dst_image);
            break;
        default:

            break;
        }

        c = (char)cvWaitKey(delay);
        if (c == 27 || play_status == false)
            break;
    }
}

void MainWindow::on_rb_normal_toggled(bool checked)
{
    if (checked == true)
        img_status = 0;

}

void MainWindow::on_rb_grayscale_toggled(bool checked)
{
    if (checked == true){
        img_status = 1;
    }
}

void MainWindow::on_rb_bw_toggled(bool checked)
{
    if (checked == true){
        img_status = 2;
        ui->slider_bw->setEnabled(true);
    }else{
        ui->slider_bw->setDisabled(true);
    }
}

void MainWindow::on_rb_hblur_toggled(bool checked)
{
    if (checked == true)
        img_status = 3;
}

void MainWindow::on_slider_bw_sliderMoved(int position)
{
    bw_threshold = position;
}

void MainWindow::on_actionTest_triggered()
{
    sourceReference = QFileDialog::getOpenFileName(this, tr("Open Video"), "/home/mgarcia/Videos", tr("Video Files (*.mp4 *.avi)"));
    ui->filename->setText(sourceReference);
}


void MainWindow::on_rb_gblur_toggled(bool checked)
{
    if (checked == true)
        img_status = 4;
}
