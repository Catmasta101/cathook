/*
 * AutoStrafe.h
 *
 *  Created on: Nov 26, 2016
 *      Author: nullifiedcat
 */

#ifndef HACKS_AUTOSTRAFE_H_
#define HACKS_AUTOSTRAFE_H_

#include "IHack.h"

class AutoStrafe : public IHack {
public:
	DECLARE_HACK_METHODS();
	AutoStrafe();
	CatVar* v_bEnabled;
};

DECLARE_HACK_SINGLETON(AutoStrafe);

#endif /* HACKS_AUTOSTRAFE_H_ */
