#include "mainwindow.h"
#include <QLabel>

///////
/// \brief MainWindow::slot_sensor_status
/// \param MainCard_Input
/// \param CanIO_Input
/// \param MainCard_Output
/// \param CanIO_Output
///The ".cpp" format programmer file is to describe the real-time IO display on the mainwindow

void MainWindow::slot_sensor_status(DWORD MainCard_Input,DWORD CanIO_Input ,\
                                    DWORD MainCard_Output,DWORD CanIO_Output)
{
//    qDebug()<<"call slot_sensor_status";
    //get the real-time value
    systems_conversion(MainCard_Input,1);
    systems_conversion(CanIO_Input,2);
    systems_conversion(MainCard_Output,3);
    systems_conversion(CanIO_Output,4);
    //display the real-time status
    display_IO();
}

void MainWindow::display_IO()
{
//    qDebug()<<"call display_IO";
    int i,j,k,x;
    for(i=0;i<16;i++)
    {
        ////the following code block is to test the function of vector and pointer
//        qDebug()<<"Main input:"<<*(Live_MainCard_Input+i);
//        qDebug()<<"Main input label"<<Main_Input_Box[i];
        ////
        QLabel* main_input=Main_Input_Box[i];
        switch (*(Live_MainCard_Input+i)) {
        case 0:
            main_input->setPixmap(QPixmap("Q1480\\green-circle-md.png"));
            break;
        case 1:
            main_input->setPixmap(QPixmap("Q1480\\red-circle-md.png"));
            break;
        default:
            break;
        }
    }
    for(j=0;j<16;j++)
    {
        QLabel* main_output=Main_Output_Box[j];
        switch (*(Live_MainCard_Output+j)) {
        case 0:
            main_output->setPixmap(QPixmap("Q1480\\green-circle-md.png"));
            break;
        case 1:
            main_output->setPixmap(QPixmap("Q1480\\red-circle-md.png"));
            break;
        default:
            break;
        }
    }
    for(k=0;k<16;k++)
    {
        QLabel* can_input=Can_Input_Box[k];
        switch (*(Live_CanIO_Input+k)) {
        case 0:
            can_input->setPixmap(QPixmap("Q1480\\green-circle-md.png"));
            break;
        case 1:
            can_input->setPixmap(QPixmap("Q1480\\red-circle-md.png"));
            break;
        default:
            break;
        }
    }
    for(x=0;x<16;x++)
    {
        QLabel* can_output=Can_Output_Box[x];
        switch (*(Live_CanIO_Output+x)) {
        case 0:
            can_output->setPixmap(QPixmap("Q1480\\green-circle-md.png"));
            break;
        case 1:
            can_output->setPixmap(QPixmap("Q1480\\red-circle-md.png"));
            break;
        default:
            break;
        }
    }
}

void MainWindow::systems_conversion(DWORD Input,int num)
{
//    qDebug()<<"call systems_conversion";
    DWORD n=Input;//here n must be type"DWORD",or it could be overflow and get wrong result
    int p=2,c,m=0;//"p" for binary type data
//    static int s[100];//must use the keyword "static"
                       //or declare the array "s" as a global variable,
                      //or the array will be destroy with the function finished.
    while (n!=0)//type-conversion and save the result to array s.
    {
        c=n%p;
        n=n/p;
        switch (num) {
        case 1:
            *(Live_MainCard_Input+m)=c;
//            qDebug()<<"Live_MainCarc_Input["<<m<<"]="<<Live_MainCard_Input[m];
//            qDebug()<<"*(Live_MainCard_Input+"<<m<<")="<<c;
            break;
        case 2:
            *(Live_CanIO_Input+m)=c;
            break;
        case 3:
            *(Live_MainCard_Output+m)=c;
            break;
        case 4:
            *(Live_CanIO_Output+m)=c;
            break;
        default:
            break;
        }
//        s[m]=c;   //save the remainder sequential to the array s
        m++;//Here is the recicle of all function.
    }
//    return s;//"return s" returns a "temporary/local" ADDRESS of the systems-conversion array
             //the address could be used by declare a pointer-type variable like"int *a=s",
             //and then use the array by"*(a+i)" or "a[i]"
}
