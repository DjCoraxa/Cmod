#include <sourcemod>
#include <cmod/Item>

static ItemID clientItem[MAXPLAYERS + 1] = {ItemID_Invalid, ...};

public void OnClientDisconnect(int client) {
  if (clientItem[client].isValid())
    clientItem[client].sendDisable(client);

  clientItem[client] = ItemID_Invalid;
}

void setClientItem(int client, ItemID itemID) {
  if (clientItem[client].isValid())
    clientItem[client].sendDisable(client);

  clientItem[client] = itemID;

  if (clientItem[client].isValid())
    itemID.sendEnable(client);
}

ItemID getClientItem(int client) {
  return clientItem[client];
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  CreateNative("Client.getItem", native_Client_getItem);
  CreateNative("Client.setItem", native_Client_setItem);
  return APLRes_Success;
}

public native_Client_getItem(Handle plugin, int numParams) {
  return view_as<int>(getClientItem(GetNativeCell(1)));
}

public native_Client_setItem(Handle plugin, int numParams) {
  setClientItem(GetNativeCell(1), GetNativeCell(2));
}
