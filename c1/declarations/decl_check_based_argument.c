int __cdecl decl_check_based_argument(int name)

{
  c1_symbol *sym;
  c1_type *pcVar1;
  c1_scope_lookup *found;
  ushort uVar2;
  
  found = scope_stack_lookup(g_current_scope,name);
  if (found == (c1_scope_lookup *)0x0) {
    diag_error(0x41,name);
    return 0;
  }
  sym = found->sym;
  pcVar1 = sym->type;
  if (((((char)pcVar1->code < '\0') && (pcVar1 != (c1_type *)0x0)) &&
      ((uVar2 = pcVar1->code & 0x8f, uVar2 == 0x86 || (uVar2 == 0x82)))) &&
     ((pcVar1->flags & 8) == 0)) {
    if (g_opt_Zi != '\0') {
      sym_mark_referenced(sym);
      return (int)sym;
    }
  }
  else {
    diag_error(0xd5,name);
  }
  return (int)sym;
}

