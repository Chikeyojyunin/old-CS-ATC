// Ats.cpp : DLL �A�v���P�[�V�����p�̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "atsplugin.h"
#include "doorCloseingSecurity.h"
#include "old-CS-ATC.h"
#include <stdio.h>
#include <cmath>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{

    return TRUE;
}

ATS_API int WINAPI GetPluginVersion()
{
	return ATS_VERSION;
}

ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC vehicleSpec)
{
	g_svcBrake = vehicleSpec.BrakeNotches;
	g_emgBrake = g_svcBrake + 1;
}

ATS_API void WINAPI Initialize(int brake)
{
	g_speed = 0;
}

ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE vehicleState, int *panel, int *sound,double *Location)
{
	g_speed = vehicleState.Speed;
	g_output.Brake = g_brakeNotch;
	g_output.Power = g_powerNotch;
	g_output.Reverser = g_doorCloseingSecurity.main(g_pilotlamp, g_reverser); // �˕ۈ��o��

	//�M�����蕔
	if (signalcode == 10) {
		//01�̎�
		speedlimit = 0;//����0

	}
	else if (signalcode == 15) {
		//25�̎�
		speedlimit = 25;//����25

	}
	else if (signalcode == 18) {
		//40�̎�
		speedlimit = 40;//����40

	}
	else if (signalcode == 21) {
		//55�̎�
		speedlimit = 55;//����55
	}
	else if (signalcode == 25) {
		//75�̎�
		speedlimit = 75;//����75

	}
	else if (signalcode == 28) {
		//90�̎�
		speedlimit = 90;//����90

	}
	else {
		//02�̎�
		speedlimit = -2;//EB
	}
	//�u���[�L�o�͕�
	if (speedlimit == -2) {
		//02�̎�
		emgbraketrigger = true;

	}
	else {
		//02�ȊO�̎�
		emgbraketrigger = false;
	}
	if (speedlimit == 0 || speedlimit < g_speed) {
		//01�܂��͌������x��茻�ݑ��x���o�Ă��鎞
		svcbraketrigger = true;

	}
	else {
		//����ȊO�̎�
		svcbraketrigger = false;

	}
	//�u���[�L�w�ߕ�
	if (emgbraketrigger == true) {
		//EB���o��
		brakeoutput = g_emgBrake;
	}
	else if (svcbraketrigger == true && g_brakeNotch != g_emgBrake) {
		//��p�u���[�L���o�͂��ꂽ���鎞���AEB����Ȃ����ɏ�p�ő�u���[�L���o��
		brakeoutput = g_svcBrake;
	}
	else {
		//�u���[�L�o�͂��Ȃ��Ƃ�
		brakeoutput = -1;
	}
	//BVE�Ƀu���[�L�i����`����ꏊ
	trysetintvalue(&g_output.Brake, brakeoutput);
	
	return g_output;
}

ATS_API void WINAPI SetPower(int notch)
{
	g_powerNotch = notch;
}

ATS_API void WINAPI SetBrake(int notch)
{
	g_brakeNotch = notch;
}

ATS_API void WINAPI SetReverser(int pos)
{
	g_reverser = pos;
}

ATS_API void WINAPI KeyDown(int atsKeyCode)
{
}


ATS_API void WINAPI KeyUp(int hornType)
{
}

ATS_API void WINAPI HornBlow(int atsHornBlowIndex)
{
}

ATS_API void WINAPI DoorOpen()
{
	g_pilotlamp = false;


}

ATS_API void WINAPI DoorClose()
{
	g_pilotlamp = true;
}

ATS_API void WINAPI SetSignal(int signal)
{
	signalcode = signal;//BVE����̐M�������

}

ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA beaconData)
{
}

ATS_API void WINAPI Load() 
{
}

ATS_API void WINAPI Dispose() 
{
}
void trysetintvalue(int* pTrysettarget, int value)
{
	if (value == -1) {

	}
	else {
		*pTrysettarget = value;
	}
}

