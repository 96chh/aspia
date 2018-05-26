//
// PROJECT:         Aspia
// FILE:            console/console_statusbar.cc
// LICENSE:         GNU General Public License 3
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "console/console_statusbar.h"

#include <QIcon>

namespace aspia {

ConsoleStatusBar::ConsoleStatusBar(QWidget* parent)
    : QStatusBar(parent)
{
    // Nothing
}

ConsoleStatusBar::~ConsoleStatusBar() = default;

void ConsoleStatusBar::setCurrentComputerGroup(
    const proto::address_book::ComputerGroup& computer_group)
{
    clear();

    item_list_.push_back(new QLabel(this));
    item_list_.push_back(new QLabel(this));
    item_list_.push_back(new QLabel(this));

    for (auto item : item_list_)
    {
        item->setTextFormat(Qt::RichText);
        addWidget(item);
    }

    item_list_[0]->setText(QString("<table><tr><td><img src=':/icon/folder.png'></td>"
                                   "<td>%1</td></tr></table>")
                           .arg(QString::fromStdString(computer_group.name())));

    item_list_[1]->setText(tr("<table><tr><td><img src=':/icon/folder.png'></td>"
                              "<td>Child Groups: %1</td></tr></table>")
                           .arg(computer_group.computer_group_size()));

    item_list_[2]->setText(tr("<table><tr><td><img src=':/icon/computer.png'></td>"
                              "<td>Child Computers: %1</td></tr></table>")
                           .arg(computer_group.computer_size()));
}

void ConsoleStatusBar::clear()
{
    for (auto item : item_list_)
    {
        removeWidget(item);
        delete item;
    }

    item_list_.clear();
}

} // namespace aspia
