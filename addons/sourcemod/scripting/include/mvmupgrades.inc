#if defined _mvmupgrades_included
#endinput
#endif
#define _mvmupgrades_included

enum MVMUpgradesUIGroup
{
	MVMUpgradesUIGroup_Item,
	MVMUpgradesUIGroup_Player,
	MVMUpgradesUIGroup_Powerup
}

enum MVMUpgradesQuality
{
	MVMUpgradesQuality_Low,
	MVMUpgradesQuality_Normal,
	MVMUpgradesQuality_High
}

native int MVMUpgrades_GetCount();

native int MVMUpgrades_GetAttribute(int index, char[] attribute, int length);

native int MVMUpgrades_GetIcon(int index, char[] icon, int length);

native float MVMUpgrades_GetIncrement(int index);

native float MVMUpgrades_GetCap(int index);

native int MVMUpgrades_GetCost(int index);

native MVMUpgradesUIGroup MVMUpgrades_GetUIGroup(int index);

native MVMUpgradesQuality MVMUpgrades_GetQuality(int index);

native int MVMUpgrades_GetTier(int index);

public Extension __ext_mvmupgrades = 
{
	name = "mvmupgrades",
	file = "mvmupgrades.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
}