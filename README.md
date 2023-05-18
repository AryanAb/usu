# usu

[![AryanAb](https://circleci.com/gh/AryanAb/usu.svg?style=shield)](https://app.circleci.com/pipelines/github/AryanAb/usu?filter=all)

usu is a very simple programming language that is currently work in progress. Usu is latin for practice. As the name implies, the language is meant to be just for practicing compiler concepts and nothing too serious. Contributions and criticisms are welcomed.

## Sample Program

You can see a very basic usu program below.

```
# All seven base SI quantities and their base units are built in

length a = 10 m     # define length variable
time t = 5 s        # define time variable
mass m = 2 kg       # define mass variable
current c = 4 A     # define electric current variable 
temp k = 100 K      # define temperature variable
amount n = 2 mol    # define amount of substance variable
lum l = 3.3 cd      # define luminous intensity variable

# define dimensionless variable when needed
less c = 1

# define new dimension
vel := length / time;

# calculate an expression and assign it to new variable
vel v = a / t

# define new unit
km := 1000 * m;

# catch mistakes early
length warn = a + 1 km    # Warning: adding two quantities of different units (m and km)
length err = a + k        # Error: cannot add variables of dimension length to temperature
```


## usu Specifications

### Tokens

```
LESS, LENGTH, TIME, MASS, CURRENT, TEMP, AMOUNT, LUM, ID, ASSIGN, NUMBER, M, S, KG, A, K, MOL, CD, PLUS, MINUS, MULT, DIV, DEFINE, SEMICOLUMN, RETURN, LCBRACKET, RCBRACKET, LPAREN, RPAREN
```

### Grammar

```
<program>      -> <declerations>
<declerations> -> <declerations> <decleration> | <decleration>
<decleration>  -> <var_decleration> | <dim_decleration> | <unit_decleration>

<var_decleration>  -> <dim_expression> ID ASSIGN <num_expression> <unit_expression>
<dim_decleration>  -> ID DEFINE <dim_expression>
<unit_decleration> -> ID DEFINE <unit_expression>

<dim_expression> -> <dim_term> (+ | - <dim_term>)*
<dim_term>       -> <dim_factor> (* | / <dim_factor>)*
<dim_factor>     -> ID | <dim>
<dim>            -> LESS | LENGTH | TIME | MASS | CURRENT | TEMP | AMOUNT | LUM

<unit_expression> -> <unit_term> (+ | - <unit_term>)*
<unit_term>       -> <unit_factor> (* | / <unit_factor>)*
<unit_factor>     -> ID | <unit>
<unit>            -> M | S | KG | A | K | MOL | CD

<num_expression> -> <num_term> (+ | - <num_term>)*
<num_term>       -> <num_factor> (* | / <num_factor>)*
<num_factor>     -> ID | NUMBER
```

## How to Build

Simply clone the repository, and use the `make` command to build the compiler. The executable file for the compiler will be placed in the bin directory. Note that the compiler is not yet fully finished.
