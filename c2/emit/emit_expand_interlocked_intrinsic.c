void __fastcall emit_expand_interlocked_intrinsic(c2_tuple *intrin)

{
  uint16_t uVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_fe_symbol *pcVar7;
  c2_const_operand *src2;
  c2_tuple *t;
  c2_operand *pcVar8;
  bool bVar9;
  code *pcVar10;
  c2_tuple *local_8;
  c2_tuple *local_4;
  c2_insert_fn *insert_fn;
  
  pcVar3 = intrin->src;
  local_8 = intrin;
  switch((pcVar3->u18).lo) {
  case 0x11b:
  case 0x11c:
    pcVar3 = pcVar3->next;
    pcVar6 = pcVar3->next;
    pcVar5 = intrin;
    if (g_opt_nolock == 0) {
      pcVar5 = tuple_new_nooperands(0xb6,0x1004,tuple_insert_after,intrin);
    }
    if (g_opt_global == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = tuple_get_memeffect_alias(intrin);
    }
    pcVar4 = operand_new_mem(0x14c,0x1004,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,uVar2);
    pcVar10 = tuple_insert_after;
    pcVar4->flags = pcVar4->flags | 0x40;
    pcVar3 = pcVar6;
    pcVar8 = (c2_operand *)node_clone((c2_node *)pcVar4);
    pcVar5 = tuple_new_binary(0xd9,0x1004,pcVar4,pcVar8,pcVar3,pcVar10,pcVar5);
    tuple_append_dst(pcVar5,pcVar6);
    pcVar3 = intrin->dst;
    if (((pcVar3 != (c2_operand *)0x0) && (pcVar3->kind == '\x01')) &&
       (pcVar5 = tuple_new((-(uint)((intrin->src->u18).reg != (c2_symbol *)0x11b) & 0xfffffffd) +
                           0x21,0x1004,pcVar6,pcVar6,tuple_insert_after,pcVar5),
       (pcVar6->u18).reg != (pcVar3->u18).reg)) {
      tuple_new(1,0x1004,pcVar3,pcVar6,tuple_insert_after,pcVar5);
      return;
    }
    break;
  case 0x11d:
    pcVar3 = pcVar3->next;
    pcVar6 = pcVar3->next;
    uVar1 = pcVar6->type;
    if (g_opt_global == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = tuple_get_memeffect_alias(intrin);
    }
    pcVar3 = operand_new_mem(0x14c,uVar1,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,uVar2);
    pcVar10 = tuple_insert_after;
    bVar9 = g_opt_nolock == 0;
    pcVar3->flags = pcVar3->flags | 0x40;
    if (bVar9) {
      pcVar4 = pcVar6;
      pcVar5 = intrin;
      pcVar8 = (c2_operand *)node_clone((c2_node *)pcVar3);
      pcVar5 = tuple_new_binary(9,uVar1,pcVar3,pcVar8,pcVar4,pcVar10,pcVar5);
      tuple_append_dst(pcVar5,pcVar6);
      pcVar3 = intrin->dst;
      if (pcVar3 == (c2_operand *)0x0) {
        return;
      }
      if (pcVar3->kind != '\x01') {
        return;
      }
      if ((pcVar6->u18).reg == (pcVar3->u18).reg) {
        return;
      }
      pcVar10 = tuple_insert_after;
    }
    else {
      pcVar4 = pcVar3;
      pcVar5 = intrin;
      pcVar8 = operand_new_reg(0x149,uVar1,g_reg_symbols + 1,g_reg_symbols + 1);
      pcVar5 = tuple_new(1,uVar1,pcVar8,pcVar4,pcVar10,pcVar5);
      pcVar7 = label_symbol_new();
      t = tuple_new_label(pcVar7);
      tuple_insert_after(pcVar5,t);
      pcVar10 = tuple_insert_after;
      pcVar5 = t;
      pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar3);
      pcVar5 = tuple_new_binary(0xda,uVar1,pcVar3,pcVar4,pcVar6,pcVar10,pcVar5);
      pcVar3 = operand_new_reg(0x149,uVar1,g_reg_symbols + 1,g_reg_symbols + 1);
      tuple_append_dst(pcVar5,pcVar3);
      pcVar3 = operand_new_temp(0x8000);
      (pcVar3->u18).reg = g_reg_symbols + 0x42;
      tuple_append_dst(pcVar5,pcVar3);
      pcVar3->sym->def = pcVar5;
      pcVar5 = tuple_new_branch(0xf,'\x02',(c2_node *)t,pcVar3,pcVar5,tuple_insert_after,pcVar5);
      pcVar3 = intrin->dst;
      if (pcVar3 == (c2_operand *)0x0) {
        return;
      }
      if (pcVar3->kind != '\x01') {
        return;
      }
      if ((pcVar3->u18).reg == g_reg_symbols + 1) {
        return;
      }
      pcVar10 = tuple_insert_after;
      pcVar6 = operand_new_reg(0x149,uVar1,g_reg_symbols + 1,g_reg_symbols + 1);
    }
    tuple_new(1,uVar1,pcVar3,pcVar6,pcVar10,pcVar5);
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\cgintrin.c",0xaf9);
  case 0x13e:
    if (g_opt_nolock == 0) {
      local_8 = tuple_new_nooperands(0xb6,0x1004,tuple_insert_after,intrin);
    }
    pcVar3 = intrin->src->next;
    pcVar6 = pcVar3->next;
    uVar1 = pcVar6->type;
    if (g_opt_global == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = tuple_get_memeffect_alias(intrin);
    }
    pcVar4 = operand_new_mem(0x14c,uVar1,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,uVar2);
    pcVar10 = tuple_insert_after;
    pcVar4->flags = pcVar4->flags | 0x40;
    pcVar3 = pcVar6;
    pcVar8 = (c2_operand *)node_clone((c2_node *)pcVar4);
    pcVar5 = tuple_new_binary(0xd9,uVar1,pcVar4,pcVar8,pcVar3,pcVar10,local_8);
    tuple_append_dst(pcVar5,pcVar6);
    pcVar3 = intrin->dst;
    if (((pcVar3 != (c2_operand *)0x0) && (pcVar3->kind == '\x01')) &&
       ((pcVar6->u18).reg != (pcVar3->u18).reg)) {
      tuple_new(1,uVar1,pcVar3,pcVar6,tuple_insert_after,pcVar5);
      return;
    }
    break;
  case 0x13f:
    if (g_opt_nolock == 0) {
      local_8 = tuple_new_nooperands(0xb6,0x1004,tuple_insert_after,intrin);
    }
    pcVar3 = intrin->src->next;
    pcVar6 = pcVar3->next;
    uVar1 = pcVar6->type;
    if (g_opt_global == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = tuple_get_memeffect_alias(intrin);
    }
    pcVar3 = operand_new_mem(0x14c,uVar1,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,uVar2);
    pcVar3->flags = pcVar3->flags | 0x40;
    insert_fn = tuple_insert_after;
    pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar3);
    pcVar5 = tuple_new_binary(0xda,uVar1,pcVar3,pcVar4,pcVar6,insert_fn,local_8);
    pcVar3 = operand_new_reg(0x149,uVar1,g_reg_symbols + 1,g_reg_symbols + 1);
    tuple_append_dst(pcVar5,pcVar3);
    pcVar3 = intrin->dst;
    if (((pcVar3 != (c2_operand *)0x0) && (pcVar3->kind == '\x01')) &&
       ((pcVar3->u18).reg != g_reg_symbols + 1)) {
      insert_fn = tuple_insert_after;
      pcVar6 = operand_new_reg(0x149,uVar1,g_reg_symbols + 1,g_reg_symbols + 1);
      tuple_new(1,uVar1,pcVar3,pcVar6,insert_fn,pcVar5);
      return;
    }
    break;
  case 0x14b:
    pcVar3 = pcVar3->next;
    pcVar6 = pcVar3->next;
    uVar1 = pcVar6->type;
    if (g_opt_global == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = tuple_get_memeffect_alias(intrin);
    }
    pcVar3 = operand_new_mem(0x14c,uVar1,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,uVar2);
    bVar9 = g_opt_nolock == 0;
    pcVar3->flags = pcVar3->flags | 0x40;
    if (bVar9) {
      intrin = tuple_new_nooperands(0xb6,0x1004,tuple_insert_after,intrin);
    }
    insert_fn = tuple_insert_after;
    pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar3);
    pcVar5 = tuple_new_binary(0x2d,uVar1,pcVar3,pcVar4,pcVar6,insert_fn,intrin);
    if (g_opt_nolock == 0) {
      pcVar6 = operand_new_temp(0x8000);
      (pcVar6->u18).reg = g_reg_symbols + 0x42;
      tuple_append_dst(pcVar5,pcVar6);
      pcVar6->sym->def = pcVar5;
      pcVar7 = label_symbol_new();
      local_4 = tuple_new_label(pcVar7);
      pcVar5 = tuple_new_branch(0xf,'\n',(c2_node *)local_4,pcVar6,pcVar5,tuple_insert_after,pcVar5)
      ;
      pcVar5 = tuple_new_nooperands(0xb6,0x1004,tuple_insert_after,pcVar5);
    }
    pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar3);
    insert_fn = tuple_insert_after;
    pcVar3->disp = 4;
    src2 = operand_new_intconst(uVar1,0,0);
    pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar3);
    pcVar5 = tuple_new_binary(0x2c,uVar1,pcVar3,pcVar6,src2,insert_fn,pcVar5);
    if (g_opt_nolock == 0) {
      tuple_insert_after(pcVar5,local_4);
      return;
    }
  }
  return;
}

