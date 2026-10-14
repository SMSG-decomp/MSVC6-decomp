c2_fe_symbol * label_symbol_new(void)

{
  c2_fe_symbol *fsym;
  uint32_t uVar1;
  
  fsym = fe_symbol_alloc('\x03',1);
  fsym->role = ' ';
  uVar1 = fe_symbol_next_id();
  fsym->id = uVar1;
  fe_symbol_hash_insert(fsym,1);
  return fsym;
}

