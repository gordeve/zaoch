import requests

url = "https://olympiads.ru/zaoch/2021-22/standings_short.html"
r = requests.get(url, allow_redirects=True)
open('short.html', 'wb').write(r.content)

url = "https://olympiads.ru/zaoch/2021-22/standings.html"
r = requests.get(url, allow_redirects=True)
open('stand.html', 'wb').write(r.content)