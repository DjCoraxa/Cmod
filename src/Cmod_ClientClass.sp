#include <sourcemod>
#include <cmod/Class>

static ClassID clientClass[MAXPLAYERS + 1] = {ClassID_Invalid, ...};

public void OnClientDisconnect(int client) {
  if (clientClass[client].isValid())
    clientClass[client].sendDisable(client);

  clientClass[client] = ClassID_Invalid;
}

void setClientClass(int client, ClassID classID) {
  if (clientClass[client].isValid())
    clientClass[client].sendDisable(client);

  clientClass[client] = classID

  if (clientClass[client].isValid())
    classID.sendEnable(client);
}

ClassID getClientClass(int client) {
  return clientClass[client];
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  CreateNative("Client.getClass", native_Client_getClass);
  CreateNative("Client.setClass", native_Client_setClass);
  return APLRes_Success;
}

public native_Client_getClass(Handle plugin, int numParams) {
  return view_as<int>(getClientClass(GetNativeCell(1)));
}

public native_Client_setClass(Handle plugin, int numParams) {
  setClientClass(GetNativeCell(1), GetNativeCell(2));
}
