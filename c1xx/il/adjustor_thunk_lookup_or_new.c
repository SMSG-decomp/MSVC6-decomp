c1_symbol * __cdecl adjustor_thunk_lookup_or_new(int kind,c1_symbol *target,int delta,int vtordisp)

{
  c1_thunk_key *thunk_key;
  c1_symbol *pcVar1;
  c1_u8 *key;
  c1_symbol *value;
  
  thunk_key = (c1_thunk_key *)record4_new(kind,(int)target,delta,vtordisp,5);
  if (g_adjustor_thunk_table == (c1_symtab *)0x0) {
    g_adjustor_thunk_table = symtab_new(0x20,0,5,4,'\x01','\x01');
  }
  pcVar1 = symtab_lookup(g_adjustor_thunk_table,thunk_key);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = sym_clone_with_new_id(thunk_key);
    value = pcVar1;
    key = record4_copy((int *)thunk_key,0);
    symtab_insert(g_adjustor_thunk_table,key,value);
  }
  return pcVar1;
}

