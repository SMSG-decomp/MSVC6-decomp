int globopt_free_expr_tables(void)

{
  int iVar1;
  
  clear_expression_hash();
  iVar1 = arena_reset(0xe);
  return iVar1;
}

