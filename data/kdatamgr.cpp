#include "kdatamgr.h"

KDataMgr* KDataMgr::instance()
{
	static KDataMgr dataMgr;
	return &dataMgr;
}

KDataMgr::KDataMgr()
{

}

KDataMgr::~KDataMgr()
{

}

void KDataMgr::init()
{

}
