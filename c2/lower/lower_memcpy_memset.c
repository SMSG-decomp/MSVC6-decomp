void __fastcall lower_memcpy_memset(c2_tuple *t,c2_operand **args,uint elem_size,int is_fill)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  c2_operand *dst;
  c2_operand *pcVar5;
  uint uVar6;
  uint size_code;
  longlong lVar7;
  c2_operand *local_14;
  uint32_t local_10;
  uint local_c;
  
  size_code = elem_size;
  pcVar1 = args[2];
  local_14 = (c2_operand *)0x0;
  local_c = 0;
  dst = pcVar1->sym->def->src;
  if (dst->kind == '\a') {
    local_10 = (dst->u18).lo;
    if (local_10 == 0) {
      lower_memcpy_operand_add_reg_use(args[1]);
      lower_memcpy_operand_add_reg_use(pcVar1);
      pcVar2 = (*args)->sym->def;
      pcVar1 = t->dst;
      if ((pcVar1 == (c2_operand *)0x0) || (pcVar1->kind == '\v')) {
        lower_memcpy_operand_add_reg_use(*args);
        return;
      }
      pcVar2->op = 1;
      tuple_replace_dst(pcVar2,pcVar2->dst,pcVar1);
      if ((1 << (pcVar2->dst->kind & 0x1f) & 6U) == 0) {
        return;
      }
      pcVar3 = pcVar2->dst->sym;
      if (pcVar3->def == (c2_tuple *)0x0) {
        return;
      }
      pcVar3->def = pcVar2;
      return;
    }
  }
  else {
    local_10 = 0;
  }
  pcVar1 = *args;
  if ((is_fill == 0) || (elem_size != 1)) {
    if (elem_size != 4) goto LAB_107653ec;
  }
  else {
    pcVar4 = args[1];
    pcVar2 = pcVar4->sym->def;
    if ((pcVar2->type & 0xfff) != 1) {
      set_op_width(pcVar2,1);
    }
    operand_retype(pcVar4,0x1001,0);
LAB_107653ec:
    if ((t->u24).intrinsic_flag == 0) {
      if (dst->op == 0x146) {
        uVar6 = (uint)(local_10 != 0);
        lVar7 = allshr((dst->u18).lo,dst->tag,(byte)size_code ^ 3);
        dst->u18 = (c2_operand_u18)(int)lVar7;
        dst->tag = (int)((ulonglong)lVar7 >> 0x20);
        elem_size = (uint)args[2];
        goto LAB_10765479;
      }
      uVar6 = 1 << (dst->kind & 0x1f) & 6;
      if ((((uVar6 == 0) || (pcVar2 = dst->sym->def, pcVar2 == (c2_tuple *)0x0)) ||
          (pcVar2->op != 1)) ||
         (((((1 << (pcVar2->src->kind & 0x1f) & 6U) == 0 ||
            (pcVar2 = pcVar2->src->sym->def, pcVar2 == (c2_tuple *)0x0)) ||
           ((pcVar2->op != 0x12 ||
            ((pcVar4 = pcVar2->src, pcVar4->op != 0x14f ||
             ((pcVar4->flags & 0xf) != 4 >> ((byte)size_code & 0x1f))))))) || (pcVar4->disp != 0))))
      {
        if ((((uVar6 == 0) || (pcVar2 = dst->sym->def, pcVar2 == (c2_tuple *)0x0)) ||
            (pcVar2->op != 0x2e)) ||
           ((pcVar4 = pcVar2->src->next, pcVar4->kind != '\a' || ((*(byte *)&pcVar4->u18 & 3) != 0))
           )) {
          elem_size = (uint)lower_arg_push_value(t,args[2]);
          if (size_code == 1) {
            dst = operand_new_temp(0x1004);
            build_fill_pattern(1,0x1004,dst,(c2_operand **)&elem_size,t->prev);
          }
          uVar6 = 1;
          goto LAB_10765479;
        }
        local_c = size_code ^ 3;
        local_14 = (c2_operand *)0x1;
        size_code = 4;
      }
      else {
        pcVar5 = pcVar4->index;
        local_14 = (c2_operand *)0x1;
        pcVar2->op = 1;
        size_code = 4;
        pcVar5 = operand_new_reg(0x149,pcVar5->type,pcVar5->sym,(pcVar5->u18).reg);
        tuple_replace_src(pcVar2,pcVar4,pcVar5);
      }
    }
  }
  elem_size = (uint)args[2];
  uVar6 = 0;
LAB_10765479:
  emit_string_block_op
            (local_10,(c2_operand *)elem_size,dst,pcVar1,args[1],uVar6,local_14,size_code,is_fill,1,
             1,t,local_c);
  return;
}

