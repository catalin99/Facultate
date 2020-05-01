module IMP-SYNTAX
  syntax AExp ::= Id
| Int
| String
| "++" Id
| "read" "(" ")"
| AExp "/" AExp    [left]
> AExp "+" AExp    [left, strict]
| "(" AExp ")"     [bracket]

  syntax BExp ::= Bool
                | AExp ">" AExp    [strict]
            | "(" BExp ")"     [bracket]

  syntax Block ::= "{" "}"
                 | "{" Stmt "}"

  syntax Stmt ::= Block
| Id "=" AExp ";"               [strict(2)]
| "int" Id ";"
| "print" "(" AExp ")" ";"      [strict]
| AExp ";"            [strict]
| "if" BExp Block "else" Block  [strict(1)]
| "while" BExp Block
> Stmt Stmt                     [right]
endmodule

module IMP
  imports IMP-SYNTAX
  syntax KResult ::= Int | Bool | String

  configuration <T>
                  <k> $PGM:Stmt </k>
                <env> .Map </env> // varname |-> address
          <store> .Map </store>  // address |-> value
          <in stream="stdin"> .List </in>
          <out stream="stdout"> .List </out>
          <stack> .List </stack>
            </T>

  // AExp
  rule I1:Int + I2:Int => I1 +Int I2

  // BExp
  rule I1:Int > I2:Int => I1 >Int I2

  // variable declaration
  rule <k> (int X:Id ; => .) ...</k>
       <env> M:Map => M[X <- !L:Int] </env>
       <store> Sigma:Map (.Map => (!L |-> 0)) </store>


  // variable lookup
  rule <k> (X:Id => V) ...</k>
       <env>... X |-> L:Int ...</env>
       <store>... L |-> V:Int ...</store>


  // Stmt sequence
  rule S1:Stmt S2:Stmt => S1 ~> S2

  // assignment
  rule <k> (X:Id = V:Int ; => .) ...</k>
       <env>... X |-> L:Int </env>
       <store>... L |-> (_ => V) </store>

  // if
  rule if true  B1 else _  => B1
  rule if false _  else B2 => B2

  // blocks
/*  rule <k> { S:Stmt } => S ~> Rho ...</k>
       <env> Rho </env>
  rule <k> (Rho => .) ...</k>
       <env> _ => Rho </env>
*/
  syntax KItem ::= "restoreEnv"
  rule <k> { S:Stmt } => S ~> restoreEnv ...</k>
       <env> Rho </env>
       <stack> (.List => ListItem(Rho)) ...</stack>

  rule <k> restoreEnv => . ...</k>
       <env> _ => Rho </env>
       <stack> (ListItem(Rho) => .List) ...</stack>

  rule {} => .

  // while loop
  rule while C { S }=> if C { S while C { S } } else {}

  // (pre)increment
  rule <k> (++ X:Id) => I +Int 1 ...</k>
       <env>... X |-> L </env>
       <store>... L |-> (I:Int => I +Int 1) ...</store>
  rule I:Int ; => .

  // read
  rule <k> read() => I ...</k>
       <in> (ListItem(I:Int) => .List) ...</in>

  // print
  syntax Printable ::= Int | String
  syntax AExp ::= Printable // TODO: by K!
  rule <k> (print(I:Printable) ; => .) ...</k>
       <out>... (.List => ListItem(I)) </out>

endmodule
