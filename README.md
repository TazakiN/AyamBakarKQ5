# AyamBakarKQ5

## cara pake makefile

tinggal "make"
nah jangan lupa di folder bin harus ada folder yang udah kita bikin di src. kalo ga ada, makefile ga bakal jalan

Misal:

```
AyamBakarKQ5/
├── config/
│   └── ...
├── bin/
│   ├── utils/      <-- harus ada
│   │   └── ...
│   └── main.o
├── src/
│   ├── main.cpp
│   └── utils/
│       ├── readFile.cpp
│       └── readFile.h
├── .gitignore
├── main.exe
├── makefile
└── README.md
```

nah kita harus bikin folder utils di bin, sama kek di src. kalo ga ada, makefile ga bakal jalan
