void __fastcall
operand_constraints_by_opcode
          (c2_tuple *t,c2_operand *opnd,c2_operand *s,c2_operand *opnd2,uint32_t *out)

{
  uint16_t uVar1;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  uint32_t *out_00;
  uint8_t uVar4;
  c2_tuple *pcVar5;
  int iVar6;
  c2_operand *pcVar7;
  byte bVar8;
  uint uVar9;
  uint32_t uVar10;
  bool bVar11;
  
  out_00 = out;
  uVar10 = 1;
  if ((1 << (t->kind & 0x1f) & 0xa0000U) == 0) {
    if (((s != (c2_operand *)0x0) && ((1 << (s->kind & 0x1f) & 0x18U) != 0)) &&
       ((s->type & 0xfff) < 4)) {
      *out = *out | 2;
    }
    if (((opnd2 != (c2_operand *)0x0) && ((1 << (opnd2->kind & 0x1f) & 0x18U) != 0)) &&
       ((opnd2->type & 0xfff) < 4)) {
      *out = *out | 4;
    }
  }
  uVar9 = t->op;
  if (uVar9 < 0xa4) {
    if (uVar9 == 0xa3) {
      if (s->kind == '\x01') {
        return;
      }
      *out = *out | 2;
      return;
    }
    switch(uVar9) {
    case 1:
      uVar9 = 1 << (s->kind & 0x1f) & 0x18;
      if (((uVar9 != 0) && (s->op == 0x14a)) && (opnd->kind == '\x01')) {
        t->op = 0x12;
        return;
      }
      if (opnd->kind == '\x01') {
        return;
      }
      if (s->kind == 1) {
        return;
      }
      uVar10 = s->op;
      if (uVar10 == 0x146) {
        return;
      }
      if (uVar10 == 0x147) {
        return;
      }
      if (uVar9 != 0) {
        if (uVar10 != 0x14a) {
          return;
        }
        *out = *out | 2;
        return;
      }
      goto LAB_107124d1;
    case 6:
    case 0x1f:
    case 0x20:
    case 0x22:
      goto switchD_107122bd_caseD_6;
    case 9:
      uVar10 = opnd2->op;
      if (((uVar10 == 0x146) || (uVar10 == 0x147)) ||
         (((1 << (opnd2->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) {
        *out = *out | 4;
        return;
      }
      break;
    case 10:
      if ((opnd->kind != '\x01') || (((opnd->u18).reg)->storage != g_reg_symbols + 1)) {
        out[1] = 1;
        *out = *out | 1;
      }
      goto LAB_1076cd0a;
    case 0xb:
      if ((opnd2->kind != '\x01') || (((opnd2->u18).reg)->storage != g_reg_symbols + 1)) {
        out[3] = 1;
        *out = *out | 4;
      }
LAB_1076cd0a:
      uVar10 = s->op;
      if ((((uVar10 == 0x146) || (uVar10 == 0x147)) ||
          (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) &&
         (((s->u18).lo & 0xff) == (s->u18).lo)) {
        return;
      }
      out[2] = 3;
      *out = *out | 2;
      return;
    case 0xd:
      goto switchD_107122bd_caseD_d;
    case 0xe:
      if ((1 << (s->kind & 0x1f) & 0x380U) != 0) {
        *out = *out | 2;
      }
      if (opnd == (c2_operand *)0x0) {
        return;
      }
      if ((1 << (opnd->kind & 0x1f) & 6U) == 0) {
        return;
      }
      if ((t->src->kind == '\x04') && ((c2_fe_symbol *)t->src->sym == g_alloca_probe_symbol)) {
        return;
      }
      if ((t->type & 0xf000) == 0x4000) {
        return;
      }
      if ((opnd->kind == 1) && (((opnd->u18).reg)->storage == g_reg_symbols + 1)) {
        return;
      }
      out[1] = 1;
      *out = *out | 1;
      return;
    case 0x12:
      goto LAB_107124c7;
    case 0x1e:
    case 0x21:
      if (s->kind == '\a') {
        uVar9 = *out | 2;
        goto LAB_10712426;
      }
      break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      uVar10 = opnd2->op;
      if (((uVar10 != 0x146) && (uVar10 != 0x147)) &&
         ((((1 << (opnd2->kind & 0x1f) & 0x18U) == 0 || (uVar10 == 0x14a)) &&
          ((opnd2->kind != 1 || ((opnd2->u18).reg != g_reg_symbols + 2)))))) {
        out[3] = 2;
        *out = *out | 4;
      }
      break;
    case 0x2f:
      uVar10 = s->op;
      if (((((uVar10 == 0x146) || (uVar10 == 0x147)) ||
           (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) &&
          ((uVar2 = opnd2->op, uVar2 != 0x146 && (uVar2 != 0x147)))) &&
         (((1 << (opnd2->kind & 0x1f) & 0x18U) == 0 || (uVar2 == 0x14a)))) {
        pcVar5 = find_next_use_of_dst(t,(c2_operand **)&out);
        uVar4 = x86_fixed_reg_class(pcVar5);
        if (uVar4 != '\0') {
          uVar9 = *out_00 | 0x10;
          goto LAB_10712426;
        }
      }
      if ((((uVar10 == 0x146) || (uVar10 == 0x147)) ||
          (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) ||
         (((((s->kind != 1 && (uVar10 = opnd2->op, uVar10 != 0x146)) && (uVar10 != 0x147)) &&
           (((1 << (opnd2->kind & 0x1f) & 0x18U) == 0 || (uVar10 == 0x14a)))) && (opnd2->kind != 1))
         )) {
        uVar9 = *out_00 | 2;
        goto LAB_10712426;
      }
      break;
    case 0x33:
      if (s->kind == '\a') {
        uVar4 = opnd2->kind;
        uVar9 = *out | 0x10;
        *out = uVar9;
        if (uVar4 != '\a') {
          return;
        }
      }
      else {
        if ((opnd2->kind != '\x02') && (opnd2->kind != '\x06')) {
          return;
        }
        uVar9 = *out;
        if (s->kind == '\x01') {
          *out = uVar9 | 0x10;
          return;
        }
      }
      *out = uVar9 | 4;
      return;
    case 0x99:
      if ((s->kind == '\x01') && ((s->u18).reg == g_reg_symbols + 1)) goto LAB_107126d3;
      goto LAB_107126c6;
    case 0x9f:
      goto switchD_107122bd_caseD_9f;
    }
    goto switchD_107122bd_caseD_2;
  }
  switch(uVar9) {
  case 0xc1:
    if (s->kind != '\x01') {
      uVar9 = *out | 2;
LAB_10712426:
      *out_00 = uVar9;
    }
    break;
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
    if (opnd->kind != '\x01') {
      *out = *out | 1;
    }
    uVar10 = s->op;
    if (((uVar10 == 0x146) || (uVar10 == 0x147)) ||
       (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) {
      uVar9 = *out | 2;
      goto LAB_10712426;
    }
    break;
  case 0xca:
  case 0xcb:
    bVar8 = t->src->next->kind;
LAB_1076cea1:
    if (bVar8 != 1) {
      uVar9 = *out | 4;
      goto LAB_10712426;
    }
    break;
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
    uVar10 = s->op;
    if (((uVar10 == 0x146) || (uVar10 == 0x147)) ||
       (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar10 != 0x14a)))) {
      *out = *out | 2;
    }
    uVar10 = opnd2->op;
    if (((uVar10 != 0x146) && (uVar10 != 0x147)) &&
       ((bVar8 = opnd2->kind, (1 << (bVar8 & 0x1f) & 0x18U) == 0 || (uVar10 == 0x14a))))
    goto LAB_1076cea1;
    break;
  case 0xdf:
switchD_107122bd_caseD_9f:
    if ((s->kind == '\x01') && ((s->u18).reg == g_reg_symbols + 1)) goto LAB_107126d3;
LAB_107126c6:
    out[2] = 1;
    *out = *out | 2;
LAB_107126d3:
    out[1] = 1;
    *out = *out | 1;
    return;
  case 0x118:
  case 0x119:
    if (opnd->kind != '\x01') {
      uVar9 = *out | 1;
      goto LAB_10712426;
    }
    break;
  case 0x145:
  case 0x16b:
  case 0x191:
  case 0x198:
  case 0x1a0:
  case 0x1a8:
    goto switchD_107125da_caseD_145;
  case 0x15a:
    if (((opnd->kind == '\x01') && (opnd->sym->cls == '\x03')) &&
       ((opnd->sym->def != (c2_tuple *)0x0 && (((opnd->u18).reg)->cls == '\x01')))) {
      return;
    }
switchD_107122bd_caseD_d:
    bVar8 = s->kind;
    if (((((bVar8 == 1) && ((s->type & 0xfff) < 4)) && (((s->u18).reg)->cls == '\x02')) &&
        ((uVar4 = s->sym->cls, uVar4 != '\x03' && (uVar4 != '\x04')))) &&
       ((uVar4 != '\x05' && (uVar4 != '\x06')))) goto LAB_107124d1;
    uVar10 = s->op;
    if (uVar10 == 0x146) {
      return;
    }
    if (uVar10 == 0x147) {
      return;
    }
    if (((1 << (bVar8 & 0x1f) & 0x18U) != 0) && (uVar10 != 0x14a)) {
      return;
    }
    if (bVar8 == 1) {
      return;
    }
    if ((g_opt_favor_speed != 0) || ((bVar8 == 3 && (uVar10 == 0x14a)))) {
      *out = *out | 2;
    }
    if (3 < (s->type & 0xfff)) {
      return;
    }
    bVar11 = uVar10 == 0x14a;
    goto LAB_107124cb;
  case 0x166:
    uVar9 = *out;
    uVar4 = s->kind;
    *out = uVar9 | 8;
    if (uVar4 != '\a') {
      return;
    }
    if ((s->u18).reg != (c2_symbol *)0x183) {
      return;
    }
    if (s->tag != 0) {
      return;
    }
    if ((opnd2->kind == '\x01') && (iVar6 = operand_compare(opnd,opnd2), iVar6 == 0)) {
      return;
    }
    *out_00 = uVar9 | 0xc;
    return;
  case 0x176:
    uVar10 = (-(uint)(1 < (t->type & 0xfff)) & 0xffffffee) + 0x15;
switchD_107122bd_caseD_6:
    uVar2 = opnd2->op;
    if (((uVar2 == 0x146) || (uVar2 == 0x147)) ||
       (((1 << (opnd2->kind & 0x1f) & 0x18U) != 0 && (uVar2 != 0x14a)))) {
      *out = *out | 4;
    }
    iVar6 = tuple_reads_eax_not_first(t);
    if (iVar6 == 0) {
      out_00[2] = 1;
      *out_00 = *out_00 | 2;
    }
    else {
      uVar2 = s->op;
      if (((uVar2 == 0x146) || (uVar2 == 0x147)) ||
         (((1 << (s->kind & 0x1f) & 0x18U) != 0 && (uVar2 != 0x14a)))) {
        *out_00 = *out_00 | 2;
      }
    }
    if ((((opnd->kind == '\x01') && (opnd->sym->cls == '\x03')) &&
        (opnd->sym->def != (c2_tuple *)0x0)) && (((opnd->u18).reg)->cls == '\x01')) {
      return;
    }
    out_00[1] = uVar10;
    *out_00 = *out_00 | 1;
    return;
  case 0x18d:
    iVar6 = switch_use_byte_index_table((c2_node *)t);
    if (iVar6 != 0) {
      pcVar7 = t->src;
      if (g_opt_favor_speed == 0) {
        if (((pcVar7->kind == '\x01') && (pcVar7->sym->cls == '\x03')) &&
           (pcVar7->sym->def != (c2_tuple *)0x0)) {
          return;
        }
        *out_00 = *out_00 | 2;
        return;
      }
      if (pcVar7->kind != '\x01') {
        *out_00 = *out_00 | 2;
      }
      if (pcVar7->next != (c2_operand *)0x0) {
        return;
      }
      pcVar5 = tuple_new_pseudo(0x19e,0x1001);
      tuple_insert_before(t,pcVar5);
      pcVar7 = operand_new_temp(0x1001);
      bVar8 = pcVar7->flags;
      pcVar3 = pcVar7->sym;
      pcVar5->dst = pcVar7;
      pcVar7->flags = bVar8 | 0x10;
      pcVar3->def = pcVar5;
      tuple_append_src(t,pcVar7);
      return;
    }
    opnd = t->src;
LAB_107124c7:
    bVar11 = opnd->kind == '\x01';
LAB_107124cb:
    if (bVar11) {
      return;
    }
LAB_107124d1:
    *out_00 = *out_00 | 2;
    return;
  case 400:
    uVar1 = (t->u20).intrinsic.id;
    if (uVar1 == 0xdf) {
      return;
    }
    if (uVar1 == 0x184) {
      return;
    }
  }
switchD_107122bd_caseD_2:
  operand_pair_constraints(t,opnd,s,opnd2,out_00);
switchD_107125da_caseD_145:
  return;
}

