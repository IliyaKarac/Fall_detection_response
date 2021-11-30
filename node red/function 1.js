

var fall = msg.payload.fall;
var address = msg.payload.address;
var id = parseInt(msg.payload.id);
var name = msg.payload.name;

var address2 = "'" + address + "'";
var fall2 = "'" + fall + "'";
var name2 = "'" + name + "'";


msg.topic = "INSERT INTO fallTable VALUES (" + id + ", " + name2 + ", " + address2+ ", " + fall2 +");"
return msg;