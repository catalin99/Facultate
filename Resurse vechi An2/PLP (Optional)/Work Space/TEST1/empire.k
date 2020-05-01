module EMPIRE-SYNTAX

     syntax Valoare ::= Id
                     |  Int
                     |  Valoare "+" Valoare        [left, strict]

     syntax Cartier ::= "{" "}"
                     |  "{" Bloc "}"

     syntax Bloc ::=  "var" Ids                    [strict]
                    | Id ":=" Valoare              [strict(2)]
                    | Cartier
                    > Bloc ";" Bloc                [left, strict]

     syntax Ids ::= List {Id,","}

endmodule

module EMPIRE
     imports EMPIRE-SYNTAX
     syntax KResult ::= Int

     configuration  <T>
                         <k>$PGM:Bloc</k>
                         <adresa>.Map</adresa>
                         <magazie>.Map</magazie>
                    </T>

     rule I1:Int + I2:Int => I1 +Int I2

     rule var .Ids => .

     rule S1:Bloc ; S2:Bloc => S1 ~> S2

     // asignare
     rule <k> var (X,Xs=>Xs) ...</k>
          <adresa> Rho:Map => Rho[X <- !L:Int] </adresa>
          <magazie> Sigma:Map (. => (!L |-> 0)) </magazie>

     rule <k> { S:Bloc } => S ~> Rho ... </k> <adresa> Rho </adresa>
     rule <k> Rho => . ...</k> <adresa> _ => Rho </adresa>

     rule <k>(X:Id := V:Int => .)...</k>
          <adresa>...X |-> L:Int...</adresa>
          <magazie>...L|->(_=>V)...</magazie>

     rule <k>(X:Id=>V:Int)...</k>
          <adresa>...X |-> L:Int...</adresa>
          <magazie>...L |-> V...</magazie>

     rule {} => .
endmodule
