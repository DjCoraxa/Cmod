#include <sourcemod>
#include <cmod>
#include <cmod/version>

public Plugin myinfo = {
  name = "Cmod_SimpleClassChooser",
  author = "plx211",
  description = "Simple menu with class to choose",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

static CmodClass cmodClass;

char cmd[][] = {
  "sm_class",
  "sm_klasa"
};

const int cmdCount = 2;

public void OnPluginStart() {
  for (int i = 0; i < cmdCount; ++i)
    RegConsoleCmd(cmd[i], cmd_showClassMenu);

  HookEvent("player_spawn", Event_PlayerSpawn);
}
public int Event_PlayerSpawn(Handle event, char[] name, bool dontbroadcast)
{
  int userid = GetClientOfUserId(GetEventInt(event, "userid"));
  ClientID client = view_as<ClientID>(userid);
  if(client.getClass() == ClassID_Invalid)
    FakeClientCommand(client, "sm_klasa");
  return Plugin_Handled;
}
public Action cmd_showClassMenu(int client, int argc) {
  Menu menu = new Menu(handler);

  int maxNameLength = cmodClass.maxNameLength;
  char[] className = new char[maxNameLength + 1];
  char[] stringClassID = new char[16];
  ClassID maxClassID = cmodClass.maxID;

  for (ClassID classID = view_as<ClassID>(0); classID < maxClassID; ++classID) {
    if (!classID.isValid())
      continue;

    classID.getName(className, maxNameLength);
    Format(stringClassID, 15, "%d", classID);
    menu.AddItem(stringClassID, className);
  }
  menu.SetTitle("Cmod -> Wybierz klasę");
  menu.Display(client, 60);
}

public int handler(Menu menu, MenuAction action, int param1, int param2) {
  if (action == MenuAction_Select){
    ClientID client = view_as<ClientID>(param1);
    char[] info = new char[32];
    menu.GetItem(param2, info, 31)
    ClassID classID = view_as<ClassID>(StringToInt(info));
    if(client.getClass() == ClassID_Invalid)
    {
      client.setClass(classID);
      client.giveWeapons();
    }
    else
      client.setClass(classID);
	} else if (action == MenuAction_End) {
		menu.Close()
	}
}
