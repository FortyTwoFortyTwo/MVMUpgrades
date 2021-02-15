#include "extension.h"

cell_t MVMUpgrades_GetCount(IPluginContext *pContext, const cell_t *params)
{
	return g_MannVsMachineUpgrades->m_Upgrades.Count();
}

cell_t MVMUpgrades_GetAttribute(IPluginContext *pContext, const cell_t *params)
{
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	size_t numBytes;
	pContext->StringToLocalUTF8(params[2], params[3], g_MannVsMachineUpgrades->m_Upgrades[params[1]].szAttrib, &numBytes);
	return numBytes;
}

cell_t MVMUpgrades_GetIcon(IPluginContext *pContext, const cell_t *params)
{
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	size_t numBytes;
	pContext->StringToLocalUTF8(params[2], params[3], g_MannVsMachineUpgrades->m_Upgrades[params[1]].szIcon, &numBytes);
	return numBytes;
}

cell_t MVMUpgrades_GetIncrement(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return sp_ftoc(g_MannVsMachineUpgrades->m_Upgrades[params[1]].flIncrement);
}

cell_t MVMUpgrades_GetCap(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return sp_ftoc(g_MannVsMachineUpgrades->m_Upgrades[params[1]].flCap);
}

cell_t MVMUpgrades_GetCost(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return g_MannVsMachineUpgrades->m_Upgrades[params[1]].nCost;
}

cell_t MVMUpgrades_GetUIGroup(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return g_MannVsMachineUpgrades->m_Upgrades[params[1]].nUIGroup;
}

cell_t MVMUpgrades_GetQuality(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return g_MannVsMachineUpgrades->m_Upgrades[params[1]].nQuality;
}

cell_t MVMUpgrades_GetTier(IPluginContext *pContext, const cell_t *params)
{
	
	if (params[1] < 0 || params[1] >= g_MannVsMachineUpgrades->m_Upgrades.Count())
		return pContext->ThrowNativeError("Index %d is not valid", params[1]);
	
	return g_MannVsMachineUpgrades->m_Upgrades[params[1]].nTier;
}

sp_nativeinfo_t g_ExtensionNatives[] = 
{
	{"MVMUpgrades_GetCount",	MVMUpgrades_GetCount},
	{"MVMUpgrades_GetAttribute",	MVMUpgrades_GetAttribute},
	{"MVMUpgrades_GetIcon",	MVMUpgrades_GetIcon},
	{"MVMUpgrades_GetIncrement",	MVMUpgrades_GetIncrement},
	{"MVMUpgrades_GetCap",	MVMUpgrades_GetCap},
	{"MVMUpgrades_GetCost",	MVMUpgrades_GetCost},
	{"MVMUpgrades_GetUIGroup",	MVMUpgrades_GetUIGroup},
	{"MVMUpgrades_GetQuality",	MVMUpgrades_GetQuality},
	{"MVMUpgrades_GetTier",	MVMUpgrades_GetTier},
	
	{NULL,								NULL}
};