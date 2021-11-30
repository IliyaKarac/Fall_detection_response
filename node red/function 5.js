
name = msg.payload.name
address = msg.payload.address


msg.payload = name + " from " + address + " says: Help! I've fallen and I can get up!";
return msg;