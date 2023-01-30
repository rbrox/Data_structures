import json
import requests
import sys

def main():
    
    if len(sys.argv) != 2:
        sys.exit('Missing command-line argument')
        
    response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")        
    print (json.dumps(response.json(), indent= 4))
    
main()