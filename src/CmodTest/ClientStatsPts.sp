#include <sourcemod>
#include <cmod>

public void OnPluginStart() {
  RegConsoleCmd("cmodtest_clientstatspts", cmd_cmodtest_clientstatspts);
}

public Action cmd_cmodtest_clientstatspts(int client, int argc) {
  ClientID cmodClient = view_as<ClientID>(1);
  PrintToServer("ClientID cmodClient = 1");

  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);
  cmodClient.freeStatsPts = 69;
  PrintToServer("cmodClient.freeStatsPts = 69")
  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);

  StatsID stats = new StatsID("happy");
  PrintToServer("StatsID stats = new StatsID(\"happy\")");
  PrintToServer("cmodClient.getStatsPts(stats) return %d", cmodClient.getStatsPts(stats));
  cmodClient.setStatsPts(stats, 12);
  PrintToServer("cmodClient.setStatsPts(stats, 12)")
  PrintToServer("cmodClient.getStatsPts(stats) return %d", cmodClient.getStatsPts(stats));

  PrintToServer("cmodClient.getStatsAllPts(stats) return %d", cmodClient.getStatsAllPts(stats));
  cmodClient.setStatsPts(stats, 123, ClientPts_Bonus);
  PrintToServer("cmodClient.setStatsPts(stats, 123, ClientPts_Bonus)");
  PrintToServer("cmodClient.getStatsAllPts(stats) return %d", cmodClient.getStatsAllPts(stats));
  cmodClient.recalculateStatsAllPts(stats);
  PrintToServer("cmodClient.recalculateStatsAllPts(stats)");
  PrintToServer("cmodClient.getStatsAllPts(stats) return %d", cmodClient.getStatsAllPts(stats));

  PrintToServer("cmodClient.getStatsPts(stats) return %d", cmodClient.getStatsPts(stats));
  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);
  PrintToServer("cmodClient.spendStatsPts(stats, 3) return %d", cmodClient.spendStatsPts(stats, 3));
  PrintToServer("cmodClient.getStatsPts(stats) return %d", cmodClient.getStatsPts(stats));
  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);

  PrintToServer("cmodClient.spendStatsPts(stats, 999999) return %d", cmodClient.spendStatsPts(stats, 999999));
  PrintToServer("cmodClient.getStatsPts(stats) return %d", cmodClient.getStatsPts(stats));
  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);

  cmodClient.resetStatsPts(stats)
  PrintToServer("cmodClient.resetStatsPts(stats)");
  PrintToServer("cmodClient.freeStatsPts return %d", cmodClient.freeStatsPts);

  cmodClient.freeStatsPts = 0;
  PrintToServer("cmodClient.freeStatsPts = 0")

  stats.remove();
  PrintToServer("stats.remove()");
}
