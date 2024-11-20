# Tundra Ökoszisztéma Szimulátor

Komplex populációdinamikai szimulátor, amely modellezi a tundra ragadozó és zsákmányállat kolóniák közötti kölcsönhatásokat. A program nyomon követi a különböző fajok egyedszámának változását és a köztük lévő interakciókat.

## Működés

### Populációk
#### Ragadozók
- **Hóbagoly**: 4 egyedenként 1 utód minden 8. körben
- **Sarki róka**: 4 egyedenként 3 utód minden 8. körben
- **Farkas**: 4 egyedenként 2 utód minden 8. körben

#### Zsákmányállatok
- **Lemming**
  - 4x egyedszám csökkenés vadászatnál
  - Duplázódás minden 2. körben
  - 200 fölött → 30-ra csökken
- **Sarki nyúl**
  - 2x egyedszám csökkenés vadászatnál
  - 1.5x növekedés minden 2. körben
  - 100 fölött → 20-ra csökken
- **Ürge**
  - 2x egyedszám csökkenés vadászatnál
  - Duplázódás minden 4. körben
  - 200 fölött → 40-ra csökken

### Szimuláció menete
1. Ragadozók véletlenszerű vadászata
2. Populációk változásának számítása
3. Automatikus populáció korrekciók
4. Körönkénti státusz kijelzés

## Használat

### Bemenet formátuma
```txt
[zsákmánykolóniák_száma] [ragadozókolóniák_száma]
[becenév] [faj_azonosító] [egyedszám]
[becenév] [faj_azonosító] [egyedszám]
...
```

Faj azonosítók:
- h: hóbagoly
- s: sarki róka
- f: farkas
- l: lemming
- n: nyúl
- u: ürge

### Példa bemenet
```txt
2 1
LemmingKolonia l 150
NyulKolonia n 80
HobagolyKolonia h 20
```

## Tesztesetek

1. Üres bemenet
2. Csak zsákmányállatok
3. Csak ragadozók
4. Egy ragadozó, több zsákmány
5. Több ragadozó, egy zsákmány
6. Minden fajból egy-egy kolónia

## Kilépési feltételek

A szimuláció véget ér, ha:
- Minden ragadozó kolónia egyedszáma 4 alá csökken
- A ragadozók összesített száma megduplázódik a kezdeti értékhez képest
