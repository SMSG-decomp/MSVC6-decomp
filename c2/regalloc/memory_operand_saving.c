uint32_t __fastcall memory_operand_saving(c2_tuple *t,c2_symbol *sym)

{
  uint8_t uVar1;
  uint uVar2;
  int iVar3;
  c2_operand *pcVar4;
  
  uVar1 = sym->cls;
  if (g_opt_favor_speed != 0) {
    if (uVar1 != '\r') {
      return 2;
    }
    uVar2 = t->op;
    if (((uVar2 == 0) || (0x143 < uVar2)) || ((g_x86_op_flags[uVar2] & 0x800) != 0)) {
      pcVar4 = t->dst;
    }
    else {
      pcVar4 = t->src;
    }
    if (((uVar2 == 0x2f) && (((sym->u28).const_operand)->kind == '\a')) &&
       ((((sym->u28).const_operand)->u18).reg == (c2_symbol *)0x0)) {
      return 0;
    }
    uVar1 = pcVar4->kind;
    if ((uVar1 != '\x02') &&
       ((uVar1 != '\x06' || ((pcVar4->base_sym == (c2_symbol *)0x0 && (pcVar4->disp == 0)))))) {
      if (((uVar1 == '\x01') && (((pcVar4->u18).reg)->cls == '\x02')) && (pcVar4->sym != sym)) {
        pcVar4->flags11 = pcVar4->flags11 | 0x80;
      }
      return 0;
    }
    return 1;
  }
  if (uVar1 == '\r') {
    pcVar4 = (sym->u28).const_operand;
    if (pcVar4->kind == '\a') {
      if ((pcVar4->u18).reg == (c2_symbol *)0x0) {
        if (t->op == 1) {
          pcVar4 = t->dst;
          if (pcVar4->kind != '\x01') {
            return 1;
          }
          uVar1 = ((pcVar4->u18).reg)->cls;
        }
        else {
          if (t->op != 0x2f) {
            return 1;
          }
          pcVar4 = t->src;
          if (pcVar4->kind != '\x01') {
            return 1;
          }
          uVar1 = ((pcVar4->u18).reg)->cls;
        }
        if (uVar1 != '\x02') {
          return 0;
        }
        pcVar4->flags11 = pcVar4->flags11 | 0x80;
        return 0;
      }
      iVar3 = const_compare(pcVar4,0xffffffff,-1);
      if (iVar3 != 0) {
        if (t->op == 1) {
          if (((t->type & 0xfff) != 4) ||
             ((c2_symbol *)(int)*(char *)&pcVar4->u18 != (pcVar4->u18).reg)) {
            return (t->type & 0xfff) - 1;
          }
          pcVar4 = t->dst;
          if (pcVar4->kind != '\x01') {
            return 3;
          }
          if (((pcVar4->u18).reg)->cls == '\x02') {
            pcVar4->flags11 = pcVar4->flags11 | 0x80;
            return 1;
          }
        }
        else if ((c2_symbol *)(int)*(char *)&pcVar4->u18 != (pcVar4->u18).reg) {
          return t->type & 0xfff;
        }
      }
      return 1;
    }
  }
  else if (((uVar1 == '\x03') || (uVar1 == '\x04')) || ((uVar1 == '\x05' || (uVar1 == '\x06')))) {
    return g_ebp_allocatable + 1;
  }
  return 4;
}

