open Core
open Parsing

let filename = 
  let args = Sys.get_argv () in
    args.(1)
  
let () = 
  Stdio.In_channel.with_file filename ~f:(fun file_ic ->
    let lexbuf = Lexing.from_channel file_ic in
        Ast.Pprint.pprint (Parser.prog Lexer.read lexbuf))

