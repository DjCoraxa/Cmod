#include <sourcemod>
#include <cmod>

static ExpID clientExpID[MAXPLAYERS + 1] = {ExpID_Invalid, ...};

static ConVar cvarMaxLvl;
static ConVar cvarLvlRatio;

public void OnPluginStart() {
  cvarMaxLvl = CreateConVar("cmodclientexp_maxlvl", "100", "Max client lvl");
  cvarLvlRatio = CreateConVar("cmodclientexp_lvlratio", "35", "Client lvl ratio");
}

public void OnPluginEnd() {
  for (int client = 0; client < MAXPLAYERS; ++client)
    if (clientExpID[client].isValid())
      clientExpID[client].remove();
}

public void OnClientPutInServer(int client) {
  clientExpID[client] = new ExpID(cvarMaxLvl.IntValue, cvarLvlRatio.IntValue);
}

public void OnClientDisconnect_Post(int client) {
  clientExpID[client].remove();
}

Client getClientByExpID(ExpID expID) {
  for (int client = 1; client <= MaxClients; ++client)
    if (clientExpID[client] == expID)
      return view_as<Client>(client);
  return Client_Invalid;
}

ExpID getClientExpID(int client) {
  return clientExpID[client];
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  CreateNative("Client.expID.get", native_Client_expID_get);
  CreateNative("CmodClient.getClientByExpID", native_CmodClient_getClientByExpID);
  return APLRes_Success;
}

public int native_Client_expID_get(Handle plugin, int numParams) {
  return view_as<int>(getClientExpID(GetNativeCell(1)));
}

public int native_CmodClient_getClientByExpID(Handle plugin, int numParams) {
  return view_as<int>(getClientByExpID(GetNativeCell(1)));
}
