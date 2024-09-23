# About the project
Bunny is a simple multiparadigm programming language focused on avoiding verbose and hard-to-read syntax.
## Tokens
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
- ~ ... standard library (after #, ", %, @ or |)
- \# ... numeric (after $, % or @)
- " ... string (after $, % or @)
## 3rd order keywords
- ~ ... specialized standard library (after %#, @#, %" or @")
## Structure of a program and functions
- Function token outside of function body is interpreted as definition.
- All inputs are on the same line as the function token.
- Function body starts on the next line and ends on the first empty line.
- All function tokens inside of function body are interpreted as function calls.
- Function call is formatted as first line of function definition.
## Structure of a line and parenthesis
- Each line is interpreted as one statement.
- Each line is made up of tokens separated by spaces.
- Used are only opening '(' parenthesis and are in effect until the end of the line.
## Implicit operators
Following operators can be omitted:
- assignment operator after variable in the beginning of a line
- multiplication operator between variables and numeric values that are not in the beginning of a line
## Example code
Explicit
```
@MAIN
@#FUNCTION #14

@#FUNCTION $#INPUT
$#VAR %~= #12
$#RESULT %~= #~PI %#~* ( $#INPUT %#~+ $#VAR
@~PRINT $#RESULT
```
Implicit
```
@MAIN
@FUNCTION #14

@FUNCTION $INPUT
$VAR #12
$RESULT #~PI ( $INPUT %#~+ $VAR
@~PRINT $RESULT
```
