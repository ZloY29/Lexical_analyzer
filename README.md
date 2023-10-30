# Lexical_analyzer
Laboratory work in which it was necessary to make your own lexical analyzer that recognizes the language specified by a context-free grammar.

Option 21
Procedure → Begin Descriptions Operators End Begin → procedure ProcedureName ; begin
End → end
ProcedureName → Id
Descriptions → var DescrList
DescrList → Descr | Descr DescrList
Descr → VarList : Type ;
VarList → Id | Id , VarList
Type → integer
Operators → Op | Op Operators
Op → Id := Expr ; | if Condition then Op | if ( Condition ) then Op else Op Expr → SimpleExpr | SimpleExpr + Expr | SimpleExpr - Expr
SimpleExpr → Id | Const | ( Expr )
Condition → Expr RelationOperator Expr
RelationOperator → = | <> | > | <
Id → Letter | Letter Id
Const → Digit | Digit Const
Digit → 0 | 1 | . . . | 9
Letter → a | b | . . . | z | A | B | . . . | Z

