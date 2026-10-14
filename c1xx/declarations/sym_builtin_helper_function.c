c1_symbol * __cdecl sym_builtin_helper_function(int index)

{
  byte bVar1;
  void *name;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  char local;
  
  local = '\0';
  name = name_intern(g_builtin_helper_table[index].name);
  pcVar2 = sym_new_object(name,local);
  pcVar2->kind = pcVar2->kind & 0xe7 | 7;
  pcVar3 = sym_new_builtin_helper(g_builtin_helper_table[index].convention,g_type_int);
  bVar1 = pcVar2->flags1;
  pcVar2->type = pcVar3;
  (pcVar2->tail).fn.op_token = '\x01';
  pcVar2->flags1 = bVar1 & 0xfe | 2;
  return pcVar2;
}

