import requests

id_ = input("Enter Id: ")
parameters = {"id":id_}

r = requests.delete("https://www.falldetectionresponse.ca:1880/delete", data = parameters, verify=False)
print(r.url)