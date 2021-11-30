var id = parseInt(msg.payload.id);

msg.topic = "UPDATE fallTable SET fall = 'True' WHERE id = " + id + ";" 

return msg;