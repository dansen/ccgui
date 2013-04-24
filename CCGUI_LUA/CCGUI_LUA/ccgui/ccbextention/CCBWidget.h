//
//  CCBWidget.h
//  CCGUI
//
//  Created by CrazyApps on 13-4-21.
//
//

#ifndef __CCGUI__CCBWidget__
#define __CCGUI__CCBWidget__

#include "Widget.h"
_CCGUI_NAMESPACE_BEGIN

class CCBWidget: public Widget
{
public:
    static CCBWidget * create(std::string name, const char * ccbfileName);
private:
    bool init(const char * filename);
public:
private:
    Widget * m_widget;
};


_CCGUI_NAMESPACE_END
#endif
