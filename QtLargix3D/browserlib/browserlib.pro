QT += core gui widgets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qtbuttonpropertybrowser.cpp \
    qteditorfactory.cpp \
    qtgroupboxpropertybrowser.cpp \
    qtpropertybrowser.cpp \
    qtpropertybrowserutils.cpp \
    qtpropertymanager.cpp \
    qttreepropertybrowser.cpp \
    qtvariantproperty.cpp

HEADERS += \
    qpoint3d.h \
    qpoint3df.h \
    qtbuttonpropertybrowser.h \
    qteditorfactory.h \
    qtgroupboxpropertybrowser.h \
    qtpropertybrowser.h \
    qtpropertybrowserutils_p.h \
    qtpropertymanager.h \
    qttreepropertybrowser.h \
    qtvariantproperty.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
