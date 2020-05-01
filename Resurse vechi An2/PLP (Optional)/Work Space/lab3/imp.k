module IMP-SYNTAX

  syntax AExp ::= Int | Id
                | AExp "/" AExp [left, strict]
                > AExp "+" AExp [left, strict]
                // strict => evalueaza intai argumentele lui + si dupa aduna
                | "(" AExp ")"  [bracket]

  syntax BExp ::= Bool
                | "!" BExp    [strict]
                | BExp "&&" BExp [strict(1)]
                | AExp "<=" AExp [strict]
                | "(" BExp ")"   [bracket]


  syntax Block ::= "{" "}"
                 | "{" Stmt "}"

  syntax Stmt ::= Block
                | Id "=" AExp ";" [strict(2)]
                | "if" BExp Block "else" Block [strict(1)]
                | "while" BExp Block [strict(1)]
                > Stmt Stmt [left]

  syntax Pgm ::= "int" Ids ";" Stmt
  syntax Ids ::= List{Id, ","}

endmodule

module IMP
  imports IMP-SYNTAX

  configuration <T>
                    <k> $PGM:Pgm </k>
                    <state> .Map </state>
                </T>

  syntax KResult ::= Int | Bool

  // Pgm
  rule <k> int (X, Xs => Xs) ; S </k>
       <state> Rho:Map (.Map => X |-> 0) </state>
       when notBool(X in keys(Rho))
  rule int .Ids ; S => S

  rule S1:Int + S2:Int => S1 +Int S2
  rule S1:Int <= S2:Int => S1 <=Int S2
  rule S1:Int / S2:Int => S1 /Int S2 when S2 =/=Int 0

  // Seq
  rule S1:Stmt S2:Stmt => S1 ~> S2

  //  <k> n = 10 ;
  //  </k> <state> n |-> 0 sum |-> 0 </state> </T>
  // assignment
  rule
     <k> X:Id  = V:Int ; => . ...</k>
     <state>... X |-> (_ => V) ...</state>

  // sa stie sa ia valoarea unui ID din memorie
  // variable lookup
  rule
     <k> X:Id => V ...</k>
     <state>... X |-> V:Int ...</state>

   // if
   rule if true B1:Block else _  => B1
   rule if false _ else B2:Block => B2

   // if blocks
   rule { S:Stmt } => S
   rule {} => .

   // ! or (rule ! B:Bool => notBool B)
   rule ! true => false
   rule ! false => true

   // &&
   rule true && B => true
   rule false && B => false

   //while (loop unrolling)
   rule while B { S } => if B { S while B { S } } else {}
endmodule
