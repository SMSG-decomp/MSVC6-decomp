int __fastcall op_supports_width(c2_tuple *t,int width)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  ushort uVar4;
  c2_tuple *pcVar5;
  c2_operand *local_4;
  
  uVar4 = t->type & 0xfff;
  if (uVar4 == 2) {
    return 1;
  }
  if (uVar4 != 4) {
    return 0;
  }
  uVar1 = t->op;
  if (uVar1 < 0x15c) {
    if ((uVar1 == 0x15b) || (uVar1 == 1)) {
      if (t->src->kind != '\a') {
        return 0;
      }
      pcVar3 = (t->src->u18).reg;
      goto LAB_1072253c;
    }
    if (uVar1 != 0x2f) {
      return 0;
    }
  }
  else {
    if (uVar1 == 0x172) {
      if (width != 2) {
        if (width != 1) {
          return 0;
        }
        if ((1 << (t->dst->kind & 0x1f) & 6U) == 0) {
          return 0;
        }
        if (t->dst->sym->def == (c2_tuple *)0x0) {
          return 0;
        }
        local_4 = (c2_operand *)t;
        pcVar5 = find_next_use_of_dst(t,&local_4);
        if (pcVar5->op != 0x17d) {
          return 0;
        }
        pcVar2 = pcVar5->src->next;
        if (pcVar2->kind != '\a') {
          return 0;
        }
        if ((pcVar2->u18).reg != (c2_symbol *)0x0) {
          return 0;
        }
        return 1;
      }
      if (g_opt_favor_speed != 0) {
        return 0;
      }
      pcVar2 = t->src->next;
      if (pcVar2->kind != '\a') {
        return 0;
      }
      pcVar3 = (c2_symbol *)((int)*(char *)&pcVar2->u18 - (pcVar2->u18).lo);
LAB_1072253c:
      if (pcVar3 == (c2_symbol *)0x0) {
        return 0;
      }
      return 1;
    }
    if (uVar1 != 0x17d) {
      return 0;
    }
  }
  if (width == 1) {
    return 1;
  }
  if (width == 2) {
    pcVar2 = t->src;
    if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
       (pcVar5 = pcVar2->sym->def, pcVar5 != (c2_tuple *)0x0)) {
      if ((pcVar5->op == 0x15f) &&
         ((uVar4 = pcVar5->src->type, (1 << (byte)(uVar4 >> 0xc) & 0xeU) != 0 &&
          ((uVar4 & 0xfff) == 2)))) {
        return 1;
      }
      if (((pcVar5->type & 0xfff) == 2) && (pcVar5->op == 0x15b)) {
        return 1;
      }
    }
    if (((1 << (pcVar2->next->kind & 0x1f) & 6U) != 0) &&
       (pcVar5 = pcVar2->next->sym->def, pcVar5 != (c2_tuple *)0x0)) {
      if ((pcVar5->op == 0x15f) &&
         ((uVar4 = pcVar5->src->type, (1 << (byte)(uVar4 >> 0xc) & 0xeU) != 0 &&
          ((uVar4 & 0xfff) == 2)))) {
        return 1;
      }
      if (((pcVar5->type & 0xfff) == 2) && (pcVar5->op == 0x15b)) {
        return 1;
      }
    }
  }
  return 0;
}

