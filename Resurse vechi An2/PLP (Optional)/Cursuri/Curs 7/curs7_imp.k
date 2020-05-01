module IMP-SYNTAX
     syntax AExp ::= Id
               | Int
               | String
               | "++" Id
               | Id "(" Params ")"                [strict(2)]
               | "read" "(" ")"
               | AExp "/" AExp                    [left]
               > AExp "+" AExp                    [left, strict]
               | "(" AExp ")"                     [bracket]

     syntax BExp ::= Bool
               | AExp ">" AExp                     [strict]
               | "(" BExp ")"                     [bracket]

     syntax Block ::= "{" "}"
                 | "{" Stmt "}"

     syntax Stmt ::= Block
               | Id "=" AExp ";"                                 [strict(2)]
               | "int" Id ";"
               | "print" "(" AExp ")" ";"                         [strict]
               | "return" ";"
               | "return" AExp ";"                     [strict]
               | AExp ";"                               [strict]
               | "if" BExp Block "else" Block                     [strict(1)]
               | "while" BExp Block
               > Stmt Stmt                                        [right]

     syntax Pgm ::= List{Decl, ";"}

     syntax Decl ::= FunDecl
               | VarDecl

     syntax VarDecl ::= "int" Id

     syntax FunDecl ::= "function" Id "(" VarDecls ")" Block

     syntax VarDecls ::= List{VarDecl, ","}

     syntax Params ::= List{AExp, ","} [strict]
endmodule

module IMP
  imports IMP-SYNTAX

  syntax Val ::= Int | Bool | String
  syntax Vals ::= List{Val, ","}
  syntax KResult ::= Val | Vals

  syntax Params ::= Vals
  syntax AExp ::= Val

  syntax KItem ::= "execute"
  syntax Id ::= "main"                 [token]

  configuration <T>
               <k> $PGM:Pgm ~> execute </k>
               <env> .Map </env> // varname |-> address
               <store> .Map </store>  // address |-> value
               <in stream="stdin"> .List </in>
               <out stream="stdout"> .List </out>
               <stack> .List </stack>
               <fstack> .List </fstack>
               </T>

  // AExp
  rule I1:Int + I2:Int => I1 +Int I2

  // BExp
  rule I1:Int > I2:Int => I1 >Int I2

  // variable declaration
  rule <k> (int X:Id ; => .) ...</k>
       <env> M:Map => M[X <- !L:Int] </env>
       <store> Sigma:Map (.Map => (!L |-> 0)) </store>

  // global variable declaration
      rule <k> (int X:Id => .) ...</k>
           <env> M:Map => M[X <- !L:Int] </env>
           <store> Sigma:Map (.Map => (!L |-> 0)) </store>

  // function declaration
      syntax Lambda ::= "lambda" "(" VarDecls "," Block ")"
      rule <k> (function X:Id ( V:VarDecls ) B => .) ...</k>
      <env> Rho:Map => Rho[X <- !L:Int] </env>
      <store> Sigma:Map => Sigma[!L <- lambda(V, B) ] </store>

  rule .Pgm ~> execute => main(.Params)

  // variable lookup
  rule <k> (X:Id => V) ...</k>
       <env>... X |-> L:Int ...</env>
       <store>... L |-> V:Int ...</store>


  // Stmt sequence
  rule S1:Stmt S2:Stmt => S1 ~> S2
  rule D:Decl ; Ds:Pgm => D ~> Ds

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

  // function call
  syntax KItem ::= "saveEnv"
  syntax KItem ::= "mkDecl" "(" VarDecls "," Vals ")"
  rule <k> X:Id ( P:Vals) => saveEnv ~> mkDecl(Ds, P) ~> S ...</k>
          <env>... X |-> L:Int ...</env>
          <store>... L |-> lambda(Ds:VarDecls, { S }) ... </store>

  //save the environment
  rule <k> (saveEnv => .) ...</k>
          <env> Rho </env>
          <fstack> (.List => ListItem(Rho)) ...</fstack>

  // make declarations
  rule mkDecl(.VarDecls, .Vals) => .
  rule <k> mkDecl ( (int X:Id, Xs:VarDecls), (V:Int, Vs:Vals) ) => mkDecl(Xs, Vs) ...</k>
     <env> Rho => Rho[X <- !L:Int] </env>
     <store> Sigma => Sigma[!L <- V] </store>

  // return
  rule <k> return V:Val ; => V...</k>
     <env> _ => Rho </env>
     <fstack> (ListItem(Rho) => .List) ...</fstack>

     rule <k> (return ; => .) ...</k>
        <env> _ => Rho </env>
        <fstack> (ListItem(Rho) => .List) ...</fstack>
endmodule
