module IMP_C-SYNTAX
     syntax AExp ::= Id | Int
                   > AExp "+" AExp                                    [left, strict]

     syntax Stmt ::= "{" Stmts "}"
                   | Id ":=" AExp                                [strict(2)]
                   | "var" Ids

     syntax Stmts ::= List{Stmt, ";"}
     syntax Ids   ::= List{Id, ","}

endmodule

module IMP_C
     imports IMP_C-SYNTAX
     syntax KResult ::= Int

     configuration  <T>
                         <k> $PGM:Stmt </k>
                         <env> .Map </env>
                         <store> .Map </store>
                    </T>

     // AExp
     rule I1:Int + I2:Int => I1 +Int I2

     // Variable declaration
     rule <k> (var X:Id => .) ...</k>
           <env> M:Map => M[X <- !L:Int] </env>
           <store> Sigma:Map (.Map => (!L |-> 0)) </store>

     // Variable lookup
     rule <k> (X:Id => V:Int) ...</k>
          <env>... X |-> L:Int ...</env>
          <store>... L |-> V:Int ...</store>

     // Variable assignment
     rule <k> (X:Id := V:Int => .) ...</k>
          <env>... X |-> L:Int </env>
          <store>... L |-> (_ => V:Int) </store>

endmodule
