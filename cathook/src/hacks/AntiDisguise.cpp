/*
 * AntiDisguise.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: nullifiedcat
 */

#include "AntiDisguise.h"

#include "../common.h"
#include "../sdk.h"

DEFINE_HACK_SINGLETON(AntiDisguise);

const char* AntiDisguise::GetName() {
	return "ANTI-DISGUISE";
}

AntiDisguise::AntiDisguise() {
	v_bEnabled = CREATE_CV(CV_SWITCH, "antidisguise", "0", "Remove spy disguise");
}

void AntiDisguise::PaintTraverse(void*, unsigned int, bool, bool) {
	if (!v_bEnabled->GetBool()) return;
	for (int i = 0; i < 64 && i < HIGHEST_ENTITY; i++) {
		IClientEntity* ent = ENTITY(i);
		if (!ent) continue;
		if (ent->GetClientClass()->m_ClassID == ClassID::CTFPlayer) {
			if (NET_INT(ent, netvar.iClass) == tf_class::tf_spy) {
				NET_INT(ent, netvar.iCond) = NET_INT(ent, netvar.iCond) &~ cond::disguised;
			}
		}
	}
}

bool AntiDisguise::CreateMove(void*, float, CUserCmd*) {return true;}
