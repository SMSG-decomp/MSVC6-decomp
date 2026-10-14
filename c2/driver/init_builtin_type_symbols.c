void init_builtin_type_symbols(void)

{
  int32_t value;
  
  value = 0;
  fe_set_type4_store_st0(&value,&g_ld_const_zero);
  value = 1;
  fe_set_type4_store_st0(&value,&g_ld_const_one);
  value = 2;
  fe_set_type4_store_st0(&value,&g_ld_const_two);
  return;
}

