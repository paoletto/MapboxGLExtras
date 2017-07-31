#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>
#include <QDebug>
#include "mapboxstylelayout.h"

QT_BEGIN_NAMESPACE

#ifndef QRC_INIT
#define QRC_INIT( s ) Q_INIT_RESOURCE( s )
#endif

static void initResources()
{
#ifdef STATIC_QMLPLUGIN
    QRC_INIT( PLUGIN_QRC_FILENAME ); // Fix this
#endif
}

class PLUGIN_MODULE_NAME : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID QT_STRINGIFY(PLUGIN_MODULE_NAME))

public:
    PLUGIN_MODULE_NAME(QObject *parent = 0)
    :   QQmlExtensionPlugin(parent)
    {
        qDebug() << "Constructing " << QT_STRINGIFY(PLUGIN_MODULE_NAME);
        initResources();
    }

    void registerTypes(const char *uri)
    {
        qDebug() << uri << QT_STRINGIFY(PLUGIN_MODULE_NAME);
        Q_ASSERT(uri == QLatin1String(QT_STRINGIFY(PLUGIN_MODULE_NAME)));
        if (QLatin1String(uri) == QLatin1String(QT_STRINGIFY(PLUGIN_MODULE_NAME))) {

            // @uri MapboxGLExtras
            int major = 1;
            int minor = 0;

            qmlRegisterType<MapboxStyleLayout>(uri, major, minor, "MapboxStyleLayout");
        }
    }
};

QT_END_NAMESPACE

#include "plugin.moc"
