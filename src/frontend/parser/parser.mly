%{
  open Ast.Ast_types
%}

%token <float> NUMBER
%token <string> ID
%token LENGTH
%token METRE
%token TIME
%token SECOND
%token MASS
%token KILOGRAM
%token CURRENT
%token AMPERE
%token TEMPERATURE
%token KELVIN
%token AMOUNT
%token MOLE
%token LUM
%token CANDELA
%token ASSIGN
%token DEFINE_DIM
%token DEFINE_UNIT
%token PLUS
%token MINUS
%token MULT
%token DIV
%token LANGLE
%token RANGLE
%token EOF
%start <Ast.Ast_types.statements option> prog
%%

prog:
  | EOF       { None }
  | v = value { Some v } ;

value:
  | ss = statements; EOF { ss } ;

statements:
  | s = statement                    { [s] }
  | s = statement; ss = statements   { s :: ss } ;

statement:
  | d = var_decleration  { d }
  | d = dim_decleration  { d }
  | d = unit_decleration { d }


var_decleration:
  | dim = dim_expression; id = ID; ASSIGN; num_expr = num_expression { Var_dec (dim, id, num_expr) }


dim_decleration:
  | id = ID; DEFINE_DIM; dim_expr = dim_expression { Dim_dec (id, dim_expr) }

num_expression:
  | a = num_expression; PLUS;  b = num_term  { Num_expr (a, Plus, b) }
  | a = num_expression; MINUS; b = num_term  { Num_expr (a, Minus, b) }
  | a = num_term                             { a }

num_term:
  | a = num_term; MULT; b = num_factor { Num_expr (a, Mult, b) }
  | a = num_term; DIV;  b = num_factor { Num_expr (a, Div, b) }
  | a = num_factor                     { a }

num_factor:
  | n = NUMBER; u = unit_expression { Value (n, u) }
  | x = ID     { Variable x }

dim_expression:
  | a = dim_expression; PLUS;  b = dim_term { Dim_expr (a, Plus, b) }
  | a = dim_expression; MINUS; b = dim_term { Dim_expr (a, Minus, b) }
  | a = dim_term                            { a }

dim_term:
  | a = dim_term; MULT; b = dim_factor { Dim_expr (a, Mult, b) }
  | a = dim_term; DIV; b = dim_factor  { Dim_expr (a, Div, b) }
  | a = dim_factor { a }

dim_factor:
  | LENGTH      { Length }
  | TIME        { Time }
  | MASS        { Mass }
  | CURRENT     { Current }
  | TEMPERATURE { Temp }
  | AMOUNT      { Amount }
  | LUM         { Lum }
  | id = ID     { Custom_dim id }


unit_decleration:
  | id = ID; DEFINE_UNIT; unit = unit_expression { Unit_dec (id, unit) }

unit_expression:
  | LANGLE; u = unit_term; RANGLE { u }

unit_term:
  | a = unit_term; MULT; b = unit_factor { Unit_expr (a, Mult, b) }
  | a = unit_term; DIV;  b = unit_factor { Unit_expr (a, Div, b) }
  | a = unit_factor                      { a }

unit_factor:
  | u = unit {u}
  | n = NUMBER; MULT; u = unit { Unit_comb (n, Mult, u) }
  | n = NUMBER; DIV;  u = unit { Unit_comb (n, Div, u) }

unit:
  | METRE    { Metre }
  | SECOND   { Second }
  | KILOGRAM { Kilogram }
  | AMPERE   { Ampere }
  | KELVIN   { Kelvin }
  | MOLE     { Mole }
  | CANDELA  { Candela }
  | c = ID   { Custom_unit c }