#pragma once

#include <QString>


struct KStyle
{
	static qreal dpiScaled(qreal value);
};

#define LEFT_MINIWIDTH KStyle::dpiScaled(200)
#define LEFT_MAXWIDTH KStyle::dpiScaled(300)
#define LEFT_MINIHEIGHT KStyle::dpiScaled(100)
#define RIGHT_MINIWIDTH 
#define RIGHT_MAXWIDTH
#define MAIN_MINIWIDTH
#define MAIN_MAXWIDTH

#define LEFT_ITEM_HEIGHT KStyle::dpiScaled(48)


