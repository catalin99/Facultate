module IMP-SYNTAX
 syntax AExp ::= Id 
               | Int
               | String
               | "++" Id
               | AExp "/" AExp          [left]
               | AExp "*" AExp          [left]
                > AExp "+" AExp         [left, strict]
               | AExp "-" AExp          [left, strict]
               | "(" AExp ")"           [bracket]

 syntax BExp ::= Bool
                | AExp "<=" AExp    [strict]
                | AExp "<" AExp     [strict]
                | AExp ">=" AExp    [strict]
                | AExp ">" AExp     [strict]
                | "not" BExp        [strict]
                | "!" BExp          [strict]
                | BExp "&&" BExp    [strict(1)]
                | "(" BExp ")"      [bracket]

 syntax Block ::= "{" "}"
                | "{" Stmt "}"
                | Id "=" AExp ";"             [strict(2)]

 syntax Stmt ::= Block
               | Id "=" AExp ";"    [strict(2)]
               | "int" Id ";"
               | "return" ";"
               | "return" AExp ";"             [strict]
               | AExp ";"                      [strict]
               | "if" BExp Block "else" Block  [strict(1)]
               | "while" BExp Block 
               > Stmt Stmt  [left]               

 syntax Pgm ::= "int" Ids ";" Stmt
 syntax Ids ::= List {Id,","}
endmodule

module IMP 
 imports IMP-SYNTAX

 configuration <T>
    <k> $PGM:Pgm </k>
    <env> .Map </env>
    <store> .Map </store>
 </T>

// Rezultatul returnat de program
 syntax KResult ::= Int | Bool

 rule <k> X:Id => I ...</k> <env>... X |-> I ...</env>
 rule <k> int (X,Xs => Xs);_ </k> <env> Rho:Map (.Map => X|->0) </env>

 rule int .Ids; S => S

// Statementuri
 rule S1:Stmt S2:Stmt => S1 ~> S2

 // Operatii 
 rule I1:Int + I2:Int => I1 +Int I2
 rule I1:Int - I2:Int => I1 -Int I2
 rule I1:Int * I2:Int => I1 *Int I2
 rule I1:Int / I2:Int => I1 /Int I2

 // Operatii boolene
 rule I1 <= I2 => I1 <=Int I2
 rule ! T => notBool T
 rule true && B => B
 rule false && _ => false

 // Blocuri
 rule {} => .
 rule {S} => S

 // Asigniere
 rule <k> X = I:Int; => . ...</k> <env>... X |-> (_ => I) ...</env>

 // If
 rule if (true)  S else _ => S
 rule if (false) _ else S => S

 // while
 rule while (B) S => if (B) {S while (B) S} else {}
endmodule
