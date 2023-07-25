type id = string

type num =
  | Number of float
  | Var of string

type bin_op =
  | Plus
  | Minus
  | Mult
  | Div

type dim_expr =
  | Length
  | Time
  | Mass
  | Current
  | Temp
  | Amount
  | Lum
  | Custom_dim of string
  | Dim_expr of dim_expr * bin_op * dim_expr

type unit_expr =
  | Metre
  | Second
  | Kilogram
  | Ampere
  | Kelvin
  | Mole
  | Candela
  | Custom_unit of string
  | Unit_expr of unit_expr * bin_op * unit_expr
  | Unit_comb of float * bin_op * unit_expr

type num_expr = 
  | Value of float * unit_expr
  | Variable of string
  | Num_expr of num_expr * bin_op * num_expr

type statement = 
  | Var_dec of dim_expr * string * num_expr
  | Dim_dec of string * dim_expr
  | Unit_dec of string * unit_expr

type statements = statement list