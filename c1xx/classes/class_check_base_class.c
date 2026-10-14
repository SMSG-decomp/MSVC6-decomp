c1_symbol * __cdecl class_check_base_class(int access,char is_virtual,c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  c1_u8 cVar4;
  c1_symbol *pcVar5;
  
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  pcVar2 = sym->type;
  cVar1 = (char)pcVar2->code;
  pcVar3 = pcVar2;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  if ((pcVar3->code & 0xfff) != 0x801) {
    cVar1 = (char)pcVar2->code;
    pcVar3 = pcVar2;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0xfff) != 0x802) {
      if ((sym->kind & 0x1f) != 4) {
        if (((sym->flags2 & 0x10) == 0) || ((pcVar2->code >> 9 & 1) == 0)) {
          diag_error(0x204,sym);
          return (c1_symbol *)0x0;
        }
        if ((pcVar2->code & 0x200) == 0) {
          sym = (c1_symbol *)0x0;
        }
        else {
          sym = (pcVar2->extra).cls;
        }
      }
      if ((sym->flags2 & 4) == 0) {
        tmpl_instantiate_if_needed(sym);
      }
      if (((sym->flags2 & 4) == 0) && ((((sym->detail).cls)->flags3f & 0x80) == 0)) {
        diag_error(0x1f8,0x53,sym);
        return (c1_symbol *)0x0;
      }
      if ((g_class_def_stack[g_class_depth].flags & 8) == 0) {
        diag_error(0x23a,g_class_def_stack[g_class_depth].cls);
        return (c1_symbol *)0x0;
      }
      pcVar5 = g_class_def_stack[g_class_depth].cls;
      if ((((pcVar5->entity ^ sym->entity) & 0xffffff) == 0) &&
         (((g_compile_flags_cc & 0x100000) == 0 || (sym->name != pcVar5->name)))) {
        diag_error(0x2da,sym);
        return (c1_symbol *)0x0;
      }
      pcVar2 = sym->type;
      cVar1 = (char)pcVar2->code;
      pcVar3 = pcVar2;
      while (cVar1 < '\0') {
        pcVar3 = pcVar3->base;
        cVar1 = (char)pcVar3->code;
      }
      if ((pcVar3->code & 0x20f) != 0x203) {
        cVar1 = (char)pcVar2->code;
        while (cVar1 < '\0') {
          pcVar2 = pcVar2->base;
          cVar1 = (char)pcVar2->code;
        }
        if ((pcVar2->code & 0x100) == 0) {
          if (((sym->flags5 & 1) != 0) && ((((sym->detail).cls)->flags3f & 0x80) == 0)) {
            diag_error(0x1f7,sym);
            return (c1_symbol *)0x0;
          }
          if (((pcVar5->flags22 & 0xc) != 0) && ((sym->flags22 & 0xc) == 0)) {
            pcVar5 = class_warn_dll_interface_base(sym,access,is_virtual);
            return pcVar5;
          }
          cVar4 = class_check_duplicate_base(is_virtual,sym,g_class_def_stack[g_class_depth].cls);
          if (cVar4 != '\0') {
            pcVar5 = class_append_base_entry(access,is_virtual,sym);
            return pcVar5;
          }
          return (c1_symbol *)0x0;
        }
      }
      diag_error(0x239,sym);
      return (c1_symbol *)0x0;
    }
  }
  pcVar5 = class_add_dependent_base_entry(access,is_virtual,sym);
  return pcVar5;
}

