#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H


#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>


class ImageDelegate : public QStyledItemDelegate
{
public:
    ImageDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}


    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        if (index.column() == 2) // Assuming the image_path column is at index 4
        {
            QString imagePath = index.data(Qt::DisplayRole).toString();
            QPixmap pixmap(imagePath);


            if (!pixmap.isNull())
            {
                // Draw the image in the cell
                painter->drawPixmap(option.rect, pixmap.scaledToWidth(option.rect.width(), Qt::SmoothTransformation));
                return;
            }
        }


        QStyledItemDelegate::paint(painter, option, index);
    }
};






#endif // IMAGEDELEGATE_H
