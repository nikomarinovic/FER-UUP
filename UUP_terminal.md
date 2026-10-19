# **Terminal i GCC: Mac i Windows**

Podsjetnik za prevođenje C programa i osnovne naredbe terminala na **macOS-u (Terminal)** i **Windowsima (CMD)**.

[⬅ Natrag na README](./README.md)

## **Sadržaj**

- [1. Prevedi program](#1-prevedi-program)
- [2. Pokreni](#2-pokreni)
- [Ručno kroz faze prevođenja](#ručno-kroz-faze-prevođenja)
- [Kretanje po mapama](#osnovne-naredbe-kretanje-po-mapama)
- [Datoteke i mape](#osnovne-naredbe-datoteke-i-mape)
- [Pregled sadržaja i ostalo](#osnovne-naredbe-pregled-sadržaja-i-ostalo)
- [Mini cheat sheet](#mini-cheat-sheet)

## **1. Prevedi program**

| | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Naredba** | `gcc -std=c11 -pedantic-errors -Wall hello.c -o hello` | `gcc -std=c11 -pedantic-errors -Wall hello.c -o hello.exe` |
| **Nastaje** | `hello` | `hello.exe` |

## **2. Pokreni**

| | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Naredba** | `./hello` | `hello` ili `hello.exe` |
| **Rezultat** | `Hello world!` | `Hello world!` |

## **Ručno kroz faze prevođenja**

| **Faza** | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **1. Preprocesiranje** (`hello.i`) | `gcc -E hello.c -o hello.i` | `gcc -E hello.c -o hello.i` |
| **2. C → Assembly** (`hello.s`) | `gcc -S hello.c -o hello.s` | `gcc -S hello.c -o hello.s` |
| **3. Assembly → Object** (`hello.o`) | `gcc -c hello.s -o hello.o` | `gcc -c hello.s -o hello.o` |
| **4. Object → izvršni program** | `gcc hello.o -o hello` | `gcc hello.o -o hello.exe` |
| **5. Pokretanje** | `./hello` | `hello.exe` |

> Faze 1 do 3 su iste na oba sustava. Razlika je samo u izvršnoj datoteci (`hello` naspram `hello.exe`) i u pokretanju.

## **Osnovne naredbe: kretanje po mapama**

| **Što radiš** | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Gdje sam** | `pwd` | `cd` |
| **Popis datoteka** | `ls` | `dir` |
| **Popis sa skrivenim i detaljima** | `ls -la` | `dir /a` |
| **Uđi u mapu** | `cd mapa` | `cd mapa` |
| **Jedna mapa gore** | `cd ..` | `cd ..` |
| **Kućna mapa** | `cd ~` | `cd %USERPROFILE%` |
| **Vrh diska** | `cd /` | `cd \` |
| **Očisti ekran** | `clear` | `cls` |

## **Osnovne naredbe: datoteke i mape**

| **Što radiš** | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Nova mapa** | `mkdir mapa` | `mkdir mapa` |
| **Nova prazna datoteka** | `touch dat.txt` | `type nul > dat.txt` |
| **Kopiraj datoteku** | `cp dat.txt kopija.txt` | `copy dat.txt kopija.txt` |
| **Kopiraj u mapu** | `cp dat.txt mapa/` | `copy dat.txt mapa\` |
| **Kopiraj cijelu mapu** | `cp -r mapa1 mapa2` | `xcopy mapa1 mapa2 /E /I` |
| **Premjesti datoteku** | `mv dat.txt mapa/` | `move dat.txt mapa\` |
| **Preimenuj** | `mv staro.txt novo.txt` | `ren staro.txt novo.txt` |
| **Obriši datoteku** | `rm dat.txt` | `del dat.txt` |
| **Obriši praznu mapu** | `rmdir mapa` | `rmdir mapa` |
| **Obriši mapu sa sadržajem** | `rm -r mapa` | `rmdir /s mapa` |

> ⚠️ **Pazi:** `rm` i `del` brišu trajno, nema koša. Na Macu `rm -i dat.txt` prije brisanja pita za potvrdu, a `cp -i` štiti od prepisivanja.

## **Osnovne naredbe: pregled sadržaja i ostalo**

| **Što radiš** | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Ispiši sadržaj datoteke** | `cat dat.txt` | `type dat.txt` |
| **Listaj datoteku po stranicama** | `less dat.txt` | `more dat.txt` |
| **Traži tekst u datoteci** | `grep "tekst" dat.txt` | `findstr "tekst" dat.txt` |
| **Ispiši tekst** | `echo tekst` | `echo tekst` |
| **Gdje je program** | `which gcc` | `where gcc` |
| **Pomoć za naredbu** | `man gcc` | `gcc --help` |
| **Otvori mapu u pregledniku** | `open .` | `start .` |
| **Otvori datoteku** | `open dat.txt` | `start dat.txt` |
| **Prekini program koji radi** | `Ctrl + C` | `Ctrl + C` |

## **Mini cheat sheet**

| | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| **Napravi folder** | `mkdir -p ~/UPRO` | `mkdir C:\UPRO` |
| **Uđi u folder** | `cd ~/UPRO` | `cd C:\UPRO` |
| **Popis datoteka** | `ls` | `dir` |
| **Očisti ekran** | `clear` | `cls` |
| **Trenutna mapa** | `pwd` | `cd` |
| **Provjeri GCC** | `gcc --version` | `gcc --version` |
| **Prevedi** | `gcc -std=c11 -pedantic-errors -Wall hello.c -o hello` | `gcc -std=c11 -pedantic-errors -Wall hello.c -o hello.exe` |
| **Pokreni** | `./hello` | `hello.exe` |
| **Obriši izvršnu** | `rm hello` | `del hello.exe` |

---

*FER · Uvod u programiranje*