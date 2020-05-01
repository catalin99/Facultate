module IMP-SYNTAX
    syntax AExp ::= Id
                | Int
                | AExp "/" AExp                         [left]
                > AExp "+" AExp                         [left, strict]
                | "(" AExp ")"                          [bracket]

    syntax BExp ::= Bool
                | AExp ">" AExp                         [strict]
                | "(" BExp ")"                          [bracket]

    syntax Block ::= "{" "}"
                | "{" Stmt "}"

    syntax Stmt ::= Id "=" AExp ";"                      [strict(2)]
                | "int" Id ";"
                | "if" BExp Block "else" Block          [strict(1)]
                | "while" BExp Block
                > Stmt Stmt                             [right]
endmodule

module IMP

    imports IMP-SYNTAX
    syntax KResult ::= Int | Bool
    
    /* hack
    syntax Id ::= "x"
    configuration   <T>
                        <k> $PGM:Stmt </k>
                        <env> .Map </env>
                    </T> 
    */

      imports IMP-SYNTAX
    syntax KResult ::= Int | Bool
  
rule I1:Int + I2:Int => I1 +Int I2

    // BExp
    rule I1:Int > I2:Int => I1 >Int I2

  =/=Int



  rule <k> (X:Id => V) ... </k>
       <env>... X |-> L:Int ...</env>
       <store>... L |-> V:Int ...</store>

  rule <k> (int X:Id ; => .) ...</k>
       <env> M:Map => M[X <- !L:Int] </env>
       <store> Sigma:Map (.Map => (!L |-> 0)) </store>


  // BExp
  rule I1:Int > I2:Int => I1 >Int I2

  // if
  rule if true  B1 else _  => B1
  rule if false _  else B2 => B2

    // variable declaration
    rule <k> (int X:Id ; => .) ...</k>
            <env> M:Map (.Map => (X |-> 0)) </env>
            when notBool(X in keys(M))

    // variable lookup
    rule <k> (X:Id => V) ...</k>
            <env>... X |-> V:Int ...</env>

    // Stmt sequence
    rule S1:Stmt S2:Stmt => S1 ~> S2

    // assignment
    rule <k> (X:Id = V:Int ; => .) ...</k>
    <env>... X |-> (_ => V) </env>

    // if
    rule if true  B1 else _  => B1
    rule if false _  else B2 => B2

    // blocks
    rule { S:Stmt } => S
    rule {} => .

    // while loop
    rule while C { S } => if C { S while C { S } } else {}

endmodule
