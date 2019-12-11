#pragma once

#include <QString>

#ifdef Q_OS_WIN
#include "qt_windows.h"
#elif Q_OS_MAC
#include <private/qt_cocoa_helpers_mac_p.h>
#elif Q_OS_UNIX
#include <qx11info_x11.h>
#include <X11/Xlib.h>
#endif

qreal dpiScaled(qreal value)
{
	static qreal scale = -1;
	if (scale < 0) {
		scale = 1.0;
#ifdef Q_OS_WIN
		{
			HDC hdcScreen = GetDC(0);
			int dpi = GetDeviceCaps(hdcScreen, LOGPIXELSX);
			ReleaseDC(0, hdcScreen);
			scale = dpi / 96.0;
		}
#elif Q_OS_MAC
		scale = qt_mac_get_scalefactor();
#elif Q_OS_UNIX
		{
			int dpi = 0;
			char* str = XGetDefault(QX11Info::display(), "Xft", "dpi");
			if (str)
			{
				char* end = 0;
				int v = strtol(str, &end, 0);
				if (str != end)
				{
					dpi = v;
					scale = dpi / 96.0;
				}
			}
		}
#endif
	}
	return value * scale;
}
