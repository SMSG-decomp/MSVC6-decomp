int __fastcall operand_readable_at_width(c2_operand *opnd,int width)

{
  int iVar1;
  uint8_t uVar2;
  c2_tuple *t;
  c2_symbol *pcVar3;
  c2_fe_symbol *pcVar4;
  int iVar5;
  c2_operand *pcVar6;
  uint uVar7;
  
  switch(opnd->kind) {
  case '\x01':
    if ((1 << (opnd->kind & 0x1f) & 6U) != 0) {
      t = opnd->sym->def;
      if ((t != (c2_tuple *)0x0) && (width < (int)(opnd->type & 0xfff))) {
        pcVar6 = find_dst_symbol_ref(t,opnd->sym);
        if (pcVar6->sym->offset < width) {
          return 1;
        }
        return 0;
      }
    }
    pcVar3 = opnd->sym;
    if (((((pcVar3 != (c2_symbol *)0x0) && ((int)(opnd->type & 0xfff) < width)) &&
         (uVar2 = pcVar3->cls, uVar2 != '\x03')) && ((uVar2 != '\x04' && (uVar2 != '\x05')))) &&
       (uVar2 != '\x06')) {
      pcVar4 = pcVar3->storage->fe;
      iVar5 = pcVar3->storage->size;
      iVar1 = pcVar3->offset + width;
      if (iVar5 < iVar1) {
        if (pcVar4 != (c2_fe_symbol *)0x0) {
          uVar7 = pcVar4->storage & 0x780;
          if (uVar7 == 0x180) {
            return 0;
          }
          if (uVar7 == 0x100) {
            return 0;
          }
        }
        if (g_default_stack_align < width) {
          return 0;
        }
        if ((width - 1U & pcVar4->offset) != 0) {
          return 0;
        }
      }
      if (((pcVar3->offset & 3U) != 0) && (3 < iVar5)) {
        if (g_opt_favor_speed != 0) {
          return 0;
        }
        if (iVar5 < iVar1) {
          return 0;
        }
      }
      if ((opnd->flags & 0x40) != 0) {
        return 0;
      }
    }
switchD_1071c98b_caseD_7:
    return 1;
  case '\x02':
    if (opnd->op != 0x14a) {
      return (uint)(width <= (int)(opnd->type & 0xfff));
    }
    return 1;
  default:
    return 0;
  case '\x06':
    return (uint)(width <= (int)(opnd->type & 0xfff));
  case '\a':
    goto switchD_1071c98b_caseD_7;
  }
}

