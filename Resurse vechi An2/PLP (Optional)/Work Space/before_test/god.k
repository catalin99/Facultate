module GOD-SYNTAX
syntax Expressions ::= Int | Id
                    | "(" Expressions ")"                   [bracket]
                    > left:
                    Expressions "*" Expressions             [left, strict]
                    | Expressions "/" Expressions           [left, strict]
                    | Expressions "%" Expressions           [left, strict]
                    > left:
                    Expressions "+" Expressions             [left, strict]
                    | Expressions "-" Expressions           [left, strict]

syntax BoolE ::= Bool
               | Expressions "<=" Expressions               [strict]
               | "(" Expressions ")"                        [bracket]

syntax Assignation ::= Id "=" Expressions                   [strict(2)]

syntax Block ::= "{" "}"
               | "{" Stmt "}"                               [strict]

syntax Decl ::= "var" Id                                    [strict]

syntax Stmt ::= Decl ";"
               | Assignation ";"
               | BoolE "?" Block ":" Block                  [strict(1)]
               | "repeat" Stmt "until" BoolE "end"          [strict(2)]

endmodule

module GOD
     imports GOD-SYNTAX
     syntax KResult ::= Int
     configuration <T>
                    <k> $PGM:Stmt </k>
                    <env> .Map </env>
                </T>

     rule I1:Int + I2:Int => I1 +Int I2
     rule I1:Int * I2:Int => I1 *Int I2
     rule I1:Int <= I2:Int => I1 <=Int I2

     // if
     rule B ? true B1 else _  => B1
     rule B ? false _ else B2 => B2

     // variable declaration
     rule <k> (var X:Id => .) ...</k>
          <env> M:Map (.Map => (X |-> 0)) </env>

     // variable lookup
     rule <k> (X:Id => V) ...</k>
          <env>... X |-> V:Int ...</env>

     // assignment
     rule <k> (X:Id = V:Int ; => .) ...</k>
     <env>... X |-> (_ => V) </env>

     // blocks
     rule { S:Stmt } => S
     rule {} => .

     // until loop
     rule repeat S until B _ => B true {} else { S repeat S until B }

endmodule
