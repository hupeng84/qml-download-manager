
QT       += network qml quick core

TARGET = qmldownloadmanager
CONFIG   += console

TEMPLATE = app

SOURCES += main.cpp \
    downloadwidget.cpp \
    downloadmanager.cpp 

HEADERS += \
    downloadwidget.h \
    downloadmanager.h 

RESOURCES += \
    main.qrc

OTHER_FILES += \
    README.md \
    main.qml
