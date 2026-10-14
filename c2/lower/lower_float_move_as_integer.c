int __fastcall lower_float_move_as_integer(c2_tuple *t)

{
  char cVar1;
  byte bVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_symbol *pcVar8;
  c2_tuple *pcVar9;
  uint uVar10;
  int iVar11;
  c2_operand *local_4;
  
  if ((1 << (t->kind & 0x1f) & 0x2000U) != 0) {
    return 0;
  }
  if ((t->type & 0xf000) != 0x4000) {
    return 0;
  }
  uVar5 = t->op;
  local_4 = (c2_operand *)t;
  if (uVar5 == 0x15a) {
    if (((t->src->kind == '\x01') && (pcVar8 = t->src->sym, pcVar8->cls == '\x03')) &&
       (pcVar8->def != (c2_tuple *)0x0)) {
      return 0;
    }
    pcVar9 = find_next_use_of_dst(t,&local_4);
    if (pcVar9->op != 0x184) {
      return 0;
    }
    if (((pcVar9->u24).call.conv == '\x18') && (local_4 == pcVar9->src->next)) {
      return 0;
    }
  }
  else {
    if (uVar5 == 0x15b) {
      uVar3 = t->dst->kind;
      if (((uVar3 != '\x01') || (pcVar8 = t->dst->sym, pcVar8->cls != '\x03')) ||
         (pcVar8->def == (c2_tuple *)0x0)) {
        uVar4 = t->src->kind;
        if (((uVar4 != '\x01') || (pcVar8 = t->src->sym, pcVar8->cls != '\x03')) ||
           (pcVar8->def == (c2_tuple *)0x0)) {
          if (((g_opt_global != 0) && (g_opt_float_consistency == 0)) &&
             ((uVar3 == '\x02' || (uVar4 == '\x02')))) {
            return 0;
          }
          goto LAB_1075c6e7;
        }
      }
      return 0;
    }
    if (uVar5 != 0x17d) {
      return 0;
    }
    pcVar9 = find_next_use_of_dst(t,&local_4);
    cVar1 = (char)pcVar9->type;
    if ((cVar1 != '\x02') && (cVar1 != '\x01')) {
      return 0;
    }
    pcVar6 = t->src;
    for (pcVar7 = pcVar6; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
      if ((((pcVar7->kind == '\x01') && (pcVar7->sym->cls == '\x03')) &&
          (pcVar9 = pcVar7->sym->def, pcVar9 != (c2_tuple *)0x0)) && (pcVar9->op != 0x12)) {
        return 0;
      }
    }
    bVar2 = pcVar6->kind;
    uVar10 = 1 << (bVar2 & 0x1f) & 0x380;
    if ((uVar10 != 0) && ((1 << (pcVar6->next->kind & 0x1f) & 0x380U) != 0)) {
      return 0;
    }
    if (uVar10 == 0) {
      if ((1 << (pcVar6->next->kind & 0x1f) & 0x380U) == 0) {
        return 0;
      }
    }
    else {
      iVar11 = float_const_compare_mask(1,(c2_float_const *)pcVar6->sym,&g_ld_const_zero);
      if (iVar11 != 0) {
        return 0;
      }
      if (((g_opt_global != 0) && (g_opt_float_consistency == 0)) && (pcVar6->next->kind == '\x02'))
      {
        return 0;
      }
    }
    if ((1 << (pcVar6->next->kind & 0x1f) & 0x380U) != 0) {
      iVar11 = float_const_compare_mask(1,(c2_float_const *)pcVar6->next->sym,&g_ld_const_zero);
      if (iVar11 != 0) {
        return 0;
      }
      if (((g_opt_global != 0) && (g_opt_float_consistency == 0)) && (bVar2 == 2)) {
        return 0;
      }
    }
  }
LAB_1075c6e7:
  emit_float_move_as_integer(t);
  return 1;
}

