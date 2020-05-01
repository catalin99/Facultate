module IMP-SYNTAX
  syntax IMPExp ::= Id | Int | String

  syntax IMPS ::= IMPB
               |  "var" Ids
               |  "print" "(" IMPExps ")"                           [strict(1)]
               >  Id ":=" IMPExp                                    [strict(2)]
               |  IMPS ";" IMPS                                     [left]

syntax IMPB ::= "{" "}"
             |  "{" IMPS "}"

  syntax Ids ::= List{Id,","}                                      [strict]

  syntax IMPExps ::= List{IMPExp, ","}                             [strict]
endmodule

module IMP
  imports IMP-SYNTAX

  configuration <T>
        		     <k> $PGM:IMPS </k>
     		     <env> .Map </env>
     		     <store> .Map </store>
     		     <out stream="stdout"> .List </out>
     		 </T>

  syntax IMPExps ::= Vals
  syntax IMPExp ::= Val
  syntax Val ::= Int | String
  syntax Vals ::= List{Val, ","}
  syntax KResult ::= Val | Vals

  rule S1 ; S2 => S1 ~> S2
  rule {} => .
  rule var .Ids => .
  rule print(.Vals) => .

  rule <k> var (X,Xs => Xs) ...</k>
       <env> Ro:Map => Ro[X <- !L:Int] </env>
       <store> Sigma:Map (. => !L |-> 0) </store>

  rule <k> X => V:Int ...</k>
       <env>... X |-> L:Int ...</env>
       <store>... L |-> V ...</store>

  rule <k> X := V:Int => . ...</k>
       <env>... X |-> L ...</env>
       <store>... L |-> (_ => V) ...</store>

  rule <k> { S } => S ~> Ro ...</k>
       <env> Ro:Map </env>

  rule <k> Ro => . ...</k>
       <env> _ => Ro </env>

  rule <k> print (V:Val, Vs => Vs) ...</k>
       <out>... . => ListItem(V) </out>

endmodule
