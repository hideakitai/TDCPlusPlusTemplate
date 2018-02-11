#include "SOP_CPlusPlusBase.h"

#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>


class EmptyCPluPlusSOP : public SOP_CPlusPlusBase
{
public:

	EmptyCPluPlusSOP(const OP_NodeInfo* info) {}
	virtual ~EmptyCPluPlusSOP() {}

	virtual void getGeneralInfo(SOP_GeneralInfo* ginfo) override
	{
		ginfo->cookEveryFrameIfAsked = true;
		ginfo->directToGPU = false;
	}

	virtual void execute(SOP_Output*, OP_Inputs*, void* reserved) override
	{
	}

	virtual void executeVBO(SOP_VBOOutput* output, OP_Inputs* inputs, void* reserved) override
	{
	}

	virtual void setupParameters(OP_ParameterManager* manager) override
	{
	}

	virtual void pulsePressed(const char* name) override
	{
	}

private:

};


extern "C"
{
	DLLEXPORT int32_t GetSOPAPIVersion(void)
	{
		return SOP_CPLUSPLUS_API_VERSION;
	}

	DLLEXPORT SOP_CPlusPlusBase* CreateSOPInstance(const OP_NodeInfo* info)
	{
		return new EmptyCPluPlusSOP(info);
	}

	DLLEXPORT void DestroySOPInstance(SOP_CPlusPlusBase* instance)
	{
		delete (EmptyCPluPlusSOP*)instance;
	}
};

