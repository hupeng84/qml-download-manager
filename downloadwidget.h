/**
 *Copyright (c) 2018 ilaocai
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H

#include <QObject>
#include "downloadmanager.h"

class DownloadWidget : public QObject
{
  Q_OBJECT

public:
  explicit DownloadWidget(QObject *parent = 0);

private slots:
  void addLine(QString qsLine);
  void progress(int nPercentage);
  void finished();

  void on_downloadBtn_clicked();
  void on_pauseBtn_clicked();
  void on_resumeBtn_clicked();

private:
  DownloadManager *mManager;
};

#endif // DOWNLOADWIDGET_H
