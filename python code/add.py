import requests


id_ = input("Enter Id: ")

name = raw_input("Enter Name: ")

street = raw_input("Enter Street: ")

fall = "False";

#json = '{ "id":' + str(id_) + ', "name":' + name + ', "address":' + street + ', "fall":' + str(fall) + ' }'
parameters = {"id":id_, "name":name, "address":street, "fall":fall}

print(parameters)




r = requests.post("https://www.falldetectionresponse.ca:1880/add", data = parameters, verify=False)
print(r.url)