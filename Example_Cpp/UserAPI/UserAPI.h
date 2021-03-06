#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <array>
#include <Windows.h>
#include "PreDefined.h"
#include "BS_Errno.h"
#include "../Common/BS2Context.h"
#include "../Common/DeviceControl.h"
#include "../Common/ConfigControl.h"
#include "../Common/CommControl.h"
#include "../Common/DeviceList.h"
#include "../Common/UserControl.h"

#define MENU_BREAK				0


typedef struct
{
	int			index;
	std::string disc;
} MENU_ITEM;

enum EN_MENU_DEV
{
	MENU_USR_BREAK = MENU_BREAK,
	MENU_USR_GET_USR,
	MENU_USR_GET_ALLUSR,
	MENU_USR_ENR_USR,
	MENU_USR_REM_USR,
	MENU_USR_REM_ALLUSR,
};

std::vector<MENU_ITEM> menuInfoDeviceAPI =
{
	{MENU_USR_BREAK,				"Exit"},
	{MENU_USR_GET_USR,				"Get user from device" },
	{MENU_USR_GET_ALLUSR,			"Get all users from device" },
	{MENU_USR_ENR_USR,				"Enroll user to device" },
	{MENU_USR_REM_USR,				"Remove a user " },
	{MENU_USR_REM_ALLUSR,			"Remove all users" },
};


void connectTestDevice(void* context);
uint32_t showMenu(std::vector<MENU_ITEM>& info);
uint32_t getSelectedIndex();
int connectViaIP(void* context, DeviceInfo& device);
int connectSlave(void* context, DeviceInfo& device);
int connectWiegand(void* context, DeviceInfo& device);
int searchSlave(void* context, BS2_DEVICE_ID& masterID, BS2_DEVICE_ID& slaveID);
int searchCSTSlave(void* context, BS2_DEVICE_ID& masterID, BS2_DEVICE_ID& slaveID);
int searchWiegand(void* context, BS2_DEVICE_ID& masterID, BS2_DEVICE_ID& wiegandID);
void displayDeviceList(const std::vector<BS2SimpleDeviceInfo>& devices);
void displaySlaveList(const std::vector<BS2Rs485SlaveDevice>& devices);
void displayCSTSlaveList(const std::vector<BS2Rs485SlaveDeviceEX>& devices);
void displayWiegandList(const std::vector<BS2_DEVICE_ID>& devices);
int runAPIs(void* context, const DeviceInfo& device);
int getAllLogsFromDevice(void* context, BS2_DEVICE_ID id, int32_t timezone);
int getLogsFromDevice(void* context, BS2_DEVICE_ID id, int& latestIndex, int timezone);
int getImageLog(void* context, BS2_DEVICE_ID id, BS2_EVENT_ID eventID, uint8_t* imageBuf, uint32_t& imageSize);
BS2_DEVICE_ID getSelectedDeviceID(const DeviceInfo& info);
