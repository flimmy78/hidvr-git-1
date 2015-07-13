
#include "sdk_pri_api.h"
	HI_S32 DesTyp, HI_S32 DesGrp, HI_S32 DesChn,
	HI_S32 SrcTyp, HI_S32 SrcGrp, HI_S32 SrcChn)
{
	MPP_CHN_S stSrcChn,stDesChn;

	stDesChn.enModId  = DesTyp;
	stDesChn.s32DevId = DesGrp;
	stDesChn.s32ChnId = DesChn;	

	if(HI_SUCCESS == HI_MPI_SYS_GetBindbyDest(&stDesChn, &stSrcChn)) {
		if(SrcTyp == stSrcChn.enModId
		&& SrcGrp == stSrcChn.s32DevId
		&& SrcChn == stSrcChn.s32ChnId) {
			return HI_SUCCESS;
		}

		HI_MPI_SYS_UnBind(&stSrcChn, &stDesChn);
	}

	stSrcChn.enModId  = SrcTyp;
	stSrcChn.s32DevId = SrcGrp;
	stSrcChn.s32ChnId = SrcChn;

	return HI_MPI_SYS_Bind(&stSrcChn, &stDesChn);
}

HI_S32 HI_MPI_Sys_UnBindByForce(
	HI_S32 DesTyp, HI_S32 DesGrp, HI_S32 DesChn)
{
	MPP_CHN_S stSrcChn,stDesChn;

	stDesChn.enModId  = DesTyp;
	stDesChn.s32DevId = DesGrp;
	stDesChn.s32ChnId = DesChn;	

	if(HI_SUCCESS == HI_MPI_SYS_GetBindbyDest(&stDesChn, &stSrcChn)) {
		return HI_MPI_SYS_UnBind(&stSrcChn, &stDesChn);
	}

	return HI_SUCCESS;
}

const HI_U32 HDMI_CONVTBL[][2] = {
    return HI_SUCCESS;