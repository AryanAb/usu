{
open Lexing
open Parser

exception SyntaxError of string

let next_line lexbuf =
  let pos = lexbuf.lex_curr_p in
  lexbuf.lex_curr_p <-
    { pos with pos_bol = lexbuf.lex_curr_pos;
               pos_lnum = pos.pos_lnum + 1
    }

}

let digit = ['0'-'9']
let int = '-'? digit*
let frac = '.' digit*
let exp = ['e' 'E'] ['-' '+']? digit+
let number = int digit* frac? exp?
let white = [' ' '\t']+
let newline = '\r' | '\n' | "\r\n"
let id = ['a'-'z' 'A'-'Z' '_'] ['a'-'z' 'A'-'Z' '0'-'9' '_']*

rule read =
  parse
  | white     { read lexbuf }
  | newline   { next_line lexbuf; read lexbuf }
  | number    { NUMBER (float_of_string (Lexing.lexeme lexbuf)) }
  | "#"       { read_comment lexbuf }
  | "length"  { LENGTH }
  | "m"       { METRE }
  | "time"    { TIME }
  | "s"       { SECOND }
  | "mass"    { MASS }
  | "kg"      { KILOGRAM }
  | "current" { CURRENT }
  | "A"       { AMPERE }
  | "temp"    { TEMPERATURE }
  | "K"       { KELVIN }
  | "amount"  { AMOUNT }
  | "mol"     { MOLE }
  | "lum"     { LUM }
  | "cd"      { CANDELA }
  | id        { ID (Lexing.lexeme lexbuf) }
  | "="       { ASSIGN }
  | ":="      { DEFINE_DIM }
  | "=:"      { DEFINE_UNIT }
  | "+"       { PLUS }
  | "-"       { MINUS }
  | "*"       { MULT }
  | "/"       { DIV }
  | "<"       { LANGLE }
  | ">"       { RANGLE }
  | _         { raise (SyntaxError ("Unexpected char: " ^ Lexing.lexeme lexbuf)) }
  | eof       { EOF }

and read_comment = parse
  | newline { next_line lexbuf; read lexbuf }
  | eof { EOF }
  | _ { read_comment lexbuf }