#include "mapboxstylelayout.h"

QT_BEGIN_NAMESPACE

MapboxStyleLayout::MapboxStyleLayout(QObject *parent) : QDeclarativeGeoMapParameter(parent)
{

}

MapboxStyleLayout::~MapboxStyleLayout()
{

}

QString MapboxStyleLayout::type() const {
    return QStringLiteral("layout");
}

void MapboxStyleLayout::setType(const QString &type) {
    Q_UNUSED(type) // noop
}

QT_END_NAMESPACE
