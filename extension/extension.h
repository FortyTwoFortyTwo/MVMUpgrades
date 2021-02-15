#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

#include "smsdk_ext.h"

class CBasePlayer;
class CUserCmd;

#include "utlmap.h"
#include "igamesystem.h"

//hl2sdk TF2 don't have public/tier1/ilocalize.h for locchar_t
#ifdef GC
	typedef char locchar_t;
#else
	typedef wchar_t locchar_t;
#endif

#define MAX_ATTRIBUTE_DESCRIPTION_LENGTH		( 256 / sizeof( locchar_t ) )

class CMannVsMachineUpgrades
{
public:
	char szAttrib[ MAX_ATTRIBUTE_DESCRIPTION_LENGTH ];
	char szIcon[ MAX_PATH ];
	float flIncrement;
	float flCap;
	int nCost;
	int nUIGroup;
	int nQuality;
	int nTier;		// If set, upgrades in the same tier - for the same player/item - will be mutually exclusive
};

class CMannVsMachineUpgradeManager : CAutoGameSystem
{
public:
	CUtlVector< CMannVsMachineUpgrades > m_Upgrades;

private:
	CUtlMap< const char*, int > m_AttribMap;
};

extern CMannVsMachineUpgradeManager *g_MannVsMachineUpgrades;

/**
 * @brief Sample implementation of the SDK Extension.
 * Note: Uncomment one of the pre-defined virtual functions in order to use it.
 */
class MVMUpgrades : public SDKExtension
{
public:
	/**
	 * @brief This is called after the initial loading sequence has been processed.
	 *
	 * @param error		Error message buffer.
	 * @param maxlength	Size of error message buffer.
	 * @param late		Whether or not the module was loaded after map load.
	 * @return			True to succeed loading, false to fail.
	 */
	virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
	
	/**
	 * @brief This is called right before the extension is unloaded.
	 */
	virtual void SDK_OnUnload();
};

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

