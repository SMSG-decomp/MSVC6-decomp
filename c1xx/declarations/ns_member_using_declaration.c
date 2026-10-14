void __cdecl ns_member_using_declaration(byte *result)

{
  c1_symbol *pcVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  c1_u8 cVar4;
  c1_keyed_cell *pcVar5;
  c1_symbol *sym;
  c1_symbol *local_8;
  c1_keyed_cell *local_4;
  
  sym = (c1_symbol *)result;
  if ((*result & 0x1f) == 0x12) {
    local_4 = (c1_keyed_cell *)**(undefined4 **)(result + 0x14);
    if (local_4 != (c1_keyed_cell *)(*(undefined4 **)(result + 0x14))[1]) {
      return;
    }
    sym = local_4->sym;
    pcVar5 = local_4->key;
    if (pcVar5 == (c1_keyed_cell *)0x0) {
      diag_error(0x377,sym);
      return;
    }
    local_8 = (c1_symbol *)0x0;
    pcVar1 = g_class_def_stack[g_class_depth].cls;
    do {
      pcVar2 = pcVar5->sym;
      switch(pcVar2->kind & 0x1f) {
      case 4:
        if (pcVar2 != pcVar1) {
          diag_error(0x25a,pcVar5->sym,sym,pcVar1);
          return;
        }
      default:
        pcVar2 = local_8;
        break;
      case 0xf:
        if ((pcVar2->key_ref & 0x20000) != 0) goto LAB_104ad7f3;
        break;
      case 0x16:
      case 0x18:
        ns_check_using_multiple_declaration(sym,(c1_symbol *)result);
        return;
      case 0x19:
        diag_error(0x376,pcVar5->sym,sym);
        return;
      }
      local_8 = pcVar2;
      pcVar2 = local_8;
      pcVar5 = pcVar5->key;
    } while (pcVar5 != (c1_keyed_cell *)0x0);
    pcVar5 = local_4->next;
    if ((pcVar5 != (c1_keyed_cell *)0x0) && (pcVar5 == pcVar5->next)) {
      if (local_8 != pcVar5->sym) {
        diag_error(0x25b,g_scope_vector->entries[(short)pcVar5->sym->key_ref],pcVar1);
        return;
      }
      local_8 = (c1_symbol *)((uint)local_8 & 0xffffff00);
      bVar3 = sym->kind & 0x1f;
      if (((((bVar3 == 0x10) || (bVar3 == 7)) || (bVar3 == 6)) ||
          (((bVar3 == 0x11 || (bVar3 == 8)) || (bVar3 == 0x1b)))) ||
         ((bVar3 == 0x1a &&
          (((bVar3 = **(byte **)sym->type & 0x1f, bVar3 == 0x10 || (bVar3 == 7)) ||
           ((bVar3 == 6 || (((bVar3 == 0x11 || (bVar3 == 8)) || (bVar3 == 0x1b)))))))))) {
        cVar4 = access_least_member_through_path(sym,local_4,(c1_u8 *)&local_8);
        if (cVar4 == '\0') {
          diag_error(0x36c,g_scope_vector->entries[(short)pcVar2->key_ref],sym);
          return;
        }
      }
      else {
        cVar4 = access_member_through_path(local_4);
        local_8 = (c1_symbol *)CONCAT31(local_8._1_3_,cVar4);
        if (cVar4 == '\0') {
          if ((g_compile_flags_cc & 0x100000) == 0) goto LAB_104ad815;
        }
        else if (cVar4 == '\x01') {
LAB_104ad815:
          diag_error(0x36d,g_scope_vector->entries[(short)pcVar2->key_ref],sym);
          return;
        }
      }
LAB_104ad7f3:
      ns_check_using_multiple_declaration(sym,(c1_symbol *)result);
      return;
    }
  }
  diag_error(0x364,sym);
  return;
}

