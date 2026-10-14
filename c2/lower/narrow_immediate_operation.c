int __fastcall narrow_immediate_operation(c2_tuple *t,uint32_t *size,uint32_t *offset)

{
  uint8_t uVar1;
  uint uVar2;
  c2_operand *pcVar3;
  uint uVar4;
  byte bVar5;
  c2_byte_lane_mask *pcVar6;
  c2_tuple *t_00;
  uint32_t uVar7;
  int iVar8;
  uint32_t *puVar9;
  uint32_t *kind;
  c2_operand *local_4;
  
  uVar2 = *size;
  if (((t->type & 0xfff) != uVar2) &&
     (((uVar2 != 0 || ((t->type & 0xfff) != 1)) && (t->src->next->kind == '\a')))) {
    if (t->op == 0x33) {
      t_00 = find_next_use_of_dst(t,&local_4);
      bVar5 = x86_fixed_reg_class(t_00);
      if (bVar5 == 0) {
        return 0;
      }
      if (2 < bVar5) {
        return 0;
      }
    }
    else {
      local_4 = find_dst_clobbering_reg(t,g_reg_symbols + 0x42);
      if (((1 << (local_4->kind & 0x1f) & 6U) != 0) && (local_4->sym->def != (c2_tuple *)0x0)) {
        return 0;
      }
    }
    pcVar3 = t->src;
    kind = (uint32_t *)0x0;
    uVar4 = (pcVar3->next->u18).lo;
    puVar9 = offset;
    if ((uVar2 == 1) || (uVar2 == 0)) {
      iVar8 = 0;
      pcVar6 = g_byte_lane_mask_table;
      do {
        if (t->op == 0x2e) {
          uVar7 = pcVar6->clear_mask;
        }
        else {
          uVar7 = 0;
        }
        if ((pcVar6->clear_mask & uVar4) == uVar7) {
          kind = (uint32_t *)0x1;
          puVar9 = (uint32_t *)g_byte_lane_mask_table[iVar8].byte_offset;
          break;
        }
        pcVar6 = pcVar6 + 1;
        iVar8 = iVar8 + 1;
      } while ((int)pcVar6 < 0x107ac1d8);
    }
    if ((((*size == 2) || (*size == 0)) && (kind == (uint32_t *)0x0)) && (g_opt_favor_speed == 0)) {
      if ((uVar4 & 0xffff0000) == ((t->op != 0x2e) - 1 & 0xffff0000)) {
        puVar9 = (uint32_t *)0x0;
        kind = (uint32_t *)0x2;
      }
      else if ((uVar4 & 0xffff) == ((t->op != 0x2e) - 1 & 0xffff)) {
        puVar9 = (uint32_t *)0x2;
        kind = puVar9;
      }
    }
    uVar1 = pcVar3->kind;
    if ((uVar1 == '\x01') && ((int)(pcVar3->type & 0xfff) < (int)*size)) {
      puVar9 = (uint32_t *)0x0;
      kind = (uint32_t *)*size;
    }
    if (((kind != (uint32_t *)0x0) &&
        ((uVar1 != '\x01' ||
         (iVar8 = substitution_allowed((pcVar3->u18).reg,(int)kind,(int)puVar9), iVar8 != 0)))) &&
       ((uVar7 = *size, uVar7 != 0 ||
        ((((kind != (uint32_t *)0x1 || ((t->type & 0xfff) != 4)) || (puVar9 != (uint32_t *)0x0)) ||
         ((uVar4 != (int)(char)uVar4 ||
          ((uVar1 == '\x01' && ((pcVar3->u18).reg == g_reg_symbols + 1)))))))))) {
      *offset = (uint32_t)puVar9;
      if (uVar7 == 0) {
        *size = (uint32_t)kind;
      }
      return (uint)(kind == (uint32_t *)*size);
    }
  }
  return 0;
}

