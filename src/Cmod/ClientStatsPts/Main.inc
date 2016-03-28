static ClientStatsData data;

void clientStatsPtsStart() {
  data = new ClientStatsData();
}

void clientStatsPtsNative() {
  CreateNative("Client.freeStatsPts.get", native_Client_freeStatsPts_get);
  CreateNative("Client.freeStatsPts.set", native_Client_freeStatsPts_set);
  CreateNative("Client.getStatsPts", native_Client_getStatsPts);
  CreateNative("Client.setStatsPts", native_Client_setStatsPts);
  CreateNative("Client.getStatsAllPts", native_Client_getStatsAllPts);
  CreateNative("Client.recalculateStatsAllPts", native_Client_recalculateStatsAllPts);
  CreateNative("Client.spendStatsPts", native_Client_spendStatsPts);
  CreateNative("Client.resetStatsPts", native_Client_resetStatsPts);
  CreateNative("Client.resetAllStatsPts", native_Client_resetAllStatsPts);
}

public int native_Client_freeStatsPts_get(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  return client.freePts;
}

public int native_Client_freeStatsPts_set(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  client.freePts = GetNativeCell(2);
}

public int native_Client_getStatsPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  return client.getPts(GetNativeCell(2), GetNativeCell(3));
}

public int native_Client_setStatsPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  client.setPts(GetNativeCell(2), GetNativeCell(4), GetNativeCell(3));
}

public int native_Client_getStatsAllPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  return client.getAllPts(GetNativeCell(2));
}

public int native_Client_recalculateStatsAllPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  client.recalculateAllPts(GetNativeCell(2));
}

public int native_Client_spendStatsPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  return client.spendPts(GetNativeCell(2), GetNativeCell(3));
}

public int native_Client_resetStatsPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  client.resetPts(GetNativeCell(2));
}

public int native_Client_resetAllStatsPts(Handle plugin, int numParams) {
  ClientStats client = GetNativeCell(1);
  client.resetAllPts();
}
