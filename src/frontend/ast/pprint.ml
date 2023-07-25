open Ast_types

let print_ast ast = 
  match ast with
  | Var_dec (_, _, _) -> print_endline "Var_dec"
  | Dim_dec (_, _) -> print_endline "Dim_dec"
  | Unit_dec (_, _) -> print_endline "Unit_dec" 

let rec iterate_statements = function
  | [] -> ()
  | x :: xs -> print_ast x; iterate_statements xs

let pprint = function
  | Some x -> iterate_statements x
  | None ->   print_endline "Empty File"