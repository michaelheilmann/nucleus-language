# Data Description Language

## Einführung
Die Data Language ist eine Datenbeschreibungsspache. Ihr Zweck ist die Kommunikation von
hierarchischen, typisierten Daten zwischen
- Menschen bzw.
- Maschinen bzw.
- Menschen und Maschinen und Maschinen und Menschen.

Für eine erfolgreiche Kommunikation von Daten müssen Programme der Sprache Regeln einhalten.
Programme, die diese Regelne einhalten, werden als gültig (valid) bezeichnet.
Programme, die diese Regeln nicht einhalten, werden als ungültig (invalid) bezeichnet.
Dieses Dokument spezifiziert die Data Language durch
lexikalische, syntaktische, und semantische Regeln
nach denen Programme als gültig bzw. ungültig klassifiziert werden.

Ein Prozess, der ein Programm als lexikalisch bzw. syntaktisch bzw. semantisch
gültig bzw. ungültig klassifiziert, wird als lexikalische, syntaktische, bzw.
semantische Analyse bezeichnet.

## Aufbau dieser Spezifikation
- Das erste Kapitel beschreibt die lexikalische
  Ebene der Data Language.
- Das zweite Kapitel beschreibt die syntaktische
  Ebene der Data Language.
- Das dritte Kapitel beschreibt die semantische
  Ebene der Data Language.

## Lexikalische Spezifikation
Dieses Kapitel spezifiziert die Data Language auf lexikalischer Ebene.

Die Eingabe der lexikalischen Analyse sind Programme als Folgen von Bytes.
- Die Folgen von Bytes werden in Folgen von Unicode Codepunkten transformiert
  (s. "Lexikalische Analyse Stufe 1: Bytes in Unicode Codepunkte").
- Die Folgen von Unicode Codepunkten werden in Folgen von Unicode Zeichen transformiert
  (s. "Lexikalische Analyse Stufe 2: Unicode Codepunkte in Unicode Zeichen").
- Die Folgen von Unicode Zeichen werden in Folgen von Token transformiert
  (s. "Lexikalische Analyse Stufe 3: Unicode Zeichen in Tokens").
Die Ausgabe der lexikalischen Analyse sind Programme als Folgen von Tokens.

### Lexikalische Analyse Stufe 1: Bytes in Unicode Codepunkte
Die Eingabe der lexikalischen Analyse der ersten Stufe sind Programme als Folgen von Bytes.
Die lexikalische Analyse der ersten Stufe übersetzt diese Folgen von Bytes in Folgen von Unicode Codepunkten unter einer Unicode Zeichenkodierung.
Nicht jede Eingabe dieser Stufe der lexikalischen Analyse ist ein wohlgeformtes Programm da nicht jede Folge von Bytes eine gültige Folge von Unicode Codepunkten darstellt.
**BEMERKUNG: Der Grund hierfür ist, dass nicht jeder Folge von Bytes eine Folge von Unicode-Codepunkten zugeordnet ist.**

