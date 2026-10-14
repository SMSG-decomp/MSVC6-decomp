c2_operand * __fastcall
make_byte_lane_operand
          (c2_operand *opnd,c2_operand *lane_operand,uint16_t type,int emit_copy,
          char reject_converted)

{
  c2_operand *pcVar1;
  int iVar2;
  c2_operand *pcVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  c2_tuple *t;
  int src_lane;
  c2_tuple *local_10;
  int local_c;
  c2_operand *local_8;
  c2_tuple *local_4;
  
  pcVar1 = strip_widening_converts(opnd,1);
  if ((((1 << (pcVar1->kind & 0x1f) & 6U) == 0) || (pcVar1->sym->def == (c2_tuple *)0x0)) ||
     ((reject_converted != '\0' && (pcVar1 != opnd)))) {
    pcVar1 = build_byte_lane_copy(lane_operand,type,opnd->sym->def,0,0,emit_copy & 1);
    return pcVar1;
  }
  local_8 = strip_widening_converts(opnd,3);
  t = local_8->sym->def;
  pcVar1 = t->src;
  uVar5 = t->op;
  pcVar3 = pcVar1->next;
  local_10 = t;
  if (((uVar5 == 0x172) && (iVar2 = operand_is_const_value(pcVar3,0xff00), iVar2 != 0)) &&
     ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) {
    local_4 = pcVar1->sym->def;
    if (((local_4 == (c2_tuple *)0x0) || (pcVar1->sym->def->op != 0x171)) ||
       (iVar2 = operand_is_const_value(local_4->src->next,8), iVar2 == 0)) goto LAB_1075a348;
    local_10 = local_4;
  }
  else {
LAB_1075a348:
    if (uVar5 != 0x171) {
LAB_1075a354:
      iVar2 = classify_masked_shift_source(local_8,&local_c,&local_10);
      if (iVar2 == 0) {
        puVar4 = get_byte_masked_source(local_8);
        if (puVar4 == (uint32_t *)0x0) {
          if (t->op != 0x177) {
            if (t->op != 0x172) {
              return lane_operand;
            }
            src_lane = 1;
            iVar2 = 1;
            goto LAB_107759c7;
          }
        }
        else {
          t = local_10;
          if (local_10->op != 0x177) {
            src_lane = 0;
            iVar2 = 0;
LAB_107759c7:
            pcVar1 = build_byte_lane_copy(lane_operand,type,local_10,iVar2,src_lane,emit_copy & 1);
            return pcVar1;
          }
        }
        uVar5 = classify_byte_lane_shift(t,&local_c,&local_10);
        iVar2 = (int)(uVar5 << 0x10) >> 0x18;
      }
      iVar2 = iVar2 + 1 >> 1;
      goto LAB_1075a384;
    }
    iVar2 = operand_is_const_value(pcVar3,8);
    if (iVar2 == 0) {
      iVar2 = operand_is_const_value(pcVar3,8);
      if ((iVar2 == 0) || ((t->type & 0xfff) != 2)) goto LAB_1075a354;
    }
    else if ((t->type & 0xfff) != 2) {
      pcVar3 = strip_widening_converts(pcVar1,0);
      puVar4 = get_byte_masked_source(pcVar3);
      if (puVar4 == (uint32_t *)0x0) {
        return lane_operand;
      }
      local_10 = pcVar1->sym->def;
    }
  }
  local_c = 0;
  iVar2 = 1;
LAB_1075a384:
  pcVar1 = build_byte_lane_copy(lane_operand,type,local_10,iVar2,local_c,emit_copy & 1);
  if (local_10 == t) {
    return pcVar1;
  }
  tuple_unlink_free(t);
  return pcVar1;
}

