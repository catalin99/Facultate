module CALCULY-SYNTAX
syntax Expressions ::= Int
                     | "dar mai intai" Expressions "apoi ailalta"         [bracket]
                     | "," Expressions "."                                [bracket]
                     > left:
                       "inmulteste oleaca" Expressions "cu" Expressions   [left, strict]
                     | "imparti" Expressions "cu" Expressions             [left, strict]
                     > left:
                       "aduna" Expressions "cu" Expressions               [left, strict]
                     | "scade" Expressions "din" Expressions              [left, strict]
endmodule

module CALCULY
  imports CALCULY-SYNTAX
  syntax KResult ::= Int
  configuration <k> $PGM:Expressions </k>
  rule aduna I1:Int cu I2:Int => I1 +Int I2
  /* rule scade I1:Int din I2:Int => I2 -Int I1 */
  rule inmulteste oleaca I1:Int cu I2:Int => I1 *Int I2
  // rule imparti I1:Int cu I2:Int => I1 /Int I2 when I2 =/=Int 0
endmodule
