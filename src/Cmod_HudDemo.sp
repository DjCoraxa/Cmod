#include <sourcemod>
#include <cmod>

const float timerInterval = 1.0;

static Handle clientTimer[MAXPLAYERS + 1];
static char clientClassName[MAXPLAYERS + 1][64];
static char clientItemName[MAXPLAYERS + 1][64];
static char clientHudContent[MAXPLAYERS + 1][1024];

public void OnClientPutInServer(int client) {
  clientTimer[client] = CreateTimer(timerInterval, timerShowHud, client, TIMER_REPEAT);
}

public void OnClientDisconnect(int client) {
  KillTimer(clientTimer[client]);
}

public Action timerShowHud(Handle timer, any data) {
  if (!IsClientInGame(data) || !IsPlayerAlive(data))
    return;

  Client client = view_as<Client>(data);

  ClassID classID = client.getClass();
  if(classID.isValid())
    classID.getName(clientClassName[data], 63);
  else
    Format(clientClassName[data], 63, "None");

  ItemID itemID = client.getItem();
  if (itemID.isValid())
    itemID.getName(clientItemName[data], 63);
  else
    Format(clientItemName[data], 63, "None");

  ExpID clientExpID = client.expID;

  Format(clientHudContent[data], 1023, "[Class: %s]\n[LVL: %i / %i][Exp: %i / %i]\n[Item: %s]", clientClassName[data], clientExpID.lvl, clientExpID.maxLvl, clientExpID.exp, clientExpID.getExpForLvl(clientExpID.lvl), clientItemName[data]);

  PrintHintText(data, "%s", clientHudContent[data]);
}
