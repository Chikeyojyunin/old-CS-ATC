// Ats.cpp : DLL アプリケーション用のエントリ ポイントを定義します。
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
	g_output.Reverser = g_doorCloseingSecurity.main(g_pilotlamp, g_reverser); // 戸閉保安出力

	//信号判定部
	if (signalcode == 10) {
		//01の時
		speedlimit = 0;//制限0

	}
	else if (signalcode == 15) {
		//25の時
		speedlimit = 25;//制限25

	}
	else if (signalcode == 18) {
		//40の時
		speedlimit = 40;//制限40

	}
	else if (signalcode == 21) {
		//55の時
		speedlimit = 55;//制限55
	}
	else if (signalcode == 25) {
		//75の時
		speedlimit = 75;//制限75

	}
	else if (signalcode == 28) {
		//90の時
		speedlimit = 90;//制限90

	}
	else {
		//02の時
		speedlimit = -2;//EB
	}
	//ブレーキ出力部
	if (speedlimit == -2) {
		//02の時
		emgbraketrigger = true;

	}
	else {
		//02以外の時
		emgbraketrigger = false;
	}
	if (speedlimit == 0 || speedlimit < g_speed) {
		//01または現示速度より現在速度が出ている時
		svcbraketrigger = true;

	}
	else {
		//それ以外の時
		svcbraketrigger = false;

	}
	//ブレーキ指令部
	if (emgbraketrigger == true) {
		//EBを出力
		brakeoutput = g_emgBrake;
	}
	else if (svcbraketrigger == true && g_brakeNotch != g_emgBrake) {
		//常用ブレーキが出力された居る時かつ、EBじゃない時に常用最大ブレーキを出力
		brakeoutput = g_svcBrake;
	}
	else {
		//ブレーキ出力がないとき
		brakeoutput = -1;
	}
	//BVEにブレーキ段数を伝える場所
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
	signalcode = signal;//BVEからの信号を入力

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

