#pragma once

#include <QString>


struct KStyle
{
	static qreal dpiScaled(qreal value);
};

#define LEFT_MINIWIDTH KStyle::dpiScaled(205)
#define LEFT_MAXWIDTH KStyle::dpiScaled(400)
#define RIGHT_MINIWIDTH 
#define RIGHT_MAXWIDTH
#define MAIN_MINIWIDTH
#define MAIN_MAXWIDTH

#define LEFT_ITEM_HEIGHT KStyle::dpiScaled(48)


