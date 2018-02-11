#include "CHOP_CPlusPlusBase.h"

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <assert.h>


class EmptyCPlusPlusCHOP : public CHOP_CPlusPlusBase
{

public:

	EmptyCPlusPlusCHOP(const OP_NodeInfo* info) {}
	virtual ~EmptyCPlusPlusCHOP() {}

	virtual void setupParameters(OP_ParameterManager* manager) override
	{
	}

	virtual void getGeneralInfo(CHOP_GeneralInfo* ginfo) override
	{
	}

	virtual void execute(const CHOP_Output*, OP_Inputs*, void* reserved) override
	{
	}

private:


};


extern "C"
{
	DLLEXPORT int32_t GetCHOPAPIVersion(void)
	{
		return CHOP_CPLUSPLUS_API_VERSION;
	}

	DLLEXPORT CHOP_CPlusPlusBase* CreateCHOPInstance(const OP_NodeInfo* info)
	{
		return new EmptyCPlusPlusCHOP(info);
	}

	DLLEXPORT void DestroyCHOPInstance(CHOP_CPlusPlusBase* instance)
	{
		delete (EmptyCPlusPlusCHOP*)instance;
	}
};


