#include <sourcemod>
#include <cmod/version>
#include <cmod/Exp>
#include <cmod/Class>
#include <cmod/Item>

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
}

public void OnClientDisconnect(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onDisconnect();
}

public void OnClientDisconnect_Post(int client) {
  Client cmodClient = view_as<Client>(client);
  cmodClient.onDisconnectPost();
}

public void OnLibraryAdded(const char[] name) {
  lib.onLoadLibrary(name);
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  CreateNative("ClientID.expID.get", native_ClientID_expID_get);
  CreateNative("ClientID.getClass", native_ClientID_getClass);
  CreateNative("ClientID.setClass", native_ClientID_setClass);
  CreateNative("ClientID.getItem", native_ClientID_getItem);
  CreateNative("ClientID.setItem", native_ClientID_setItem);

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

public int native_CmodClient_getClientByExpID(Handle plugin, int numParams) {
  return view_as<int>(clientMan.getClientByExpID(GetNativeCell(1)));
}
