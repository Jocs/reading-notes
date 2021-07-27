```python
import sqlite3, re
def convert(val):
  if re.search(r'\d', val):
    return float(val)
  return val.strip('\n')
conn = sqlite3.connect('food4.db')
cur = conn.cursor()
cur.execute('''
  CREATE TABLE food (
    id TEXT PRIMARY KEY,
    name TEXT,
    age FLOAT,
    job TEXT
  )
''')
query = 'INSERT INTO food VALUES (?,?,?,?)'
for line in open('./test.txt'):
  fields = line.split(' ')
  vals = [convert(f) for f in fields]
  print vals
  cur.execute(query, vals)
conn.commit()
conn.close()
```