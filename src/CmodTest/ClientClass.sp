#include <sourcemod>
#include <cmod>

ClassID testClass;

public void OnAllPluginsLoaded() {
  testClass = new ClassID("ClientClassTest");
  testClass.hookEnable(onClassEnable);
  testClass.hookDisable(onClassDisable);
  RegConsoleCmd("cmodtest_enableclass", cmd_cmodtest_enableclass);
  RegConsoleCmd("cmodtest_disableclass", cmd_cmodtest_disableclass);
  RegConsoleCmd("cmodtest_getclass", cmd_cmodtest_getclass);
}

public void OnPluginEnd() {
  testClass.remove();
}

public void onClassEnable(ClassID classID, int client) {
  PrintToChat(client, "Class enabled 0_0");
}

public void onClassDisable(ClassID classID, int client) {
  PrintToChat(client, "Class disabled -_-");
}

public Action cmd_cmodtest_enableclass(int client, int argc) {
  PrintToChat(client, "Enable class")
  ClientID cmodClient = view_as<ClientID>(1);
  cmodClient.setClass(testClass);
}

public Action cmd_cmodtest_disableclass(int client, int argc) {
  PrintToChat(client, "Disable class")
  ClientID cmodClient = view_as<ClientID>(1);
  cmodClient.setClass(ClassID_Invalid);
}

public Action cmd_cmodtest_getclass(int client, int argc) {
  ClientID cmodClient = view_as<ClientID>(1);
  PrintToChat(client, "class = %d", cmodClient.getClass());
}
