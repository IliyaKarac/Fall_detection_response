
import paho.mqtt.client as mqtt
import time
import requests

def response(client, userdata, msg):
    print("Recived: " + msg.payload.decode())
    if msg.payload.decode() == "fall detected":
        print("Calling Emergency services")
        
        id_ = 2
        name = "john doe"
        address = "456 anywhere cresent"
        parameters = {"id":id_, "name":name, "address":address}
        r = requests.put("https://www.falldetectionresponse.ca:1880/fall_detected", data = parameters, verify=False)
        print(r)
        #put the PUT request here



client = mqtt.Client("Subscriber")
client.on_message = response

#server = "192.168.102.34"
server = "broker.mqtt-dashboard.com"



print("Connected to local mqtt server")
client.connect(server,1883)

client.subscribe("User_falls")

try: 
    client.loop_forever()


except:
        print("disconnect")

client.disconnect()