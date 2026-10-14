int yy_stack_overflow(void)

{
  yyerror_c("yacc stack overflow");
  return 1;
}

