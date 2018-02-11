#include "TOP_CPlusPlusBase.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cmath>


class EmptyCPluPlusTOP : public TOP_CPlusPlusBase
{
public:
	EmptyCPluPlusTOP::EmptyCPluPlusTOP(const OP_NodeInfo* info) {} 
	virtual EmptyCPluPlusTOP::~EmptyCPluPlusTOP() {}

	virtual void getGeneralInfo(TOP_GeneralInfo* ginfo) override
	{
		ginfo->cookEveryFrame = true;
		ginfo->memPixelType = OP_CPUMemPixelType::RGBA32Float;
	}

	void execute(const TOP_OutputFormatSpecs* outputFormat, OP_Inputs* inputs, TOP_Context *context) override
	{
	}

	void setupParameters(OP_ParameterManager* manager) override
	{
	}

	void pulsePressed(const char* name) override
	{
	}

private:

};



extern "C"
{
	DLLEXPORT TOP_PluginInfo GetTOPPluginInfo(void)
	{
		TOP_PluginInfo info;
		info.apiVersion = TOPCPlusPlusAPIVersion;
		info.executeMode = TOP_ExecuteMode::CPUMemWriteOnly;
		return info;
	}

	DLLEXPORT TOP_CPlusPlusBase* CreateTOPInstance(const OP_NodeInfo* info, TOP_Context* context)
	{
		return new EmptyCPluPlusTOP(info);
	}

	DLLEXPORT void DestroyTOPInstance(TOP_CPlusPlusBase* instance, TOP_Context *context)
	{
		delete (EmptyCPluPlusTOP*)instance;
	}
};
