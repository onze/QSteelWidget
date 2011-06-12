#ifndef SBK_QSTEELWIDGETWRAPPER_H
#define SBK_QSTEELWIDGETWRAPPER_H

#define protected public

#include <shiboken.h>

#include <QSteelWidget.h>

class QSteelWidgetWrapper : public QSteelWidget
{
public:
    QSteelWidgetWrapper(QWidget * parent = 0L);
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * event);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEvent(QCloseEvent * e);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * event);
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * e);
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * e);
    virtual void dropEvent(QDropEvent * e);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const;
    virtual void keyPressEvent(QKeyEvent * e);
    virtual void keyReleaseEvent(QKeyEvent * e);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * e);
    virtual void mouseMoveEvent(QMouseEvent * e);
    virtual void mousePressEvent(QMouseEvent * e);
    virtual void mouseReleaseEvent(QMouseEvent * e);
    virtual void moveEvent(QMoveEvent * e);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent * e);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * e);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void wheelEvent(QWheelEvent * e);
    virtual ~QSteelWidgetWrapper();
};

#endif // SBK_QSTEELWIDGETWRAPPER_H

