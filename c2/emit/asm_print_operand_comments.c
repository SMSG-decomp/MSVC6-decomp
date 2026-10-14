void __thiscall asm_print_operand_comments(c2_tuple *t,int bytes)

{
  int iVar1;
  uint32_t uVar2;
  c2_fe_symbol *pcVar3;
  int first;
  c2_operand *pcVar4;
  char *fmt;
  c2_symbol *pcVar5;
  
  pcVar4 = (c2_operand *)0x0;
  first = 1;
  if ((g_opt_listing_bytes_comment != 0) && (0 < bytes)) {
    first = asm_print_operand_separator(1);
    iVar1 = asm_printf("bytes=%d",bytes);
    g_asm_column = g_asm_column + iVar1;
  }
  uVar2 = t->op;
  bytes = 0;
  if (0 < g_x86_op_operand_count[uVar2]) {
    do {
      if (pcVar4 == (c2_operand *)0x0) {
        if ((g_x86_op_flags[uVar2] & 0x800) == 0) {
LAB_107755fe:
          pcVar4 = t->src;
        }
        else {
          pcVar4 = t->dst;
        }
      }
      else {
        if (pcVar4 == t->dst) goto LAB_107755fe;
        pcVar4 = pcVar4->next;
      }
      switch(pcVar4->op) {
      case 0x146:
        pcVar5 = (pcVar4->u18).reg;
        if ((9 < (int)pcVar5) || ((int)pcVar5 < -1)) {
          first = asm_print_operand_separator(first);
          fmt = "%.8lxH";
LAB_10775623:
          iVar1 = asm_printf(fmt,pcVar5);
          g_asm_column = g_asm_column + iVar1;
        }
        break;
      case 0x14b:
        pcVar3 = pcVar4->sym->fe;
        goto LAB_107756d2;
      case 0x150:
        pcVar3 = pcVar4->base_sym->fe;
LAB_107756d2:
        if ((((pcVar3 != (c2_fe_symbol *)0x0) &&
             ((pcVar3->cls == '\x04' || (pcVar3->cls == '\x01')))) && (pcVar3->role == '\0')) &&
           (*pcVar3->name == '?')) {
LAB_107756ad:
          first = asm_print_symbol_operand(pcVar3,first);
        }
        break;
      case 0x153:
      case 0x154:
        pcVar3 = (c2_fe_symbol *)pcVar4->sym;
        if (pcVar3 == (c2_fe_symbol *)0x0) break;
        if ((((pcVar3->cls == '\x04') || (pcVar3->cls == '\x01')) && (pcVar3->role == '\0')) &&
           (*pcVar3->name == '?')) {
          first = asm_print_symbol_operand(pcVar3,first);
        }
        if ((pcVar3->cls != '\x04') || (((byte)pcVar3->attrs & 0xc) != 0xc)) break;
        pcVar3 = (pcVar3->u4a).function.x4b;
        if ((pcVar3->role != '\0') || (*pcVar3->name != '?')) {
          first = asm_print_operand_separator(first);
          pcVar5 = (c2_symbol *)pcVar3->name;
          fmt = "%s";
          goto LAB_10775623;
        }
        goto LAB_107756ad;
      }
      uVar2 = t->op;
      bytes = bytes + 1;
    } while (bytes < g_x86_op_operand_count[uVar2]);
  }
  return;
}

