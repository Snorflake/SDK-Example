#pragma once
#include "sdk.h"
typedef void(__stdcall* CreateMoveFn)(int, float, bool);
CreateMoveFn oCreateMove;
void __stdcall hkCreateMove(int sequence_number,
	float input_sample_frametime,
	bool active)
{
	oCreateMove(sequence_number, input_sample_frametime, active);
	CUserCmd* cmdlist = *(CUserCmd**)((DWORD)Interfaces.Input + 0xEC);
	CUserCmd* cmd = &cmdlist[sequence_number % 150];
	//Work here
	CBaseEntity* me = Interfaces.ClientEntList->GetClientEntity(Interfaces.Engine->GetLocalPlayer());
	if (!me)
		return;

	if (cmd->buttons & IN_JUMP && !(me->GetFlags() & FL_ONGROUND))
		cmd->buttons &= ~IN_JUMP;
	//Stop work here
	CVerifiedUserCmd* verifiedlist = *(CVerifiedUserCmd**)((DWORD)Interfaces.Input + 0xF0);
	CVerifiedUserCmd* verified = &verifiedlist[sequence_number % 150];
	verified->m_cmd = *cmd;
	verified->m_crc = gCRC.CRC32_ProcessSingleBuffer(cmd, sizeof(cmd));
}
class CHooks
{
public:
	void Hook()
	{
		CVMTHookManager* ClientHook = new CVMTHookManager(Interfaces.Client);
		oCreateMove = (CreateMoveFn)ClientHook->HookFunction(21, hkCreateMove);
		ClientHook->HookTable(true);
	}
};
CHooks Hooks;