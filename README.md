# 15-445 Database Systems
# SQLite Project Source Code

### Build
```
mkdir build
cd build
cmake ..
make
```
Debug mode:

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### Testing
```
cd build
make check
```

### Run virtual table extension in SQLite
Start SQLite with:
```
cd build
./bin/sqlite3
```

In SQLite, load virtual table extension with:

```
.load ./lib/libvtable.dylib 
```
or load `libvtable.so` (Linux), `libvtable.dll` (Windows)

Create virtual table:

```
CREATE VIRTUAL TABLE foo USING vtable('a int, b bool')
```

See [Run-Time Loadable Extensions](https://sqlite.org/loadext.html) and [CREATE VIRTUAL TABLE](https://sqlite.org/lang_createvtab.html) for further information.

### Virtual table API
https://sqlite.org/vtab.html

### TODO
* update: when size exceed that page, table heap returns false and delete/insert tuple (rid will change and need to delete/insert from index)
* delete empty page from table heap when delete tuple
* implement delete table, with empty page bitmap in disk manager (how to persistent?)
* index: unique/dup key, variable key