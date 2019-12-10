#ifndef KDATAMGR_H
#define KDATAMGR_H

#include <QObject>

class KDataMgr
{

public:
	static KDataMgr* instance();

public:


private:
	KDataMgr();
	~KDataMgr();
	void init();

private:
	QStringList m_leftItem;
	QStringList m_rightItem;
};

#endif // KDATAMGR_H