- *Informationen über Unicode können unter (https://www.unicode.org/)[https://www.unicode.org/] abgerufen werden.*
- *Die einzige Zeichenkodierung, die ein DL-Übersetzer unterstützen muss, ist UTF-8.*

### Lexikalische Analyse Stufe 2: Unicode Codepunkte in Unicode Zeichen
Die Eingabe der lexikalischen Analyse der zweiten Stufe sind Programme als Folgen von Unicode Codepunkten.
Die lexikalische Analyse der zweiten Stufe übersetzt diese Folgen von Unicode Codepunkten in Folgen von Unicode Zeichen.
Nicht jede Eingabe dieser Stufe der lexikalischen Analyse ist ein wohlgeformtes Programm da nicht jede Folge von Unicode Codepunkten eine gültige Folge von Unicode Zeichen darstellt.
**BEMERKUNG: Der Grund hierfür ist, dass nicht jedem Unicode-Codepunkt ist ein Unicode-Zeichen zugeordnet ist.**

### Lexikalische Analyse Stufe 3: Unicode Zeichen in Tokens
Die Eingabe der lexikalischen Analyse der dritten Stufe sind Programme als Folgen von Unicode Zeichen.
Die lexikalische Analyse der dritten Stufe übersetzt diese Folgen von Unicode Zeichen in Tokens.
Nicht jede Eingabe dieser Stufe der lexikalischen Analyse dieser Stufe ist ein wohlgeformtes Programm da nicht jede Folge von Unicode Zeichen eine gültige Folge von Tokens darstellt.
**BEMERKUNG: Der Grund hierfür ist, dass nicht jeder Folge von Unicode Zeichen ein Token zugeordnet ist.**

In diesem Dokument sind die Begriffe Zeichen und Unicode Zeichen Synonyme. 
Um Unicode-Zeichen eindeutig zu identifizieren wird der Wert des Unicode-Codepunktes des Zeichens angegeben.

#### Zeilenterminatoren
Programme wird in Zeilen anhand von Zeilenterminatoren zerlegt.
Zeilenterminatoren sind die Zeichen `U+000A` (dt. Zeilenumbruch, engl. line feed) bzw.
`U+000D` (dt. Wagenrücklauf, engl. carriage return) bzw. `U+000D` unmittelbar gefolgt
von `U+000D`.

``` 
lineTerminator : lineFeed
               | carriageReturn
               | carriageReturn lineFeed
lineFeed : das Zeichen U+000A
carriageReturn : das Zeichen U+000D
```

Das Ergebnis ist eine Folge von Zeilenterminatoren und Eingabezeichen.
```
inputSymbol : jedes Zeichen mit der Ausnahme von lineFeed oder carriageReturn
```

*Die Zeilen, die durch die Zeilenterminatoren definiert werden, dürfen die Zeilennummern definieren, die durch durch einen Übersetzer produziert werden.*

#### Strukturelle Zeichen
Die Wörter der 6 strukturellen Zeichen sind folgende:

Der öffnende Listenbegrenzer ist `[` (engl. left square bracket, dt. linke eckige Klammer, Unicode: `U+005B`)
```
ListOpeningDelimitier : '['
```
Der schließende Listenbegrenzer ist `]` (engl. right square bracket, dt. rechte eckige Klammer, Unicode: `U+005D`)
```
ListClosingDelimiter : ']'
```
Der öffnende Strukturbegrenzer ist `{` (engl. left curly bracket, dt. linke geschweifte Klammer, Unicode: `U+007B`)
```
StructureOpeningDelimiter : '{'
```
Der schließende Strukturbegrenzer ist `}` (engl. right curly bracket, dt. rechte geschweifte Klammer, Unicode: `U+007D`)
```
StructureClosingDelimiter : '}'
```
Der Zuweisungsoperator (für Strukturelemente) ist `:` (engl. colon, dt. Doppelpunkt, Unicode: `U+003A`)
```
Colon : ':'
```
Das Trennzeichen (für Ausdrücke) ist `,` (engl. comma, dt. Komma, Unicode: `U+002C`)
```
Comma : ','
```

#### Konstantenliterale
Die Wörter der Literale, welche die Werte true, false, und null bezeichnen, sind folgende:
Das "logisch falsch" Literal
```
False : 'false'
```
Das "logisch wahr" Literal
```
True : 'true'
```
Das "null" Literal
```
Null : 'null'
```

#### Zeichenkettenliterale
Zeichenkettenliteral beginnen und enden mit `"` (engl. quotation mark, dt. Anführungszeichen, Unicode: `U+0022`).
Alle Unicodezeichen dürfen zwischen den Anführungszeichen plaziert werden, mit der Ausname der Zeichen, die eskapiert werden müssen.
Diese sind `"` (engl. quotation mark, dt. Anführungszeichen, Unicode: `U+0022`), `\` (engl. reverse solidus, dt. umgekehrter Solidus, Unicode: `U+005C`), sowie die Kontrollzeichen (Unicode: von einschließlich `U+0000` bis einschließlich `U+001F`).

```
String
```

#### Zahlenliterale
DL unterstützt Integerzahlen und Realzahlen.
```
Number : Integer
       | Real
```

Jede folge von Ziffern ist zur Basis 10 zu interpretieren.

Den Definitionen von Integerzahlen und Realzahlen sind folgende Regeln gemein

##### Vorzeichen
Ein Vorzeichen (engl. sign) ist entweder ein `+` (Unicode: U+002B) oder ein `-` (Unicode: U+002D)
```
Sign : '+'
     | '-'
```

##### Exponent
Ein Exponent (engl. exponent) ist wie folgt definiert:

- Der Buchstaben E in Groß- oder Kleinschreibung, dem ein Vorzeichen folgen kann.
Es folgen ein oder mehrere Ziffern, wobei führende Nullen nicht gestattet sind.

```
Exponent : ExponentIndicator Sign? (Digit - Zero) Digit*
```
- Der Buchstabe E in Groß- oder Kleinschreibung, dem ein Vorzeichen folgen kann.
Es folgt die Ziffer `0`.
```
Exponent : ExponentIndicator Sign? Zero
ExponentIndicator : 'e'
                  / 'E'
```

##### Integerzahl
Ein Integerzahl ist wie folgt definiert:

- Ein optionales Vorzeichen gefolgt von einer Ziffer ungleich der Ziffer `0`  gefolgt von 0 oder mehr Ziffern.
```
Integer : Sign? (Digit - Zero) Digit*
```

- Ein optionales Vorzeichen gefolgt von der Ziffer `0`.
```
Integer : Sign? Zero
```

##### Realzahlen
Eine Realzahl ist wie folgt definiert:

- Ein optionales Vorzeichen, gefolgt von 1 oder mehrere Zifffern ohne führende 0en, gefolgt vone inem ein Punkt,
gefolgt von optional 1 oder mehrere Ziffern sowie einem optionaler Exponent.
```
Real : Sign? (Digit - Zero) Digit* Period Digit* Exponent?
```
- Ein optionales Vorzeichen, gefolgt von einem Punkt, gefolgt von 1 oder mehreren Ziffern,
gefolgt von einem optionalen Exponenten.
```
Real : Sign? Period Digit+ Exponent?
```

- Ein optionales Vorzeichen, gefolgt von 1 oder mehreren Ziffern ohne führende 0en, gefolgt von einem Exponenten.
```
Real : Sign? (Digit - Zero) Digit* Exponent
```

#### Kommentare
Es existieren einzeilige Kommentare und mehrzeilige Kommentare.

```
Comment : SingleLineComment
        / MultiLineComment
```

Ein einzeilger Kommentar beginnt mit zwei aufeinanderfolgenden `/` und erstreckt sich bis zum Ende der Zeile.

```
SingleLineCommant : Solidus Solidus InputCharacter*
Solidus : '/' (engl. solidus, dt. Solidus,  Unicode: U+002F)
```

Ein mehrzeiliger Kommentar beginnt mit einem `/` gefolgt von einem `*` und endet mit einem `*` gefolgt von einem `/`.


Kommentare schachteln nicht:
- `/*` und `*/` haben keine spezielle Bedeutung in einzeiligen Kommentaren.
- `//` hat keine spezielle Bedeutung in mehrzeiligen Kommentaren.


```
MultiLineComment : Solidus Asterisk Solidus Asterisk CommentTail

CommentTail : NotAsterisk CommentTail
            / Asterisk CommentTailAsterisk
CommentTailAsterisk : Solidus
                    / Asterisk CommentTailAsterisk
                    / NotAsterisNotSolidus CommentTail
NotAsterisk : (InputCharacter - Asterisk) 
            / LineTerminator
NotStarNotSlash : (InputCharacter - Asterisk - Solidus)
                / LineTerminator 
Asterisk : '*' (engl. asterisk, dt. Asterisk, Unicode: U+002A)
```

## Syntaktische Spezifikation

```
Unit : StructureExpression
     / ListExpression
```

```
StructureExpression : StructureOpeningDelimiter StructureBody StructureClosingDelimiter
structureBody : (StructureElement (Comma StructureElement)* Comma?)?
StructureElement : Name Colon Expression
```

```
ListExpression : ListOpeningDelimitier ListBody ListClosingDelimiter
ListBody : (ListElement (Comma ListElement)* Comma ?)?
ListElement : Expression
```

```
Expression: LiteralExpression / ListExpression / StructureExpression
LiteralExpression : Number / String / True / False / Null
```
