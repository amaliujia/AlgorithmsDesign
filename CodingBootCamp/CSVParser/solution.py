def parseCVS(input):
  res = list()
  isQuote = False
  buffer = ""

  for i in range(0, len(input)):
    if isQuote:
      if input[i] == '"':
        if input[(i+1)] == '"':
          buffer += '"'
        else:
          isQuote = False
      else:
          buffer += input[i]
    else:
      if input[i] == '"':
           isQuote = True
      elif input[i] == ',':
          res.append(buffer) 
          buffer = ""
      else:
          buffer += input[i]

  if len(buffer) != 0:
    res.append(buffer)
  
  c = ""
  for i in range(0, len(res) - 1):
    c += res[i]
    c += '|'

  c += res[len(res) - 1]
  print c



if __name__ == '__main__':
  parseCVS("\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1")
