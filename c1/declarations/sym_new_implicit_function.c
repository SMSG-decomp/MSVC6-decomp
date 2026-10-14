c1_symbol * __cdecl sym_new_implicit_function(int name)

{
  c1_symbol *pcVar1;
  char level;
  
  if (g_ms_extensions == '\0') {
    level = '\x02';
  }
  else {
    level = '\0';
  }
  pcVar1 = sym_new_object((void *)name,level);
  pcVar1->kind = pcVar1->kind & 0xe7 | 7;
  pcVar1->type = g_type_function_returning_int;
  pcVar1->flags3 = pcVar1->flags3 | 0x80;
  pcVar1->storage = pcVar1->storage & 0xf8 ^ 1;
  return pcVar1;
}

