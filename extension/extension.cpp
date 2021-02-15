#include "extension.h"

MVMUpgrades g_Interface;
SMEXT_LINK(&g_Interface);

IGameConfig *g_pGameConf = NULL;
CMannVsMachineUpgradeManager *g_MannVsMachineUpgrades;

extern sp_nativeinfo_t g_ExtensionNatives[];

bool MVMUpgrades::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
	if(strcmp(g_pSM->GetGameFolderName(), "tf") != 0)
	{
		snprintf(error, maxlength, "Cannot run on other mods than TF2.");
		return false;
	}
	
	char conf_error[255] = "";
	if (!gameconfs->LoadGameConfigFile("mvmupgrades", &g_pGameConf, conf_error, sizeof(conf_error)))
	{
		snprintf(error, maxlength, "Could not read gamedata mvmupgrades.txt: %s", conf_error);
		return false;
	}
	
	char *addr;
	if (g_pGameConf->GetMemSig("g_MannVsMachineUpgrades", (void **)&addr) && addr)
	{
		g_MannVsMachineUpgrades = (CMannVsMachineUpgradeManager *)addr;
	}
	else if (g_pGameConf->GetMemSig("CTFGameRules::SetCustomUpgradesFile", (void **)&addr) && addr)
	{
		
		int offset;
		if (g_pGameConf->GetOffset("g_MannVsMachineUpgrades", &offset) && offset)
		{
#ifdef PLATFORM_X86
			g_MannVsMachineUpgrades = (CMannVsMachineUpgradeManager *)*reinterpret_cast<void ***>(addr + offset);
#else
			int32_t varOffset = *(int32_t *) ((unsigned char *) addr + offset);
			g_MannVsMachineUpgrades = (CMannVsMachineUpgradeManager *)*reinterpret_cast<void ***>((unsigned char *) addr + offset + sizeof(int32_t) + varOffset);
#endif
		}
		else
		{
			snprintf(error, maxlength, "Could not find g_MannVsMachineUpgrades pointer by offset.");
			return false;
		}
	}
	else
	{
		snprintf(error, maxlength, "Could not find g_MannVsMachineUpgrades pointer by gamedata.");
		return false;
	}
	
	sharesys->AddNatives(myself, g_ExtensionNatives);
	
	return true;
}

void MVMUpgrades::SDK_OnUnload()
{
	gameconfs->CloseGameConfigFile(g_pGameConf);
}
