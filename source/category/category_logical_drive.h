//
// PROJECT:         Aspia
// FILE:            category/category_logical_drive.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CATEGORY__CATEGORY_LOGICAL_DRIVE_H
#define _ASPIA_CATEGORY__CATEGORY_LOGICAL_DRIVE_H

#include "category/category.h"

namespace aspia {

class CategoryLogicalDrive : public CategoryInfo
{
public:
    CategoryLogicalDrive();

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Table& table, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryLogicalDrive);
};

} // namespace aspia

#endif // _ASPIA_CATEGORY__CATEGORY_LOGICAL_DRIVE_H