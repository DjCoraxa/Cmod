#include <sourcemod>
#include <sdkhooks>
#include <cmod/version>
#include <cmod/Exp>
#include <cmod/Class>
#include <cmod/Item>
#include <cmod/Stats>

#include "Cmod/Client/Config"
#include "Cmod/Utility/Data/DataArray"
#include "Cmod/Client/Enum/ClientPtsType"
#include "Cmod/Client/ClientData"
#include "Cmod/Client/LibraryMan"
#include "Cmod/Client/Client"
#include "Cmod/Client/ClientMan"

public Plugin myinfo = {
  name = "Cmod_Client",
  author = "plx211",
  description = "Client function like exp, menu, class, etc.",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

static ClientData data;
static LibraryMan lib;
static ClientMan clientMan;
static CmodStats cmodStats;

public void OnPluginStart() {
  data = new ClientData();
}

public void OnPluginEnd() {
  for (Client client = Client_First; client < Client_Max; ++client)
    client.onPluginEnd();
}

public void OnClientPutInServer(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onPutInServer();
  SDKHook(client, SDKHook_SpawnPost, onClientSpawn);
}

public void OnClientDisconnect(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onDisconnect();
  SDKUnhook(client, SDKHook_SpawnPost, onClientSpawn);
}

public void OnClientDisconnect_Post(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onDisconnectPost();
}

public void OnLibraryAdded(const char[] name) {
  lib.onLoadLibrary(name);

  if (StrEqual(name, "Cmod_StatsCore"))
    cmodStats.hookCreateStats(onStatsCreate);
}

public void onClientSpawn(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onSpawn();
}

public void onStatsCreate(StatsID statsID) {
  for (Client client = Client_First; client < Client_Max; ++client)
    client.onStatsCreate(statsID);
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  CreateNative("ClientID.expID.get", native_ClientID_expID_get);
  CreateNative("ClientID.getClass", native_ClientID_getClass);
  CreateNative("ClientID.setClass", native_ClientID_setClass);
  CreateNative("ClientID.getItem", native_ClientID_getItem);
  CreateNative("ClientID.setItem", native_ClientID_setItem);
  CreateNative("ClientID.freeStatsPts.get", native_ClientID_freeStatsPts_get);
  CreateNative("ClientID.freeStatsPts.set", native_ClientID_freeStatsPts_set);
  CreateNative("ClientID.getStatsPts", native_ClientID_getStatsPts);
  CreateNative("ClientID.setStatsPts", native_ClientID_setStatsPts);
  CreateNative("ClientID.getStatsAllPts", native_ClientID_getStatsAllPts);
  CreateNative("ClientID.recalculateStatsAllPts", native_ClientID_recalculateStatsAllPts);
  CreateNative("ClientID.spendStatsPts", native_ClientID_spendStatsPts);
  CreateNative("ClientID.resetStatsPts", native_ClientID_resetStatsPts);
  CreateNative("ClientID.resetAllStatsPts", native_ClientID_resetAllStatsPts);

  CreateNative("CmodClient.getClientByExpID", native_CmodClient_getClientByExpID);
  return APLRes_Success;
}

public int native_ClientID_expID_get(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return view_as<int>(client.expID);
}

public native_ClientID_getClass(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return view_as<int>(client.getClass());
}

public native_ClientID_setClass(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.setClass(GetNativeCell(2));
}

public native_ClientID_getItem(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return view_as<int>(client.getItem());
}

public native_ClientID_setItem(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.setItem(GetNativeCell(2));
}

public int native_ClientID_freeStatsPts_get(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return client.freeStatsPts;
}

public int native_ClientID_freeStatsPts_set(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.freeStatsPts = GetNativeCell(2);
}

public int native_ClientID_getStatsPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return client.getStatsPts(GetNativeCell(2), GetNativeCell(3));
}

public int native_ClientID_setStatsPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.setStatsPts(GetNativeCell(2), GetNativeCell(3), GetNativeCell(4));
}

public int native_ClientID_getStatsAllPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return client.getStatsAllPts(GetNativeCell(2));
}

public int native_ClientID_recalculateStatsAllPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.recalculateStatsAllPts(GetNativeCell(2));
}

public int native_ClientID_spendStatsPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  return client.spendStatsPts(GetNativeCell(2), GetNativeCell(3));
}

public int native_ClientID_resetStatsPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.resetStatsPts(GetNativeCell(2));
}

public int native_ClientID_resetAllStatsPts(Handle plugin, int numParams) {
  Client client = GetNativeCell(1);
  client.resetAllStatsPts();
}

public int native_CmodClient_getClientByExpID(Handle plugin, int numParams) {
  return view_as<int>(clientMan.getClientByExpID(GetNativeCell(1)));
}
