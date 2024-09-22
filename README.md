# About the project
Bunny is a simple multiparadigm programming language focused on avoiding verbose and hard-to-read syntax.
## Basic principles
- Tokens do not include white spaces.
- All tokens are prefixed by at least 1st order keyword.
## 1st order keywords
- \# ... numeric value
- " ... string
- $ ... variable
- % ... operator
- @ ... function
- | ... condition
## 2nd order keywords
- ~ ... standard library
## Structure of a program
Function token outside of function body is interpreted as definition.
All inputs are on the same line as the function token.
Function body starts on the next line and ends on the first empty line.
All function tokens inside of function body are interpreted as function calls.
Function calls are formatted as first lines of function definitions.
## Example code
```
@MAIN
@FUNCION #14

@FUNCTION $INPUT
$VAR %~= #12
$RESULT %~= ( $INPUT %~+ $VAR ) %~* #~PI
@~PRINT $RESULT
```
