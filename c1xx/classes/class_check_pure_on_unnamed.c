void class_check_pure_on_unnamed(c1_declarator *d)

{
  uint *puVar1;
  byte *pbVar2;
  c1_class_record *pcVar3;
  char cVar4;
  c1_symbol *pcVar5;
  
  pcVar5 = d->sym;
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = sym_new_from_declarator(d,5);
  }
  diag_error(0x23b,g_class_def_stack[g_class_depth].cls,pcVar5);
  if ((d->spec[1] & 2) != 0) {
    puVar1 = &d->name->flags;
    *puVar1 = *puVar1 | 0x100000;
  }
  if (((*(byte *)((int)&d->sym->tail + 8) & 1) != 0) &&
     (cVar4 = class_overrides_base_virtual
                        ((c1_sym_link *)&d->sym->name,g_class_def_stack[g_class_depth].cls,'\x01'),
     cVar4 != '\0')) {
    d->sym->flags21 = d->sym->flags21 | 2;
    puVar1 = &d->sym->name->flags;
    *puVar1 = *puVar1 | 0x100000;
  }
  if ((d->flags56 & 2) != 0) {
    pcVar5 = d->sym;
    if ((pcVar5->flags21 & 2) == 0) {
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0xfd,pcVar5);
    }
    else if (((g_class_def_stack[g_class_depth].cls)->flags3 & 1) == 0) {
      pcVar3 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
      pcVar3->layout_flags3b = pcVar3->layout_flags3b | 0x80;
      pbVar2 = (byte *)((int)&d->sym->tail + 8);
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0x11b,pcVar5,(g_class_def_stack[g_class_depth].cls)->type);
    }
  }
  decl_check_operator_function(d->sym,0);
  decl_check_default_parameters_of(d->sym);
  if ((g_compile_flags_c4 & 0x4000000) == 0) {
    func_parse_definition_or_skip(d->sym,d->spec[1] >> 2 & 1);
  }
  else if ((((g_class_def_stack[g_class_depth].flags & 0x10) == 0) &&
           (g_current_function != (c1_symbol *)0x0)) &&
          (pcVar5 = d->sym, (*(byte *)((int)&pcVar5->tail + 9) & 0x10) == 0)) {
    *(byte *)((int)&pcVar5->tail + 8) = *(byte *)((int)&pcVar5->tail + 8) & 0xf7;
    class_synthesize_special_member_tokens(g_class_def_stack[g_class_depth].cls,d->sym);
    return;
  }
  return;
}

