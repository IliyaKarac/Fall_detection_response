var fall = msg.payload.fall;
var address = msg.payload.address;
var id = parseInt(msg.payload.id);
var name = msg.payload.name;

var address2 = "'" + address + "'";
var fall2 = "'" + fall + "'";
var name2 = "'" + name + "'";

 msg.topic ="UPDATE fallTable SET name =" + name2 + " ,address = " + address2 + " ,fall = " + fall2 + "WHERE id = " + id + ";" 
   


//msg.topic = "SELECT * FROM `fallTable`"  

return msg;