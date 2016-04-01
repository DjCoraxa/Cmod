#include <sourcemod>
#include <cmod>

CmodStats cmodStats;

char cmd[][] = {
  "sm_stats",
  "sm_statystyki"
};

const int cmdCount = 2;

public void OnPluginStart() {
  for (int i = 0; i < cmdCount; ++i)
    RegConsoleCmd(cmd[i], cmd_showStatsMenu);
}

public Action cmd_showStatsMenu(int client, int argc) {
  Menu menu = new Menu(handler);

  Client cmodClient = view_as<Client>(client);

  int maxNameLength = cmodStats.maxNameLength;
  int finnalyStatsNameLength = maxNameLength + 32;

  char[] statsName = new char[maxNameLength + 1];
  char[] stringStatsID = new char[16];
  char[] statsFinnaly = new char[finnalyStatsNameLength + 1];

  StatsID maxStatsID = cmodStats.maxID;

  for (StatsID statsID = view_as<StatsID>(0); statsID < maxStatsID; ++statsID) {
    if (!statsID.isValid())
      continue;

    statsID.getName(statsName, maxNameLength);
    Format(statsFinnaly, finnalyStatsNameLength, "%s (%d)", statsName, cmodClient.getStatsAllPts(statsID));
    Format(stringStatsID, 15, "%d", statsID);
    menu.AddItem(stringStatsID, statsFinnaly);
  }

  menu.Display(client, 60);
}

public int handler(Menu menu, MenuAction action, int param1, int param2) {
/*  if (action == MenuAction_Select){
    Client client = view_as<Client>(param1);
    char[] info = new char[32];
    menu.GetItem(param2, info, 31)
    ClassID classID = view_as<ClassID>(StringToInt(info));
    client.setClass(classID);
	} else if (action == MenuAction_End) {
		menu.Close()
	}*/
}
