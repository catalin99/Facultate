module IMP-SYNTAX
  syntax Exp ::=  Int | Id
                | "(" Exp ")"                                   [bracket]
                > left:
                  Exp "*" Exp                                   [left]
                | Exp "/" Exp                                   [left]
                > left:
                  Exp "+" Exp                                   [left]
                | Exp "-" Exp                                   [left]

  syntax BExp ::= Bool
                | Exp "<=" Exp
                | Exp ">=" Exp
                | Exp ">" Exp
                | Exp "<" Exp
                | Exp "==" Exp
                | "(" BExp ")"                                  [bracket]

  syntax StmtExp ::= BExp "and" BExp
                | BExp "or" BExp
                | Id "=" Exp
                | "if" BExp Block "else" Block            [avoid]
                | "if" BExp Block
                | "while" BExp "do" Block
                | StmtExp ";"

  syntax Block ::= "{" "}"
                | "{" StmtExp "}"
                | StmtExp
endmodule

module IMP
  imports IMP-SYNTAX
  configuration <k> $PGM:K </k>
endmodule
