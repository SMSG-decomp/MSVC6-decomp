int __cdecl lookup_operator_function(c1_symbol *sym,int scope_cls)

{
  c1_symbol *pcVar1;
  int iVar2;
  
  pcVar1 = class_lookup_qualified_member(g_current_scope,sym,(c1_symbol *)scope_cls,0xc);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = class_lookup_qualified_member(g_current_scope,sym,(c1_symbol *)scope_cls,8);
    if (pcVar1 == (c1_symbol *)0x0) {
      return 0;
    }
  }
  iVar2._0_2_ = pcVar1->type->code;
  iVar2._2_2_ = pcVar1->type->flags;
  return iVar2;
}

