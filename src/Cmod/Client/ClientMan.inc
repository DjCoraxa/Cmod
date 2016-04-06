methodmap ClientMan {
  public Client getClientByExpID(ExpID expID) {
    for (Client client = Client_First; client <= view_as<Client>(MaxClients); ++client)
      if (client.expID == expID)
        return client;
    return Client_Invalid;
  }
};
