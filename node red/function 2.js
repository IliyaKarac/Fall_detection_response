
var id = parseInt(msg.payload.id);

msg.topic = "DELETE FROM fallTable WHERE id=" + id + ";"  

return msg;