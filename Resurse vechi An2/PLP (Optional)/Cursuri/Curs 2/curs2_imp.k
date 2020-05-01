module IMP-SYNTAX
  syntax Exp ::=  Int | Id
                | "(" Exp ")"                                   [bracket]
                > left:
                  Exp "*" Exp                                   [left, strict]
                | Exp "/" Exp                                   [left, strict]
                > left:
                  Exp "+" Exp                                   [left, strict]
                | Exp "-" Exp                                   [left, strict]

  syntax Bool ::= "true" | "false"

  syntax BExp ::= Bool
                | Exp "<=" Exp
                | Exp ">" Exp
                | "(" BExp ")"                                  [bracket]

  syntax Block ::= "{"  "}"
                | "{" Stmt "}"

  syntax Stmt ::= Id "=" Exp ";"
                | "if" BExp Block "else" Block                  [avoid]
                | "if" BExp "then" Block
                | "while" BExp Block
                | Stmt Stmt                                     [right]
endmodule

module IMP
  imports IMP-SYNTAX
  configuration <k> $PGM:Stmt </k>
endmodule
