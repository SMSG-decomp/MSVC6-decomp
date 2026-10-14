int __fastcall fe_symbol_resolve_redirect(int key)

{
  c2_fe_symbol *pcVar1;
  c2_fe_symbol_redirect *pcVar2;
  
  pcVar1 = g_fe_symbol_redirect_map->original;
  pcVar2 = g_fe_symbol_redirect_map;
  while (pcVar1 != (c2_fe_symbol *)key) {
    pcVar2 = pcVar2->next;
    pcVar1 = pcVar2->original;
  }
  return (int)pcVar2->copy;
}

