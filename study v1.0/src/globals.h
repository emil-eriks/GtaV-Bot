#pragma once
HWND hwnd;
class programStatus
{
public:
	bool isAdmin = false;
	bool isRunning = false;
	bool Stop = false;
	bool windowPrep = false;
	bool overlapOnStart = false;
	std::string console_output = "Emil-Eriks's application started running at";
};
programStatus programstatus;

class Nightclub
{
public:
	bool second_dj_resident = false;
	bool NightclubBool = false;
	bool NightClubLoot = false;
};
Nightclub nightclub;

class Bunker
{
public:
	bool BunkerBool = false;
};
Bunker bunker;

class CocaineLockup
{
public:
	bool CocaineLockupBool = false;
};
CocaineLockup cocainelockup;

class MethLockup
{
public:
	bool MethLockupBool = false;
};
MethLockup methlockup;

class Acidlab
{
public:
	bool AcidLabBool = false;
	int MuttNumber = 1;
};
Acidlab acidlab;

class Timings
{
public:
	int loop_timer = 10;
};
Timings timings;