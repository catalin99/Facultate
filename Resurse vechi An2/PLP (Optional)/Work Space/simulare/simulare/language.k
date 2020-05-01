module LANGUAGE-SYNTAX

 syntax AExp ::= Id | Int
               | AExp "+" AExp [left,strict]

 syntax Block ::= "{" "}"
                | "{" Stmt "}"

 syntax Stmt ::= "var" Ids
               | Block
               | Id ":=" AExp [strict(2)]
               > Stmt ";" Stmt [left]

 syntax Ids ::= List {Id,","}

endmodule

module LANGUAGE
 imports LANGUAGE-SYNTAX

 configuration <T>
    <k>$PGM:Stmt</k>
    <env>.Map</env>
    <store>.Map</store>
 </T>

 syntax KResult ::= Int

 rule S1:Stmt ; S2:Stmt => S1 ~> S2

 rule <k>var (X,Xs=>Xs)...</k>
      <env> M:Map => M[X <- !L:Int] </env>
      <store> Sigma:Map (.Map => (!L |-> 0)) </store>

 rule var .Ids => .

 rule I1:Int + I2:Int => I1 +Int I2

 rule {} => .

 rule <k>{S:Stmt}=>S ~> Rho...</k> <env>Rho</env>
 rule <k>Rho=>. ...</k> <env>_ => Rho</env>

 rule <k>(X:Id := V:Int => .)...</k>
      <env>...X |-> L:Int...</env>
      <store>...L|->(_=>V)...</store>

 rule <k>(X:Id=>V:Int)...</k>
      <env>...X |-> L:Int...</env>
      <store>...L |-> V...</store>

endmodule
