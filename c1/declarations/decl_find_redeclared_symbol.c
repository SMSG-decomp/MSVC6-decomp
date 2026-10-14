int * __thiscall decl_find_redeclared_symbol(void *scope,c1_declaration *decl)

{
  uchar *puVar1;
  c1_scope_lookup *found;
  c1_symbol *pcVar2;
  
  found = (c1_scope_lookup *)(**(code **)(*(int *)scope + 8))(decl->name);
  if (found != (c1_scope_lookup *)0x0) {
    pcVar2 = decl_check_redefinition(decl,found->sym);
    puVar1 = g_arenas[3].cur;
    if (pcVar2 != (c1_symbol *)0x0) {
      g_arenas[3].cur = g_arenas[3].cur + 8;
      if (g_arenas[3].end < g_arenas[3].cur) {
        arena_grow(g_arenas + 3);
      }
      if (puVar1 != (uchar *)0x0) {
        *(c1_symbol **)puVar1 = pcVar2;
        puVar1[4] = '\0';
        puVar1[5] = '\0';
        puVar1[6] = '\0';
        puVar1[7] = '\0';
        return (int *)puVar1;
      }
    }
  }
  return (int *)0x0;
}

