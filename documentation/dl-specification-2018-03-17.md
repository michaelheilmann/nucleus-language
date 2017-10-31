# Data Description Language
Ein DDL-Text ist eine Folge von Wörtern. Die Menge der Wörter umfasst die Wörter von 6 strukturellen Zeichen, die Wörter von drei Konstantenliteralen, die Wörter der Literale, die Zeichenkettenwerte bezeichnen,  und die Wörter der Literale, die Zahlenwerte bezeichnen.
### Strukturelle Zeichen
Die Wörter der 6 strukturellen Zeichen sind folgende:

Der öffnende Listenbegrenzer ist `[` (engl. left square bracket, dt. linke eckige Klammer, Unicode: `U+005B`)
```
<öffnender-Listenbegrenzer> := '['
```
Der schließende Listenbegrenzer ist `]` (engl. right square bracket, dt. rechte eckige Klammer, Unicode: `U+005D`)
```
<schließender-Listenbegrenzer> := ']'
```
Der öffnende Strukturbegrenzer ist `{` (engl. left curly bracket, dt. linke geschweifte Klammer, Unicode: `U+007B`)
```
<öffnender-Strukturbegrenzer> := '{'
```
Der schließende Strukturbegrenzer ist `}` (engl. right curly bracket, dt. rechte geschweifte Klammer, Unicode: `U+007D`)
```
<schließender-Strukturbegrenzer> := '}'
```
Der Zuweisungsoperator (für Strukturelemente) ist `:` (engl. colon, dt. Doppelpunkt, Unicode: `U+003A`)
```
<Strukturelementzuweisungsoperator> := ':'
```
Das Trennzeichen (für Ausdrücke) ist `,` (engl. comma, dt. Komma, Unicode: `U+002C`)
```
<Werttrennzeichen> := ','
```
## Konstantenliterale

Die Wörter der Literale, welche die Werte true, false, und null bezeichnen, sind folgende:
Das "logisch falsch" Literal
```
<falsch> := 'false'
```
Der "logisch wahr" Literal
```
<wahr> := 'true'
```
Das "null" Literal
```
<null> := 'null'
```
## Zeichenkettenliterale
Zeichenkettenliteral beginnen und enden mit `"` (engl. quotation mark, dt. Anführungszeichen, Unicode: `U+0022`). Alle Unicodezeichen dürfen zwischen den Anführungszeichen plaziert werden, mit der Ausname der Zeichen, die eskapiert werden müssen. Diese sind `"` (engl. quotation mark, dt. Anführungszeichen, Unicode: `U+0022`), `\` (engl. reverse solidus, dt. umgekehrter Solidus, Unicode: `U+005C`), sowie die Kontrollzeichen (Unicode: von einschließlich `U+0000` bis einschließlich `U+001F`).

## Zahlenliterale
Die Ziffernfolge ist zur Basis 10 zu interpretieren.
Es wird zwischen Integerzahlen und Realzahlen unterschieden.

```
<Zahl> := <Integerzahl>
        | <Realzahl>
```

In den Definitionen von `<Integerzahl>` und `<Realzahl>` werden folgen von Ziffern verwendet.
Es wird zwischen zwei Folgen von Ziffern unterschieden:

Die Ziffernfolge ohne führende 0en besteht entweder
- aus der 0 oder
- aus ein Ziffer ungleich der 0 gefolgt von 1 oder mehreren Ziffern.
 
```
<Ziffern-o-führenden-Nullen> := '0' | (<Ziffern> - '0') <Ziffer>*
```

Di Ziffernfolge mit führenden 0en besteht aus
1 oder mehreren Ziffern.

```
<Ziffern-m-führenden-Nullen> := <Ziffern>+
```

### Integerzahl

Eine Integerzahl besteht aus einem optionalen Vorzeichen, gefolgt einer oder mehreren Ziffern ohne führende Nullen,
gefolgt von einem optionalen Exponenten..

```
<Integerzahl> := <Vorzeichen>? <Ziffern-o-führende-Nullen> <Exponent>?
```

### Realzahlen

Eine Realzahl besteht aus einem optionalen Vorzeichen.
Es folgen entweder
- 1 oder mehreren Ziffern ohne führende 0en, ein Punkt, sowie 0 oder mehrere Ziffern oder
- ein Punkt, sowie 1 oder mehrere Ziffern.
In beiden Fällen kann ein Exponent folgen.

```
<Realzahl> := <Vorzeichen>?
              (<Ziffern-o-führende-Nullen> '.' <Ziffern-m-führenden-Nullen>? | '.' <Ziffer-m-führenden-Nullen>)
              <Exponent>?
```

### Vorzeichen
Ein Vorzeichen ist ein Plus- oder Minuszeichen.

```
<Vorzeichen> := ('+'|'-')
```

### Exponent

Der Exponententeil beginnt mit dem Buchstaben E in Groß- oder Kleinschreibung,
dem ein Plus- oder Minuszeichen folgen kann. Es folgen ein oder mehrere Ziffern,
wobei führende Nullen nicht gestattet sind.

```
<Exponententeil> := <Exponentenzeichen><Vorzeichen>?<Ziffern-o-führende-Nullen>
<Exponentenzeichen> := ('E'|'e')
```