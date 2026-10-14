void __fastcall lower_float_compare_to_int(c2_tuple *t,uint16_t type)

{
  ushort uVar1;
  c2_tuple *t_00;
  c2_operand *pcVar2;
  uint32_t uVar3;
  c2_operand_u18 cVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_const_operand *pcVar7;
  c2_tuple *pcVar8;
  int iVar9;
  c2_tuple *pcVar10;
  uint16_t uVar11;
  ushort uVar12;
  uint lo;
  code *insert_fn_00;
  c2_tuple *anchor;
  c2_tuple *local_8;
  c2_operand *local_4;
  c2_insert_fn *insert_fn;
  
  uVar11 = (t->u20).intrinsic.id;
  pcVar6 = t->src->next;
  lo = type & 0xfff;
  local_8 = t->src->sym->def;
  pcVar8 = pcVar6->sym->def;
  t_00 = pcVar6->next->sym->def;
  local_4 = (c2_operand *)(type & 0xf000);
  if ((((short)local_4 == 0x4000) && (uVar11 == 0x97)) &&
     (pcVar2 = pcVar8->src, pcVar2->kind == '\t')) {
    if (lo != 4) {
      if (lo != 8) goto LAB_10761bb6;
      iVar9 = float_const_compare_mask(1,(c2_float_const *)pcVar2->sym,&g_ld_const_zero);
      if (iVar9 != 0) {
        lo = 4;
        pcVar7 = operand_new_intconst(0x1004,0,0);
        tuple_replace_src(pcVar8,pcVar8->src,pcVar7);
        operand_set_type(pcVar8->dst,0x1004);
        pcVar8->type = 0x1004;
        operand_set_type(pcVar6,0x1004);
        pcVar8->dst->u18 = (c2_operand_u18)pcVar8->dst->sym;
        pcVar6->u18 = (c2_operand_u18)pcVar6->sym;
        goto LAB_10761bcf;
      }
LAB_1077fad1:
      pcVar6 = local_8->src;
      if (((pcVar6->kind == '\x01') && (pcVar6->sym->cls == '\x03')) &&
         (pcVar10 = pcVar6->sym->def, pcVar10 != (c2_tuple *)0x0)) {
        cse_unlink_def(pcVar10);
      }
      pcVar6 = operand_at_offset_2(pcVar6,type,0,(int)t->dst->sym);
      insert_fn = tuple_insert_before;
      if ((short)local_4 == 0x5000) {
        pcVar10 = t;
        pcVar7 = operand_new_intconst(0x1004,type & 0xfff,0);
        tuple_new_blockop(0x16b,type,pcVar6,pcVar8->src,pcVar7,insert_fn,pcVar10);
      }
      else {
        tuple_new(0x15b,type,pcVar6,pcVar8->src,tuple_insert_before,t);
      }
      pcVar10 = local_8;
      insert_fn = tuple_insert_before;
      anchor = local_8;
      pcVar7 = operand_new_intconst(0x1004,lo,0);
      local_4 = (c2_operand *)
                tuple_new_binary_temp(0x16d,0x1004,pcVar10->src,pcVar7,insert_fn,anchor);
      tuple_replace_src(pcVar8,pcVar8->src,pcVar10->src);
      pcVar8->type = 0x1004;
      operand_set_type(pcVar8->dst,0x1004);
      tuple_replace_src(pcVar10,pcVar10->src,(c2_operand *)local_4->tag);
      pcVar6 = t->src->next;
      operand_set_type(pcVar6,0x1004);
      pcVar2 = pcVar8->dst;
      pcVar6->u18 = (c2_operand_u18)pcVar6->sym;
      uVar3 = pcVar8->op;
      pcVar2->u18 = (c2_operand_u18)pcVar2->sym;
      if (uVar3 == 0x16a) {
        pcVar8 = tuple_new(0x15a,pcVar8->type,pcVar2,pcVar8->src,tuple_insert_after,pcVar8);
        if ((pcVar8->dst->kind == '\x01') &&
           (pcVar5 = pcVar8->dst->sym, pcVar5->def != (c2_tuple *)0x0)) {
          pcVar5->def = pcVar8;
        }
        tuple_unlink_free(pcVar8->prev);
      }
      tuple_append_src(t,t->dst);
      (t->u20).intrinsic.id = 0x96;
      local_4 = (c2_operand *)0x96;
      insert_fn_00 = tuple_insert_before;
      pcVar10 = t_00;
      pcVar7 = operand_new_intconst(0x1004,lo,0);
      pcVar10 = tuple_new_binary_temp(0x16e,t_00->type,t_00->src,pcVar7,insert_fn_00,pcVar10);
      tuple_replace_src(t_00,t_00->src,pcVar10->dst);
      uVar11 = (uint16_t)local_4;
      goto LAB_1077fc70;
    }
    fpu_store_float((c2_float_const *)pcVar2->sym,(float *)&local_8);
    pcVar7 = operand_new_intconst(0x1004,(uint32_t)local_8,(int)local_8 >> 0x1f);
    tuple_replace_src(pcVar8,pcVar8->src,pcVar7);
    operand_set_type(pcVar8->dst,0x1004);
    pcVar6 = t->src;
    pcVar8->type = 0x1004;
    pcVar6 = pcVar6->next;
    operand_set_type(pcVar6,0x1004);
    pcVar2 = pcVar8->dst;
    pcVar6->u18 = (c2_operand_u18)pcVar6->sym;
    pcVar2->u18 = (c2_operand_u18)pcVar2->sym;
LAB_10761bcf:
    uVar1 = pcVar8->type;
    uVar12 = (ushort)lo;
    if ((((1 << (byte)(uVar1 >> 0xc) & 0xeU) == 0) ||
        (((uVar1 & 0xf000) == 0x1000 && ((uVar12 | 0x1000) != uVar1)))) ||
       (((uVar1 & 0xf000) == 0x2000 && ((uVar12 | 0x2000) != uVar1)))) {
      pcVar6 = pcVar8->src;
      if (((pcVar6->kind == '\x01') && (pcVar6->sym->cls == '\x03')) &&
         (pcVar10 = pcVar6->sym->def, pcVar10 != (c2_tuple *)0x0)) {
        cse_unlink_def(pcVar10);
      }
      operand_set_type(pcVar6,0x1004);
      uVar12 = uVar12 | 0x1000;
      pcVar8->type = uVar12;
      operand_set_type(pcVar8->dst,uVar12);
      local_4 = t->src->next;
      operand_set_type(local_4,uVar12);
      cVar4 = (c2_operand_u18)local_4->sym;
      pcVar8->dst->u18 = (c2_operand_u18)pcVar8->dst->sym;
      local_4->u18 = cVar4;
    }
  }
  else {
LAB_10761bb6:
    if ((lo == 3) || (4 < lo)) {
      if (uVar11 == 0x97) {
        if (lo == 3) {
          (t->u24).intrinsic_flag = 1;
        }
        goto LAB_1077fad1;
      }
LAB_1077fc70:
      if ((type & 3) == 0) {
        lo = 4;
      }
      else {
        lo = 2 - ((type & 1) != 0);
      }
    }
    if (uVar11 == 0x97) goto LAB_10761bcf;
  }
  if ((int)lo < 2) goto LAB_10761c9a;
  if ((((int)lo < 1) || ((lo & lo - 1) != 0)) ||
     ((((1 << (t_00->src->kind & 0x1f) & 6U) == 0 ||
       ((pcVar8 = t_00->src->sym->def, pcVar8 == (c2_tuple *)0x0 || (pcVar8->op != 0x171)))) ||
      (pcVar6 = pcVar8->src->next, pcVar6->kind != '\a')))) {
LAB_10761cb9:
    insert_fn = tuple_insert_before;
    pcVar8 = t_00;
    pcVar7 = operand_new_intconst(0x1004,lo,(int)lo >> 0x1f);
    pcVar8 = tuple_new_binary_temp(0x175,t_00->type,t_00->src,pcVar7,insert_fn,pcVar8);
    pcVar6 = pcVar8->dst;
  }
  else {
    pcVar5 = (c2_symbol *)log2_floor(lo);
    if (((pcVar6->u18).reg != pcVar5) || (pcVar6->tag != (int)pcVar5 >> 0x1f)) goto LAB_10761cb9;
    pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar8->src);
    tuple_unlink_free(pcVar8);
  }
  tuple_replace_src(t_00,t_00->src,pcVar6);
LAB_10761c9a:
  (t->u20).intrinsic.arg = (uint16_t)lo;
  return;
}

