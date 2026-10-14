void __thiscall
class_scope_lookup_anonymous_member(c1xx_class_scope *class_scope,void *name,int *found)

{
  c1_symbol *pcVar1;
  int iVar2;
  
  if ((class_scope->cls->type->code & 0x200) != 0) {
    pcVar1 = sym_chain_find_name((c1_symbol *)(((class_scope->cls->x28).enumerators)->compare - 8),
                                 name);
    if (pcVar1 != (c1_symbol *)0x0) {
      if (*found != 0) {
        iVar2 = asm_operand_description_id();
        diag_error(0x19a,name,iVar2);
      }
      g_symbol_scope_level = class_scope->kind;
      *found = (int)pcVar1;
    }
  }
  return;
}

