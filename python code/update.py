import requests


id_ = input("Enter Id: ")

name = raw_input("Enter Name: ")

street = raw_input("Enter Street: ")

fall = raw_input("Enter fall status: ")

parameters = {"id":id_, "name":name, "address":street, "fall":fall}

print(parameters)

r = requests.put("https://www.falldetectionresponse.ca:1880/put", data = parameters, verify=False)
print(r.url)