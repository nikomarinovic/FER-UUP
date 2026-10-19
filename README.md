# **FER-UUP**

Zbirka primjera, riješenih zadataka i materijala za kolegij **Uvod u programiranje (UUP)** na FER-u.

## **Sadržaj**

| **Mapa** | **Opis** |
| --- | --- |
| [`01-Predavanja/`](./01-Predavanja/) | Primjeri i kodovi obrađeni na predavanjima |
| [`02-Vjezbe-uz-predavanja/`](./02-Vjezbe-uz-predavanja/) | Riješeni zadaci s vježbi uz predavanja |
| [`03-Laboratorijske-vjezbe/`](./03-Laboratorijske-vjezbe/) | Zadaci i pripreme za laboratorijske vježbe |
| [`04-Dodatni-zadaci/`](./04-Dodatni-zadaci/) | Dodatni zadaci za vježbu i samostalno rješavanje |
| [`UUP_terminal.md`](./UUP_terminal.md) | Podsjetnik za terminal i GCC (macOS i Windows) |

## **Tehnologije**

- C
- GCC
- Visual Studio Code

## **Korištenje**

Repozitorij možeš preuzeti klikom na **Code → Download ZIP** ili klonirati pomoću Gita:

```sh
git clone <URL-repozitorija>
```

Kod je organiziran po vrstama nastavnih materijala kako bi se zadaci lakše pronašli. Za pokretanje programa potrebno je imati instaliran GCC ili drugi C kompajler.

### **Kompajliranje i pokretanje**

U naredbama zamijeni `program.c` imenom C datoteke koju želiš pokrenuti.

| **Faza** | **macOS (Terminal)** | **Windows (CMD)** |
| --- | --- | --- |
| Provjera kompajlera | `gcc --version` | `gcc --version` |
| Kompajliranje | `gcc -std=c11 -pedantic-errors -Wall program.c -o program` | `gcc -std=c11 -pedantic-errors -Wall program.c -o program.exe` |
| Pokretanje | `./program` | `program.exe` |

> 📖 Treba ti pomoć s terminalom (kretanje po mapama, kopiranje, brisanje, faze prevođenja)? Pogledaj **[podsjetnik za terminal i GCC](./UUP_terminal.md)**.

## **Napomena**

Ovaj repozitorij služi za učenje, ponavljanje gradiva i razmjenu znanja među studentima.

Ako pronađeš grešku ili imaš prijedlog za poboljšanje, slobodno doprinesi svojim rješenjem.

---

*FER · Uvod u programiranje*