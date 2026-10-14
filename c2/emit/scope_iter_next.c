c2_fe_symbol * __fastcall scope_iter_next(c2_scope_table *scope,c2_fe_symbol *prev)

{
  c2_fe_symbol *pcVar1;
  int iVar2;
  c2_fe_symbol **ppcVar3;
  
  if (prev == (c2_fe_symbol *)0x0) {
    g_scope_iter_bucket = -1;
    g_scope_iter_entry = (c2_fe_symbol *)0x0;
    g_scope_iter_table = scope;
  }
  else {
    if ((g_scope_iter_entry != prev) || (g_scope_iter_table != scope)) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x8ea);
    }
    pcVar1 = prev->next;
    if (pcVar1 != (c2_fe_symbol *)0x0) {
      g_scope_iter_entry = pcVar1;
      return pcVar1;
    }
  }
  iVar2 = g_scope_iter_bucket + 1;
  if (iVar2 < 0x400) {
    ppcVar3 = scope->buckets + g_scope_iter_bucket + 1;
    do {
      if (*ppcVar3 != (c2_fe_symbol *)0x0) {
        g_scope_iter_bucket = iVar2;
        g_scope_iter_entry = scope->buckets[iVar2];
        return scope->buckets[iVar2];
      }
      iVar2 = iVar2 + 1;
      ppcVar3 = ppcVar3 + 1;
    } while (iVar2 < 0x400);
  }
  g_scope_iter_bucket = iVar2;
  return (c2_fe_symbol *)0x0;
}

