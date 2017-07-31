TEMPLATE = lib
QT += qml quick positioning-private location-private 
CONFIG += qt plugin

CONFIG(debug, debug|release) {
    DESTDIR = $${PWD}/bin/debug/
} else {
    DESTDIR = $${PWD}/bin/release/
}

TARGET = mapboxglextras

HEADERS += $$files(src/*.h)
SOURCES += $$files(src/*.cpp)

RESOURCES += $$files(*.qrc)

OTHER_FILES +=  $$files(src/js/*.js) \
		$$files(src/qml/*.qml) \
                *.pri \
                *.qrc \
                qmldir

qmldir.path = $${DESTDIR}/MapboxGLExtras
qmldir.extra =  mkdir -p $${DESTDIR}/MapboxGLExtras
qmldir.files = qmldir
INSTALLS += qmldir

DEFINES += PLUGIN_MODULE_NAME="MapboxGLExtras"
