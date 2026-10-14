int __cdecl yyparse_lookahead_stack_overflow(void)

{
  uint uVar1;
  
  parse_table_yyerror_nop("yacc stack overflow");
  uVar1 = yyparse_lookahead_return_1();
  return uVar1;
}

