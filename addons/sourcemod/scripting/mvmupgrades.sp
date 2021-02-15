#include "include/mvmupgrades.inc"

#define PLUGIN_VERSION	"1.0.0"

public Plugin myinfo =
{
	name = "MVMUpgrades Example",
	author = "42",
	description = "Example plugin that lists all MvM Upgrades",
	version = PLUGIN_VERSION,
	url = "https://github.com/FortyTwoFortyTwo/MVMUpgrades",
};

public void OnPluginStart()
{
	int iLength = MVMUpgrades_GetCount();
	
	LogMessage("============");
	LogMessage("TOTAL = %d", iLength);
	LogMessage("============");
	
	for (int i = 0; i < iLength; i++)
	{
		LogMessage("#%d", i);
		
		char sAttribute[256];
		MVMUpgrades_GetAttribute(i, sAttribute, sizeof(sAttribute));
		LogMessage("Attribute: %s", sAttribute);
		
		char sIcon[256];
		MVMUpgrades_GetIcon(i, sIcon, sizeof(sIcon));
		LogMessage("Icon: %s", sIcon);
		
		LogMessage("Increment: %.2f", MVMUpgrades_GetIncrement(i));
		LogMessage("Cap: %.2f", MVMUpgrades_GetCap(i));
		LogMessage("Cost: %d", MVMUpgrades_GetCost(i));
		LogMessage("UI Group: %d", MVMUpgrades_GetUIGroup(i));
		LogMessage("Quality: %d", MVMUpgrades_GetQuality(i));
		LogMessage("Tier: %d", MVMUpgrades_GetTier(i));
		
		LogMessage("============");
	}
}