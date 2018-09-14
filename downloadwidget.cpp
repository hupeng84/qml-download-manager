/**
 *Copyright (c) 2018 ilaocai
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "downloadwidget.h"
#include <QtQml/QQmlProperty>

DownloadWidget::DownloadWidget(QObject *parent) : QObject(parent)
{
    QObject *button = parent->findChild<QObject *>("button");
    if (button)
    {
        QObject::connect(button, SIGNAL(clicked()), this, SLOT(on_downloadBtn_clicked()));
    }

    mManager = new DownloadManager(this);
    connect(mManager, SIGNAL(addLine(QString)), this, SLOT(addLine(QString)));
    connect(mManager, SIGNAL(downloadComplete()), this, SLOT(finished()));
    connect(mManager, SIGNAL(progress(int)), this, SLOT(progress(int)));
}

void DownloadWidget::on_downloadBtn_clicked()
{
    QObject *textfield = this->parent()->findChild<QObject *>("textfield");
    QUrl url(QQmlProperty::read(textfield, "text").toString());
    mManager->download(url);
}

void DownloadWidget::on_pauseBtn_clicked()
{
    mManager->pause();
}

void DownloadWidget::on_resumeBtn_clicked()
{
    mManager->resume();
}

void DownloadWidget::addLine(QString qsLine)
{
    QObject *line = this->parent()->findChild<QObject *>("line");
    QString linetext = QQmlProperty::read(line, "text").toString();
    QQmlProperty::write(line, "text", linetext.append("\n").append(qsLine));
}

void DownloadWidget::progress(int nPercentage)
{
    QObject *progress = this->parent()->findChild<QObject *>("progress");
    QQmlProperty::write(progress, "value", nPercentage);
}

void DownloadWidget::finished()
{
    QObject *finish = this->parent()->findChild<QObject *>("finish");
    QQmlProperty::write(finish, "text", "Download Finished!!!");
}
