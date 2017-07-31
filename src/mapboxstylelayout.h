

#ifndef MAPBOXSTYLELAYOUT_H
#define MAPBOXSTYLELAYOUT_H

#include <QtLocation/private/qdeclarativegeomapparameter_p.h>

QT_BEGIN_NAMESPACE

class MapboxStyleLayout: public QDeclarativeGeoMapParameter
{
    Q_OBJECT

    Q_PROPERTY(QString layer MEMBER m_layer NOTIFY layerChanged)
    Q_PROPERTY(QString lineJoin MEMBER m_lineJoin NOTIFY lineJoinChanged)
    Q_PROPERTY(QString lineCap MEMBER m_lineCap NOTIFY lineCapChanged)
public:
    explicit MapboxStyleLayout(QObject *parent = 0);
    virtual ~MapboxStyleLayout();

    QString type() const override;
    void setType(const QString &type) override;

    QString m_layer;
    QString m_lineJoin;
    QString m_lineCap;


Q_SIGNALS:
    void layerChanged(const QString &newLayer);
    void lineJoinChanged(const QString &newLineJoin);
    void lineCapChanged(const QString &newLineCap);
};

QT_END_NAMESPACE

#endif // MAPBOXSTYLELAYOUT_H
